# Relatório do benchmark comparativo

## Configuração

| Campo | Valor |
| --- | --- |
| `benchmark_version` | `1` |
| `baseline_commit` | `c86c93a` |
| `modified_commit` | `ab1122ce8fb633d1754eb830dc43b4fac522f202` |
| `repetitions` | `10` |
| `compiler` | `g++ (GCC) 16.2.1 20260810` |
| `flags` | `-std=c++17 -O2` |
| `system` | `Linux 7.3.4-1-cachyos x86_64 GNU/Linux` |

Foram usadas três variantes, 5 cenários e 10 repetições por combinação.
Os tempos estão em nanossegundos e foram medidos apenas durante os passos da simulação.

## Resultados de tempo

| Variante | Cenário | Amostras | Mediana (ns) | p95 (ns) | Desvio (ns) | Overhead vs original | Overhead vs neutro | Speedup |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| modificado_litologico | avulsao_750 | 10 | 1078271623.50 | 1095919302.00 | 14011829.04 | 2.04% | -1.01% | 0.9800x |
| modificado_litologico | litologia_500 | 10 | 571640075.00 | 615846754.00 | 20523648.87 | 1.93% | -2.18% | 0.9811x |
| modificado_litologico | plano_500 | 10 | 593117854.00 | 628903797.00 | 20263675.45 | 6.30% | 4.51% | 0.9407x |
| modificado_litologico | relevo_litologia_1000 | 10 | 2187778234.50 | 2946326320.00 | 366412752.09 | -12.08% | -19.53% | 1.1375x |
| modificado_litologico | terreno_1200 | 10 | 3705785597.00 | 3812949843.00 | 270335673.17 | 20.18% | 22.03% | 0.8321x |
| modificado_neutro | avulsao_750 | 10 | 1089322136.00 | 1134657282.00 | 23936152.08 | 3.09% | 0.00% | 0.9701x |
| modificado_neutro | litologia_500 | 10 | 584377467.50 | 617990223.00 | 19164887.05 | 4.20% | 0.00% | 0.9597x |
| modificado_neutro | plano_500 | 10 | 567509411.00 | 603704120.00 | 18039214.92 | 1.71% | 0.00% | 0.9831x |
| modificado_neutro | relevo_litologia_1000 | 10 | 2718792164.00 | 3017142570.00 | 241599784.97 | 9.25% | 0.00% | 0.9153x |
| modificado_neutro | terreno_1200 | 10 | 3036890301.00 | 4210028473.00 | 612260567.84 | -1.52% | 0.00% | 1.0154x |
| original | avulsao_750 | 10 | 1056716847.50 | 1084411912.00 | 12229987.25 | 0.00% | -2.99% | 1.0000x |
| original | litologia_500 | 10 | 560836849.00 | 598069625.00 | 18161256.39 | 0.00% | -4.03% | 1.0000x |
| original | plano_500 | 10 | 557945382.00 | 595772213.00 | 15670544.75 | 0.00% | -1.69% | 1.0000x |
| original | relevo_litologia_1000 | 10 | 2488490830.00 | 2881100432.00 | 286762232.43 | 0.00% | -8.47% | 1.0000x |
| original | terreno_1200 | 10 | 3083638510.50 | 4251938349.00 | 636214889.75 | 0.00% | 1.54% | 1.0000x |

## Resultados geométricos

| Variante | Cenário | Sinuosidade média | Desvio da sinuosidade | Deslocamento lateral médio | Valores inválidos |
| --- | --- | ---: | ---: | ---: | ---: |
| modificado_litologico | avulsao_750 | 2.89912263 | 0.32431451 | 7065.16804062 | 0 |
| modificado_litologico | litologia_500 | 2.08244054 | 0.31604793 | 5587.43394346 | 0 |
| modificado_litologico | plano_500 | 2.08244054 | 0.31604793 | 5587.43394346 | 0 |
| modificado_litologico | relevo_litologia_1000 | 3.00593045 | 0.03726895 | 7523.83957619 | 0 |
| modificado_litologico | terreno_1200 | 2.95098115 | 0.27540261 | 7889.67511945 | 0 |
| modificado_neutro | avulsao_750 | 2.89912263 | 0.32431451 | 7065.16804062 | 0 |
| modificado_neutro | litologia_500 | 2.08244054 | 0.31604793 | 5587.43394346 | 0 |
| modificado_neutro | plano_500 | 2.08244054 | 0.31604793 | 5587.43394346 | 0 |
| modificado_neutro | relevo_litologia_1000 | 3.37013260 | 0.31572225 | 9375.03556566 | 0 |
| modificado_neutro | terreno_1200 | 3.10925900 | 0.07721699 | 8528.02924019 | 0 |
| original | avulsao_750 | 2.84727606 | 0.39940597 | 6814.94643068 | 0 |
| original | litologia_500 | 2.08244054 | 0.31604793 | 5587.43394347 | 0 |
| original | plano_500 | 2.08244054 | 0.31604793 | 5587.43394347 | 0 |
| original | relevo_litologia_1000 | 3.07402170 | 0.20891932 | 9082.67435087 | 0 |
| original | terreno_1200 | 3.45252341 | 0.42906135 | 9343.17508712 | 0 |

## Critério de desempenho e qualidade

O limite de 5% é um critério de custo, não uma reprovação automática. Até 5% indica custo compatível. Acima de 5%, a extensão precisa ser justificada por ganho ou diferença geométrica relevante, especialmente em dados reais.

| Variante | Cenário | Overhead vs original | Variação da sinuosidade | Variação do deslocamento | Classificação |
| --- | --- | ---: | ---: | ---: | --- |
| modificado_litologico | avulsao_750 | 2.04% | 1.82% | 3.67% | dentro do limite de 5% |
| modificado_litologico | litologia_500 | 1.93% | -0.00% | -0.00% | dentro do limite de 5% |
| modificado_litologico | plano_500 | 6.30% | -0.00% | -0.00% | justificar com ganho de qualidade |
| modificado_litologico | relevo_litologia_1000 | -12.08% | -2.22% | -17.16% | justificar com ganho de qualidade |
| modificado_litologico | terreno_1200 | 20.18% | -14.53% | -15.56% | justificar com ganho de qualidade |
| modificado_neutro | avulsao_750 | 3.09% | 1.82% | 3.67% | dentro do limite de 5% |
| modificado_neutro | litologia_500 | 4.20% | -0.00% | -0.00% | dentro do limite de 5% |
| modificado_neutro | plano_500 | 1.71% | -0.00% | -0.00% | dentro do limite de 5% |
| modificado_neutro | relevo_litologia_1000 | 9.25% | 9.63% | 3.22% | justificar com ganho de qualidade |
| modificado_neutro | terreno_1200 | -1.52% | -9.94% | -8.72% | dentro do limite de 5% |
| original | avulsao_750 | 0.00% | 0.00% | 0.00% | baseline |
| original | litologia_500 | 0.00% | 0.00% | 0.00% | baseline |
| original | plano_500 | 0.00% | 0.00% | 0.00% | baseline |
| original | relevo_litologia_1000 | 0.00% | 0.00% | 0.00% | baseline |
| original | terreno_1200 | 0.00% | 0.00% | 0.00% | baseline |

## Interpretação

- `modificado_neutro` mede o custo estrutural da extensão quando `E=1`.
- `modificado_litologico` mede o custo adicional das consultas e da modulação espacial.
- O overhead é calculado pela mediana em relação à variante `original` do mesmo cenário.
- O overhead contra `modificado_neutro` isola o custo da litologia.
- Diferenças geométricas não são automaticamente melhorias; em dados reais devem ser comparadas ao traçado ou relevo de referência.
- Os CSVs bruto e resumido permitem reproduzir as tabelas sem executar novamente o benchmark.
