# Benchmark comparativo

Este pacote compara a baseline original do artigo com a implementação da
equipe de Warley Ramires, Alberto Henrique e Pedro Henrique Braga.

## Variantes

- `original`: código importado no commit `c86c93a`.
- `modificado_neutro`: código atual com campo litológico uniforme `E=1`.
- `modificado_litologico`: código atual com campo heterogêneo contendo zonas
  resistentes (`E=0.25`) e erodíveis (`E=1.75`).

## Cenários

- `plano_500`: terreno plano e 500 passos.
- `terreno_1200`: relevo sintético e 1200 passos.
- `avulsao_750`: 700 passos, duas avulsões e mais 50 passos.
- `litologia_500`: terreno plano, campo litológico heterogêneo e 500 passos.

Cada cenário/variante possui 100 repetições. As sementes `1234`, `4321` e
`9999` são distribuídas ciclicamente entre as repetições. A geometria inicial,
o número de passos e os parâmetros de simulação são mantidos iguais.

## Medição

O tempo é medido com `std::chrono::steady_clock` somente durante a execução
dos passos da simulação. Compilação, inicialização dos campos e gravação de
imagens ficam fora da região cronometrada.

São coletados:

- tempo total e tempo por passo;
- sinuosidade final;
- comprimento curvilíneo e comprimento linear;
- deslocamento lateral máximo;
- quantidade final de pontos;
- ocorrência de valores inválidos.

## Execução

```sh
./Benchmarks/run_benchmark.sh
```

Os resultados são gerados em `Benchmarks/results/`:

- `benchmark_raw.csv`: uma linha por execução;
- `benchmark_summary.csv`: estatísticas agregadas;
- `RELATORIO_BENCHMARK.md`: análise comparativa.

O relatório separa o overhead estrutural (`modificado_neutro`), o custo da
consulta litológica (`modificado_litologico` contra `modificado_neutro`) e o
efeito total em relação à baseline.
