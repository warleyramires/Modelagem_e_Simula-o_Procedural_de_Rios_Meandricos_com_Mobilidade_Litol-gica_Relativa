# Benchmark comparativo

Este pacote compara a baseline original do artigo com a implementação da
equipe de Warley Ramires, Alberto Henrique e Pedro Henrique Braga.

## Variantes

- `original`: código importado no commit `c86c93a`.
- `modificado_neutro`: código atual com campo litológico uniforme `E=1`.
- `modificado_litologico`: código atual com campo heterogêneo contendo zonas
  resistentes (`E=0.25`) e erodíveis (`E=1.75`).

## Cenários e iterações

- `plano`: terreno plano.
- `litologia_plana`: terreno plano com campo litológico heterogêneo.
- `terreno`: relevo sintético.
- `relevo_litologia`: relevo ondulado com campo litológico heterogêneo.
- `avulsao`: duas avulsões em 70% da simulação.

Cada cenário é executado com 500, 750, 1000 e 1500 passos. `plano` e
`litologia_plana` são controles isolados; `relevo_litologia` cobre a interação
entre relevo e litologia. A quantidade de passos aparece explicitamente nos
CSVs para impedir comparações entre execuções de durações diferentes.

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

O relatório também classifica o custo: até 5% é considerado compatível; acima
de 5%, o custo precisa ser justificado por uma melhoria ou diferença geométrica
relevante. Essa classificação não reprova automaticamente o cenário, pois a
extensão pode ser mais lenta e ainda produzir um resultado mais realista.

## Execução

```sh
./Benchmarks/run_benchmark.sh
```

Os resultados são gerados em `Benchmarks/results/`:

- `benchmark_raw.csv`: uma linha por execução;
- `benchmark_summary.csv`: estatísticas agregadas;
- `RELATORIO_BENCHMARK.md`: análise comparativa.

Os executáveis também aceitam uma duração explícita:

```sh
./benchmark_original terreno 1000 10
./benchmark_modificado modificado_litologico terreno 1000 10
```

O relatório separa o overhead estrutural (`modificado_neutro`), o custo da
consulta litológica (`modificado_litologico` contra `modificado_neutro`) e o
efeito total em relação à baseline.
