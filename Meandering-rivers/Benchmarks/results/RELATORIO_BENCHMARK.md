# Relatório do benchmark comparativo

## Configuração

| Campo | Valor |
| --- | --- |
| `benchmark_version` | `1` |
| `baseline_commit` | `c86c93a` |
| `modified_commit` | `22800c8abc91fe4b8f6a91457d13424760d2a8df` |
| `repetitions` | `1` |
| `compiler` | `g++ (GCC) 16.2.1 20260810` |
| `flags` | `-std=c++17 -O2` |
| `system` | `Linux 7.3.4-1-cachyos x86_64 GNU/Linux` |

Foram usadas três variantes, 5 cenários, 4 quantidades de passos e 1 repetições por combinação.
Os tempos estão em nanossegundos e foram medidos apenas durante os passos da simulação.

## Resultados de tempo

| Variante | Cenário | Passos | Amostras | Mediana (ns) | p95 (ns) | Desvio (ns) | Overhead vs original | Overhead vs neutro | Speedup |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| modificado_litologico | avulsao | 500 | 1 | 559474284.00 | 559474284.00 | 0.00 | 6.46% | 8.66% | 0.9393x |
| modificado_litologico | avulsao | 750 | 1 | 1107752127.00 | 1107752127.00 | 0.00 | 7.03% | 3.80% | 0.9343x |
| modificado_litologico | avulsao | 1000 | 1 | 1873771069.00 | 1873771069.00 | 0.00 | 14.03% | 6.14% | 0.8770x |
| modificado_litologico | avulsao | 1500 | 1 | 3395420220.00 | 3395420220.00 | 0.00 | 5.82% | -2.51% | 0.9450x |
| modificado_litologico | litologia_plana | 500 | 1 | 727916167.00 | 727916167.00 | 0.00 | 27.50% | 29.09% | 0.7843x |
| modificado_litologico | litologia_plana | 750 | 1 | 1221087166.00 | 1221087166.00 | 0.00 | 18.20% | 14.15% | 0.8460x |
| modificado_litologico | litologia_plana | 1000 | 1 | 1613968896.00 | 1613968896.00 | 0.00 | -2.98% | -10.25% | 1.0307x |
| modificado_litologico | litologia_plana | 1500 | 1 | 3029280590.00 | 3029280590.00 | 0.00 | -0.77% | -15.10% | 1.0078x |
| modificado_litologico | plano | 500 | 1 | 566531137.00 | 566531137.00 | 0.00 | 5.01% | -6.06% | 0.9523x |
| modificado_litologico | plano | 750 | 1 | 1071433010.00 | 1071433010.00 | 0.00 | 7.00% | -1.45% | 0.9346x |
| modificado_litologico | plano | 1000 | 1 | 1799454817.00 | 1799454817.00 | 0.00 | 9.55% | -0.60% | 0.9128x |
| modificado_litologico | plano | 1500 | 1 | 3146645159.00 | 3146645159.00 | 0.00 | 2.14% | -9.24% | 0.9790x |
| modificado_litologico | relevo_litologia | 500 | 1 | 1494976450.00 | 1494976450.00 | 0.00 | 13.02% | 13.02% | 0.8848x |
| modificado_litologico | relevo_litologia | 750 | 1 | 2381875592.00 | 2381875592.00 | 0.00 | 17.34% | 15.66% | 0.8522x |
| modificado_litologico | relevo_litologia | 1000 | 1 | 3114309311.00 | 3114309311.00 | 0.00 | 10.54% | 3.70% | 0.9047x |
| modificado_litologico | relevo_litologia | 1500 | 1 | 4748610890.00 | 4748610890.00 | 0.00 | -9.91% | -14.98% | 1.1100x |
| modificado_litologico | terreno | 500 | 1 | 1474277686.00 | 1474277686.00 | 0.00 | 15.37% | 9.10% | 0.8668x |
| modificado_litologico | terreno | 750 | 1 | 2076666617.00 | 2076666617.00 | 0.00 | 4.47% | -0.28% | 0.9572x |
| modificado_litologico | terreno | 1000 | 1 | 2961409720.00 | 2961409720.00 | 0.00 | -2.24% | -5.20% | 1.0229x |
| modificado_litologico | terreno | 1500 | 1 | 4958364942.00 | 4958364942.00 | 0.00 | -13.17% | -11.59% | 1.1517x |
| modificado_neutro | avulsao | 500 | 1 | 514874828.00 | 514874828.00 | 0.00 | -2.03% | 0.00% | 1.0207x |
| modificado_neutro | avulsao | 750 | 1 | 1067231421.00 | 1067231421.00 | 0.00 | 3.12% | 0.00% | 0.9698x |
| modificado_neutro | avulsao | 1000 | 1 | 1765397526.00 | 1765397526.00 | 0.00 | 7.44% | 0.00% | 0.9308x |
| modificado_neutro | avulsao | 1500 | 1 | 3482714574.00 | 3482714574.00 | 0.00 | 8.54% | 0.00% | 0.9213x |
| modificado_neutro | litologia_plana | 500 | 1 | 563897692.00 | 563897692.00 | 0.00 | -1.23% | 0.00% | 1.0124x |
| modificado_neutro | litologia_plana | 750 | 1 | 1069723047.00 | 1069723047.00 | 0.00 | 3.55% | 0.00% | 0.9657x |
| modificado_neutro | litologia_plana | 1000 | 1 | 1798283784.00 | 1798283784.00 | 0.00 | 8.10% | 0.00% | 0.9250x |
| modificado_neutro | litologia_plana | 1500 | 1 | 3568261020.00 | 3568261020.00 | 0.00 | 16.88% | 0.00% | 0.8556x |
| modificado_neutro | plano | 500 | 1 | 603103062.00 | 603103062.00 | 0.00 | 11.79% | 0.00% | 0.8946x |
| modificado_neutro | plano | 750 | 1 | 1087205314.00 | 1087205314.00 | 0.00 | 8.58% | 0.00% | 0.9210x |
| modificado_neutro | plano | 1000 | 1 | 1810327734.00 | 1810327734.00 | 0.00 | 10.22% | 0.00% | 0.9073x |
| modificado_neutro | plano | 1500 | 1 | 3467089996.00 | 3467089996.00 | 0.00 | 12.54% | 0.00% | 0.8885x |
| modificado_neutro | relevo_litologia | 500 | 1 | 1322713870.00 | 1322713870.00 | 0.00 | -0.00% | 0.00% | 1.0000x |
| modificado_neutro | relevo_litologia | 750 | 1 | 2059392580.00 | 2059392580.00 | 0.00 | 1.45% | 0.00% | 0.9857x |
| modificado_neutro | relevo_litologia | 1000 | 1 | 3003089911.00 | 3003089911.00 | 0.00 | 6.59% | 0.00% | 0.9382x |
| modificado_neutro | relevo_litologia | 1500 | 1 | 5585279017.00 | 5585279017.00 | 0.00 | 5.96% | 0.00% | 0.9437x |
| modificado_neutro | terreno | 500 | 1 | 1351277190.00 | 1351277190.00 | 0.00 | 5.74% | 0.00% | 0.9457x |
| modificado_neutro | terreno | 750 | 1 | 2082543987.00 | 2082543987.00 | 0.00 | 4.76% | 0.00% | 0.9545x |
| modificado_neutro | terreno | 1000 | 1 | 3123987107.00 | 3123987107.00 | 0.00 | 3.13% | 0.00% | 0.9696x |
| modificado_neutro | terreno | 1500 | 1 | 5608111380.00 | 5608111380.00 | 0.00 | -1.80% | 0.00% | 1.0183x |
| original | avulsao | 500 | 1 | 525528085.00 | 525528085.00 | 0.00 | 0.00% | 2.07% | 1.0000x |
| original | avulsao | 750 | 1 | 1034968503.00 | 1034968503.00 | 0.00 | 0.00% | -3.02% | 1.0000x |
| original | avulsao | 1000 | 1 | 1643218182.00 | 1643218182.00 | 0.00 | 0.00% | -6.92% | 1.0000x |
| original | avulsao | 1500 | 1 | 3208647389.00 | 3208647389.00 | 0.00 | 0.00% | -7.87% | 1.0000x |
| original | litologia_plana | 500 | 1 | 570898113.00 | 570898113.00 | 0.00 | 0.00% | 1.24% | 1.0000x |
| original | litologia_plana | 750 | 1 | 1033060571.00 | 1033060571.00 | 0.00 | 0.00% | -3.43% | 1.0000x |
| original | litologia_plana | 1000 | 1 | 1663483709.00 | 1663483709.00 | 0.00 | 0.00% | -7.50% | 1.0000x |
| original | litologia_plana | 1500 | 1 | 3052934397.00 | 3052934397.00 | 0.00 | 0.00% | -14.44% | 1.0000x |
| original | plano | 500 | 1 | 539511132.00 | 539511132.00 | 0.00 | 0.00% | -10.54% | 1.0000x |
| original | plano | 750 | 1 | 1001338883.00 | 1001338883.00 | 0.00 | 0.00% | -7.90% | 1.0000x |
| original | plano | 1000 | 1 | 1642528253.00 | 1642528253.00 | 0.00 | 0.00% | -9.27% | 1.0000x |
| original | plano | 1500 | 1 | 3080675534.00 | 3080675534.00 | 0.00 | 0.00% | -11.15% | 1.0000x |
| original | relevo_litologia | 500 | 1 | 1322773676.00 | 1322773676.00 | 0.00 | 0.00% | 0.00% | 1.0000x |
| original | relevo_litologia | 750 | 1 | 2029932316.00 | 2029932316.00 | 0.00 | 0.00% | -1.43% | 1.0000x |
| original | relevo_litologia | 1000 | 1 | 2817374520.00 | 2817374520.00 | 0.00 | 0.00% | -6.18% | 1.0000x |
| original | relevo_litologia | 1500 | 1 | 5270987960.00 | 5270987960.00 | 0.00 | 0.00% | -5.63% | 1.0000x |
| original | terreno | 500 | 1 | 1277867357.00 | 1277867357.00 | 0.00 | 0.00% | -5.43% | 1.0000x |
| original | terreno | 750 | 1 | 1987873420.00 | 1987873420.00 | 0.00 | 0.00% | -4.55% | 1.0000x |
| original | terreno | 1000 | 1 | 3029156609.00 | 3029156609.00 | 0.00 | 0.00% | -3.04% | 1.0000x |
| original | terreno | 1500 | 1 | 5710640343.00 | 5710640343.00 | 0.00 | 0.00% | 1.83% | 1.0000x |

## Resultados geométricos

| Variante | Cenário | Passos | Sinuosidade média | Desvio da sinuosidade | Deslocamento lateral médio | Erro do centerline | Valores inválidos |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| modificado_litologico | avulsao | 500 | 1.88131378 | 0.00000000 | 4881.73165862 | n/a | 0 |
| modificado_litologico | avulsao | 750 | 2.82159890 | 0.00000000 | 6926.29546119 | n/a | 0 |
| modificado_litologico | avulsao | 1000 | 2.85565792 | 0.00000000 | 6485.42812623 | n/a | 0 |
| modificado_litologico | avulsao | 1500 | 3.72385786 | 0.00000000 | 7374.96511327 | n/a | 0 |
| modificado_litologico | litologia_plana | 500 | 2.23505743 | 0.00000000 | 5287.33694258 | n/a | 0 |
| modificado_litologico | litologia_plana | 750 | 2.22271915 | 0.00000000 | 4360.40176087 | n/a | 0 |
| modificado_litologico | litologia_plana | 1000 | 2.70113204 | 0.00000000 | 6711.60587290 | n/a | 0 |
| modificado_litologico | litologia_plana | 1500 | 3.53203298 | 0.00000000 | 5379.98194531 | n/a | 0 |
| modificado_litologico | plano | 500 | 1.69607697 | 0.00000000 | 5302.97956233 | n/a | 0 |
| modificado_litologico | plano | 750 | 3.23878973 | 0.00000000 | 7117.09492671 | n/a | 0 |
| modificado_litologico | plano | 1000 | 2.85565792 | 0.00000000 | 6485.42812623 | n/a | 0 |
| modificado_litologico | plano | 1500 | 2.69238361 | 0.00000000 | 7895.87008246 | n/a | 0 |
| modificado_litologico | relevo_litologia | 500 | 3.04317816 | 0.00000000 | 8258.69732260 | n/a | 0 |
| modificado_litologico | relevo_litologia | 750 | 2.57004820 | 0.00000000 | 6674.32280505 | n/a | 0 |
| modificado_litologico | relevo_litologia | 1000 | 2.96824336 | 0.00000000 | 7232.17386962 | n/a | 0 |
| modificado_litologico | relevo_litologia | 1500 | 2.78349898 | 0.00000000 | 7095.35887571 | n/a | 0 |
| modificado_litologico | terreno | 500 | 2.18024279 | 0.00000000 | 7523.63866240 | n/a | 0 |
| modificado_litologico | terreno | 750 | 2.73521260 | 0.00000000 | 8876.95596648 | n/a | 0 |
| modificado_litologico | terreno | 1000 | 3.22408465 | 0.00000000 | 9462.45713190 | n/a | 0 |
| modificado_litologico | terreno | 1500 | 2.80375133 | 0.00000000 | 7376.64987849 | n/a | 0 |
| modificado_neutro | avulsao | 500 | 1.88131378 | 0.00000000 | 4881.73165862 | n/a | 0 |
| modificado_neutro | avulsao | 750 | 2.82159890 | 0.00000000 | 6926.29546119 | n/a | 0 |
| modificado_neutro | avulsao | 1000 | 2.50423665 | 0.00000000 | 6457.70750651 | n/a | 0 |
| modificado_neutro | avulsao | 1500 | 3.90339939 | 0.00000000 | 7345.83869999 | n/a | 0 |
| modificado_neutro | litologia_plana | 500 | 1.69607697 | 0.00000000 | 5302.97956233 | n/a | 0 |
| modificado_neutro | litologia_plana | 750 | 3.23878973 | 0.00000000 | 7117.09492671 | n/a | 0 |
| modificado_neutro | litologia_plana | 1000 | 2.50423665 | 0.00000000 | 6457.70750651 | n/a | 0 |
| modificado_neutro | litologia_plana | 1500 | 3.90339939 | 0.00000000 | 7345.83869999 | n/a | 0 |
| modificado_neutro | plano | 500 | 1.69607697 | 0.00000000 | 5302.97956233 | n/a | 0 |
| modificado_neutro | plano | 750 | 3.23878973 | 0.00000000 | 7117.09492671 | n/a | 0 |
| modificado_neutro | plano | 1000 | 2.50423665 | 0.00000000 | 6457.70750651 | n/a | 0 |
| modificado_neutro | plano | 1500 | 3.90339939 | 0.00000000 | 7345.83869999 | n/a | 0 |
| modificado_neutro | relevo_litologia | 500 | 2.77923704 | 0.00000000 | 9065.31671045 | n/a | 0 |
| modificado_neutro | relevo_litologia | 750 | 2.69662181 | 0.00000000 | 9373.42833688 | n/a | 0 |
| modificado_neutro | relevo_litologia | 1000 | 3.23175634 | 0.00000000 | 9743.14211916 | n/a | 0 |
| modificado_neutro | relevo_litologia | 1500 | 3.74755465 | 0.00000000 | 11172.39908835 | n/a | 0 |
| modificado_neutro | terreno | 500 | 2.31909661 | 0.00000000 | 7923.05186964 | n/a | 0 |
| modificado_neutro | terreno | 750 | 2.88456094 | 0.00000000 | 9910.74567910 | n/a | 0 |
| modificado_neutro | terreno | 1000 | 3.38194940 | 0.00000000 | 10533.46300310 | n/a | 0 |
| modificado_neutro | terreno | 1500 | 3.49371220 | 0.00000000 | 10414.22870261 | n/a | 0 |
| original | avulsao | 500 | 1.88131378 | 0.00000000 | 4881.73165862 | n/a | 0 |
| original | avulsao | 750 | 2.85390513 | 0.00000000 | 6926.34219892 | n/a | 0 |
| original | avulsao | 1000 | 2.97289537 | 0.00000000 | 6703.21185443 | n/a | 0 |
| original | avulsao | 1500 | 2.83859561 | 0.00000000 | 8146.90593503 | n/a | 0 |
| original | litologia_plana | 500 | 1.69607697 | 0.00000000 | 5302.97956234 | n/a | 0 |
| original | litologia_plana | 750 | 3.24150913 | 0.00000000 | 7040.54491934 | n/a | 0 |
| original | litologia_plana | 1000 | 2.97289537 | 0.00000000 | 6703.21185443 | n/a | 0 |
| original | litologia_plana | 1500 | 2.83859561 | 0.00000000 | 8146.90593503 | n/a | 0 |
| original | plano | 500 | 1.69607697 | 0.00000000 | 5302.97956234 | n/a | 0 |
| original | plano | 750 | 3.24150913 | 0.00000000 | 7040.54491934 | n/a | 0 |
| original | plano | 1000 | 2.97289537 | 0.00000000 | 6703.21185443 | n/a | 0 |
| original | plano | 1500 | 2.83859561 | 0.00000000 | 8146.90593503 | n/a | 0 |
| original | relevo_litologia | 500 | 2.77923704 | 0.00000000 | 9065.31671044 | n/a | 0 |
| original | relevo_litologia | 750 | 2.69662181 | 0.00000000 | 9373.42833688 | n/a | 0 |
| original | relevo_litologia | 1000 | 3.23175653 | 0.00000000 | 9743.14211896 | n/a | 0 |
| original | relevo_litologia | 1500 | 4.02478616 | 0.00000000 | 11728.00728097 | n/a | 0 |
| original | terreno | 500 | 2.31909661 | 0.00000000 | 7923.05186964 | n/a | 0 |
| original | terreno | 750 | 2.88456094 | 0.00000000 | 9910.74567911 | n/a | 0 |
| original | terreno | 1000 | 3.53369559 | 0.00000000 | 10590.79860034 | n/a | 0 |
| original | terreno | 1500 | 3.54497321 | 0.00000000 | 10296.96239387 | n/a | 0 |

## Critério de desempenho e qualidade

O limite de 5% é um critério de custo, não uma reprovação automática. Até 5% indica custo compatível. Acima de 5%, a extensão precisa ser justificada por ganho ou diferença geométrica relevante, especialmente em dados reais.

| Variante | Cenário | Passos | Overhead vs original | Variação da sinuosidade | Variação do deslocamento | Classificação |
| --- | --- | ---: | ---: | ---: | ---: | --- |
| modificado_litologico | avulsao | 500 | 6.46% | -0.00% | -0.00% | justificar com ganho de qualidade |
| modificado_litologico | avulsao | 750 | 7.03% | -1.13% | -0.00% | justificar com ganho de qualidade |
| modificado_litologico | avulsao | 1000 | 14.03% | -3.94% | -3.25% | justificar com ganho de qualidade |
| modificado_litologico | avulsao | 1500 | 5.82% | 31.19% | -9.48% | justificar com ganho de qualidade |
| modificado_litologico | litologia_plana | 500 | 27.50% | 31.78% | -0.29% | justificar com ganho de qualidade |
| modificado_litologico | litologia_plana | 750 | 18.20% | -31.43% | -38.07% | justificar com ganho de qualidade |
| modificado_litologico | litologia_plana | 1000 | -2.98% | -9.14% | 0.13% | dentro do limite de 5% |
| modificado_litologico | litologia_plana | 1500 | -0.77% | 24.43% | -33.96% | dentro do limite de 5% |
| modificado_litologico | plano | 500 | 5.01% | 0.00% | -0.00% | justificar com ganho de qualidade |
| modificado_litologico | plano | 750 | 7.00% | -0.08% | 1.09% | justificar com ganho de qualidade |
| modificado_litologico | plano | 1000 | 9.55% | -3.94% | -3.25% | justificar com ganho de qualidade |
| modificado_litologico | plano | 1500 | 2.14% | -5.15% | -3.08% | dentro do limite de 5% |
| modificado_litologico | relevo_litologia | 500 | 13.02% | 9.50% | -8.90% | justificar com ganho de qualidade |
| modificado_litologico | relevo_litologia | 750 | 17.34% | -4.69% | -28.80% | justificar com ganho de qualidade |
| modificado_litologico | relevo_litologia | 1000 | 10.54% | -8.15% | -25.77% | justificar com ganho de qualidade |
| modificado_litologico | relevo_litologia | 1500 | -9.91% | -30.84% | -39.50% | dentro do limite de 5% |
| modificado_litologico | terreno | 500 | 15.37% | -5.99% | -5.04% | justificar com ganho de qualidade |
| modificado_litologico | terreno | 750 | 4.47% | -5.18% | -10.43% | dentro do limite de 5% |
| modificado_litologico | terreno | 1000 | -2.24% | -8.76% | -10.65% | dentro do limite de 5% |
| modificado_litologico | terreno | 1500 | -13.17% | -20.91% | -28.36% | dentro do limite de 5% |
| modificado_neutro | avulsao | 500 | -2.03% | -0.00% | -0.00% | dentro do limite de 5% |
| modificado_neutro | avulsao | 750 | 3.12% | -1.13% | -0.00% | dentro do limite de 5% |
| modificado_neutro | avulsao | 1000 | 7.44% | -15.76% | -3.66% | justificar com ganho de qualidade |
| modificado_neutro | avulsao | 1500 | 8.54% | 37.51% | -9.83% | justificar com ganho de qualidade |
| modificado_neutro | litologia_plana | 500 | -1.23% | 0.00% | -0.00% | dentro do limite de 5% |
| modificado_neutro | litologia_plana | 750 | 3.55% | -0.08% | 1.09% | dentro do limite de 5% |
| modificado_neutro | litologia_plana | 1000 | 8.10% | -15.76% | -3.66% | justificar com ganho de qualidade |
| modificado_neutro | litologia_plana | 1500 | 16.88% | 37.51% | -9.83% | justificar com ganho de qualidade |
| modificado_neutro | plano | 500 | 11.79% | 0.00% | -0.00% | justificar com ganho de qualidade |
| modificado_neutro | plano | 750 | 8.58% | -0.08% | 1.09% | justificar com ganho de qualidade |
| modificado_neutro | plano | 1000 | 10.22% | -15.76% | -3.66% | justificar com ganho de qualidade |
| modificado_neutro | plano | 1500 | 12.54% | 37.51% | -9.83% | justificar com ganho de qualidade |
| modificado_neutro | relevo_litologia | 500 | -0.00% | 0.00% | 0.00% | dentro do limite de 5% |
| modificado_neutro | relevo_litologia | 750 | 1.45% | -0.00% | 0.00% | dentro do limite de 5% |
| modificado_neutro | relevo_litologia | 1000 | 6.59% | -0.00% | 0.00% | justificar com ganho de qualidade |
| modificado_neutro | relevo_litologia | 1500 | 5.96% | -6.89% | -4.74% | justificar com ganho de qualidade |
| modificado_neutro | terreno | 500 | 5.74% | 0.00% | 0.00% | justificar com ganho de qualidade |
| modificado_neutro | terreno | 750 | 4.76% | 0.00% | -0.00% | dentro do limite de 5% |
| modificado_neutro | terreno | 1000 | 3.13% | -4.29% | -0.54% | dentro do limite de 5% |
| modificado_neutro | terreno | 1500 | -1.80% | -1.45% | 1.14% | dentro do limite de 5% |
| original | avulsao | 500 | 0.00% | 0.00% | 0.00% | baseline |
| original | avulsao | 750 | 0.00% | 0.00% | 0.00% | baseline |
| original | avulsao | 1000 | 0.00% | 0.00% | 0.00% | baseline |
| original | avulsao | 1500 | 0.00% | 0.00% | 0.00% | baseline |
| original | litologia_plana | 500 | 0.00% | 0.00% | 0.00% | baseline |
| original | litologia_plana | 750 | 0.00% | 0.00% | 0.00% | baseline |
| original | litologia_plana | 1000 | 0.00% | 0.00% | 0.00% | baseline |
| original | litologia_plana | 1500 | 0.00% | 0.00% | 0.00% | baseline |
| original | plano | 500 | 0.00% | 0.00% | 0.00% | baseline |
| original | plano | 750 | 0.00% | 0.00% | 0.00% | baseline |
| original | plano | 1000 | 0.00% | 0.00% | 0.00% | baseline |
| original | plano | 1500 | 0.00% | 0.00% | 0.00% | baseline |
| original | relevo_litologia | 500 | 0.00% | 0.00% | 0.00% | baseline |
| original | relevo_litologia | 750 | 0.00% | 0.00% | 0.00% | baseline |
| original | relevo_litologia | 1000 | 0.00% | 0.00% | 0.00% | baseline |
| original | relevo_litologia | 1500 | 0.00% | 0.00% | 0.00% | baseline |
| original | terreno | 500 | 0.00% | 0.00% | 0.00% | baseline |
| original | terreno | 750 | 0.00% | 0.00% | 0.00% | baseline |
| original | terreno | 1000 | 0.00% | 0.00% | 0.00% | baseline |
| original | terreno | 1500 | 0.00% | 0.00% | 0.00% | baseline |

## Interpretação

- `modificado_neutro` mede o custo estrutural da extensão quando `E=1`.
- `modificado_litologico` mede o custo adicional das consultas e da modulação espacial.
- O overhead é calculado pela mediana em relação à variante `original` do mesmo cenário.
- O overhead contra `modificado_neutro` isola o custo da litologia.
- Diferenças geométricas não são automaticamente melhorias; em dados reais devem ser comparadas ao traçado ou relevo de referência.
- Os CSVs bruto e resumido permitem reproduzir as tabelas sem executar novamente o benchmark.
