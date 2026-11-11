#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
REPOSITORY="$(cd "$ROOT/.." && pwd)"
BASELINE_COMMIT="c86c93a"
REPETITIONS="${BENCHMARK_REPETITIONS:-100}"
RESULTS="$ROOT/Benchmarks/results"
TEMP="$(mktemp -d)"
trap 'rm -rf "$TEMP"' EXIT

mkdir -p "$RESULTS"
ORIGINAL_ROOT="$TEMP/original"
mkdir -p "$ORIGINAL_ROOT"

git -C "$REPOSITORY" archive --format=tar "$BASELINE_COMMIT" -- Meandering-rivers/Code \
	| tar -xf - -C "$TEMP"

SOURCE_FILES=(
	Code/Source/cubic-curve-set.cpp
	Code/Source/cubic-curve.cpp
	Code/Source/cubic.cpp
	Code/Source/linear.cpp
	Code/Source/meanders-channel.cpp
	Code/Source/meanders-simulation.cpp
	Code/Source/quadric.cpp
)

MODIFIED_SOURCES=()
ORIGINAL_SOURCES=()
for source in "${SOURCE_FILES[@]}"; do
	MODIFIED_SOURCES+=("$ROOT/$source")
	ORIGINAL_SOURCES+=("$ORIGINAL_ROOT/Meandering-rivers/$source")
done

g++ -std=c++17 -O2 \
	-I"$ROOT/Code/Include" -I"$ROOT/Benchmarks" \
	"$ROOT/Benchmarks/benchmark_modificado.cpp" "${MODIFIED_SOURCES[@]}" \
	-o "$TEMP/benchmark_modificado"

g++ -std=c++17 -O2 \
	-I"$ORIGINAL_ROOT/Meandering-rivers/Code/Include" -I"$ROOT/Benchmarks" \
	"$ROOT/Benchmarks/benchmark_original.cpp" "${ORIGINAL_SOURCES[@]}" \
	-o "$TEMP/benchmark_original"

RAW="$RESULTS/benchmark_raw.csv"
ENVIRONMENT="$RESULTS/benchmark_environment.txt"
printf '%s\n' "benchmark_version,1" > "$ENVIRONMENT"
printf '%s\n' "baseline_commit,$BASELINE_COMMIT" >> "$ENVIRONMENT"
printf '%s\n' "modified_commit,$(git -C "$REPOSITORY" rev-parse HEAD)" >> "$ENVIRONMENT"
printf '%s\n' "repetitions,$REPETITIONS" >> "$ENVIRONMENT"
printf '%s\n' "compiler,$(g++ --version | head -n 1)" >> "$ENVIRONMENT"
printf '%s\n' "flags,-std=c++17 -O2" >> "$ENVIRONMENT"
printf '%s\n' "system,$(uname -srmo)" >> "$ENVIRONMENT"

"$TEMP/benchmark_original" plano_500 "$REPETITIONS" > "$TEMP/original.csv"
tail -n +2 "$TEMP/original.csv" > "$RAW"
for scenario in terreno_1200 avulsao_750 litologia_500; do
	"$TEMP/benchmark_original" "$scenario" "$REPETITIONS" > "$TEMP/original.csv"
	tail -n +2 "$TEMP/original.csv" >> "$RAW"
done

for variant in modificado_neutro modificado_litologico; do
	for scenario in plano_500 terreno_1200 avulsao_750 litologia_500; do
		"$TEMP/benchmark_modificado" "$variant" "$scenario" "$REPETITIONS" > "$TEMP/modified.csv"
		tail -n +2 "$TEMP/modified.csv" >> "$RAW"
	done
done

python3 "$ROOT/Benchmarks/aggregate_results.py" \
	"$RAW" \
	"$RESULTS/benchmark_summary.csv" \
	"$RESULTS/RELATORIO_BENCHMARK.md" \
	"$ENVIRONMENT"

echo "Benchmark concluído: $RAW"
