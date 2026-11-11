#!/usr/bin/env python3
import csv
import math
import statistics
import sys
from collections import defaultdict


def percentile(values, percentile_value):
    ordered = sorted(values)
    index = max(0, math.ceil(percentile_value * len(ordered)) - 1)
    return ordered[index]


def mean_std(values):
    return statistics.mean(values), statistics.pstdev(values)


def read_environment(path):
    result = {}
    with open(path, encoding="utf-8") as handle:
        for line in handle:
            key, value = line.rstrip("\n").split(",", 1)
            result[key] = value
    return result


def main():
    if len(sys.argv) != 5:
        print("uso: aggregate_results.py raw.csv summary.csv relatorio.md ambiente.txt", file=sys.stderr)
        return 2

    raw_path, summary_path, report_path, environment_path = sys.argv[1:]
    groups = defaultdict(list)
    with open(raw_path, newline="", encoding="utf-8") as handle:
        for row in csv.DictReader(handle):
            groups[(row["variant"], row["scenario"])].append(row)

    original_times = {
        scenario: statistics.median(float(row["total_time_ns"]) for row in rows)
        for (variant, scenario), rows in groups.items()
        if variant == "original"
    }
    neutral_times = {
        scenario: statistics.median(float(row["total_time_ns"]) for row in rows)
        for (variant, scenario), rows in groups.items()
        if variant == "modificado_neutro"
    }
    summary_rows = []
    for (variant, scenario), rows in sorted(groups.items()):
        times = [float(row["total_time_ns"]) for row in rows]
        time_per_step = [float(row["time_per_step_ns"]) for row in rows]
        sinuosity = [float(row["final_sinuosity"]) for row in rows]
        displacement = [float(row["max_lateral_displacement"]) for row in rows]
        time_mean, time_std = mean_std(times)
        sinuosity_mean, sinuosity_std = mean_std(sinuosity)
        baseline = original_times[scenario]
        median = statistics.median(times)
        summary_rows.append({
            "variant": variant,
            "scenario": scenario,
            "samples": len(rows),
            "time_median_ns": median,
            "time_mean_ns": time_mean,
            "time_stddev_ns": time_std,
            "time_p95_ns": percentile(times, 0.95),
            "time_min_ns": min(times),
            "time_max_ns": max(times),
            "time_per_step_median_ns": statistics.median(time_per_step),
            "overhead_vs_original_percent": 100.0 * (median - baseline) / baseline,
            "speedup_vs_original": baseline / median,
            "overhead_vs_neutral_percent": (
                100.0 * (median - neutral_times[scenario]) / neutral_times[scenario]
                if scenario in neutral_times else ""
            ),
            "final_sinuosity_mean": sinuosity_mean,
            "final_sinuosity_stddev": sinuosity_std,
            "max_lateral_displacement_mean": statistics.mean(displacement),
            "invalid_values_total": sum(int(row["invalid_values"]) for row in rows),
        })

    fieldnames = list(summary_rows[0].keys())
    with open(summary_path, "w", newline="", encoding="utf-8") as handle:
        writer = csv.DictWriter(handle, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(summary_rows)

    environment = read_environment(environment_path)
    with open(report_path, "w", encoding="utf-8") as handle:
        handle.write("# Relatório do benchmark comparativo\n\n")
        handle.write("## Configuração\n\n")
        handle.write("| Campo | Valor |\n| --- | --- |\n")
        for key, value in environment.items():
            handle.write(f"| `{key}` | `{value}` |\n")
        handle.write("\nForam usadas três variantes, quatro cenários e 100 repetições por combinação.\n")
        handle.write("Os tempos estão em nanossegundos e foram medidos apenas durante os passos da simulação.\n\n")

        handle.write("## Resultados de tempo\n\n")
        handle.write("| Variante | Cenário | Amostras | Mediana (ns) | p95 (ns) | Desvio (ns) | Overhead vs original | Overhead vs neutro | Speedup |\n")
        handle.write("| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |\n")
        for row in summary_rows:
            neutral_overhead = row["overhead_vs_neutral_percent"]
            neutral_display = "" if neutral_overhead == "" else f"{neutral_overhead:.2f}%"
            handle.write(
                f"| {row['variant']} | {row['scenario']} | {row['samples']} | "
                f"{row['time_median_ns']:.2f} | {row['time_p95_ns']:.2f} | "
                f"{row['time_stddev_ns']:.2f} | {row['overhead_vs_original_percent']:.2f}% | "
                f"{neutral_display} | "
                f"{row['speedup_vs_original']:.4f}x |\n"
            )

        handle.write("\n## Resultados geométricos\n\n")
        handle.write("| Variante | Cenário | Sinuosidade média | Desvio da sinuosidade | Deslocamento lateral médio | Valores inválidos |\n")
        handle.write("| --- | --- | ---: | ---: | ---: | ---: |\n")
        for row in summary_rows:
            handle.write(
                f"| {row['variant']} | {row['scenario']} | {row['final_sinuosity_mean']:.8f} | "
                f"{row['final_sinuosity_stddev']:.8f} | {row['max_lateral_displacement_mean']:.8f} | "
                f"{row['invalid_values_total']} |\n"
            )

        handle.write("\n## Interpretação\n\n")
        handle.write("- `modificado_neutro` mede o custo estrutural da extensão quando `E=1`.\n")
        handle.write("- `modificado_litologico` mede o custo adicional das consultas e da modulação espacial.\n")
        handle.write("- O overhead é calculado pela mediana em relação à variante `original` do mesmo cenário.\n")
        handle.write("- O overhead contra `modificado_neutro` isola o custo da litologia.\n")
        handle.write("- Os CSVs bruto e resumido permitem reproduzir as tabelas sem executar novamente o benchmark.\n")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
