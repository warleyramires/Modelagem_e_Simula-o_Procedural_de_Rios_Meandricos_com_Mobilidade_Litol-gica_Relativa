# Relatório do benchmark comparativo

## Configuração

| Campo | Valor |
| --- | --- |
| `benchmark_version` | `1` |
| `baseline_commit` | `c86c93a` |
| `modified_commit` | `f48f0913e1ac8ac8f977b038b4dda5e26f272892` |
| `repetitions` | `100` |
| `compiler` | `g++ (GCC) 16.2.1 20260810` |
| `flags` | `-std=c++17 -O2` |
| `system` | `Linux 7.3.1-1-cachyos x86_64 GNU/Linux` |

Foram usadas três variantes, quatro cenários e 100 repetições por combinação.
Os tempos estão em nanossegundos e foram medidos apenas durante os passos da simulação.

## Resultados de tempo

| Variante | Cenário | Amostras | Mediana (ns) | p95 (ns) | Desvio (ns) | Overhead vs original | Overhead vs neutro | Speedup |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| modificado_litologico | avulsao_750 | 100 | 1053399060.00 | 1132885319.00 | 42982701.71 | 1.25% | 1.58% | 0.9877x |
| modificado_litologico | litologia_500 | 100 | 571638578.50 | 621308183.00 | 27276993.38 | 1.57% | -0.42% | 0.9845x |
| modificado_litologico | plano_500 | 100 | 569595209.50 | 624313196.00 | 28610957.94 | 2.00% | -0.13% | 0.9803x |
| modificado_litologico | terreno_1200 | 100 | 3561636046.50 | 3860263473.00 | 301446758.19 | 14.27% | 18.35% | 0.8752x |
| modificado_neutro | avulsao_750 | 100 | 1037034415.50 | 1123347533.00 | 41553965.48 | -0.33% | 0.00% | 1.0033x |
| modificado_neutro | litologia_500 | 100 | 574068531.50 | 624559002.00 | 28125916.46 | 2.01% | 0.00% | 0.9803x |
| modificado_neutro | plano_500 | 100 | 570334540.00 | 622052389.00 | 29108103.78 | 2.14% | 0.00% | 0.9791x |
| modificado_neutro | terreno_1200 | 100 | 3009348374.50 | 4270261243.00 | 587562619.57 | -3.45% | 0.00% | 1.0358x |
| original | avulsao_750 | 100 | 1040441745.50 | 1125414047.00 | 44494154.41 | 0.00% | 0.33% | 1.0000x |
| original | litologia_500 | 100 | 562778325.50 | 618047715.00 | 29718105.44 | 0.00% | -1.97% | 1.0000x |
| original | plano_500 | 100 | 558399630.00 | 596446053.00 | 20727754.95 | 0.00% | -2.09% | 1.0000x |
| original | terreno_1200 | 100 | 3116974561.50 | 4329822259.00 | 606807921.11 | 0.00% | 3.58% | 1.0000x |

## Resultados geométricos

| Variante | Cenário | Sinuosidade média | Desvio da sinuosidade | Deslocamento lateral médio | Valores inválidos |
| --- | --- | ---: | ---: | ---: | ---: |
| modificado_litologico | avulsao_750 | 2.86515592 | 0.32094669 | 7059.97535201 | 0 |
| modificado_litologico | litologia_500 | 2.12107690 | 0.30570325 | 5615.87938158 | 0 |
| modificado_litologico | plano_500 | 2.12107690 | 0.30570325 | 5615.87938158 | 0 |
| modificado_litologico | terreno_1200 | 2.92910706 | 0.27958545 | 7828.92727385 | 0 |
| modificado_neutro | avulsao_750 | 2.86515592 | 0.32094669 | 7059.97535201 | 0 |
| modificado_neutro | litologia_500 | 2.12107690 | 0.30570325 | 5615.87938158 | 0 |
| modificado_neutro | plano_500 | 2.12107690 | 0.30570325 | 5615.87938158 | 0 |
| modificado_neutro | terreno_1200 | 3.11871397 | 0.07466826 | 8537.32039318 | 0 |
| original | avulsao_750 | 2.80785276 | 0.39797170 | 6792.38658181 | 0 |
| original | litologia_500 | 2.12107690 | 0.30570325 | 5615.87938158 | 0 |
| original | plano_500 | 2.12107690 | 0.30570325 | 5615.87938158 | 0 |
| original | terreno_1200 | 3.40138735 | 0.41682028 | 9336.77882327 | 0 |

## Interpretação

- `modificado_neutro` mede o custo estrutural da extensão quando `E=1`.
- `modificado_litologico` mede o custo adicional das consultas e da modulação espacial.
- O overhead é calculado pela mediana em relação à variante `original` do mesmo cenário.
- O overhead contra `modificado_neutro` isola o custo da litologia.
- Os CSVs bruto e resumido permitem reproduzir as tabelas sem executar novamente o benchmark.
