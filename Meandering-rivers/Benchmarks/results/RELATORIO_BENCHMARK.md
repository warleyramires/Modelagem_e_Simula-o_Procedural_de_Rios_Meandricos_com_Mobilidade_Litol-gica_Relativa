# Relatório do benchmark comparativo

## Configuração

| Campo | Valor |
| --- | --- |
| `benchmark_version` | `1` |
| `baseline_commit` | `c86c93a` |
| `modified_commit` | `e236d55ed004629318a29f9eb64971d8ff9ed592` |
| `repetitions` | `1` |
| `compiler` | `g++ (GCC) 16.2.1 20260810` |
| `flags` | `-std=c++17 -O2` |
| `system` | `Linux 7.3.4-1-cachyos x86_64 GNU/Linux` |

Foram usadas três variantes, 5 cenários, 4 quantidades de passos e 1 repetições por combinação.
Os tempos estão em nanossegundos e foram medidos apenas durante os passos da simulação.

## Resultados de tempo

| Variante | Cenário | Passos | Amostras | Mediana (ns) | p95 (ns) | Desvio (ns) | Overhead vs original | Overhead vs neutro | Speedup |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| modificado_litologico | avulsao | 500 | 1 | 531547162.00 | 531547162.00 | 0.00 | 3.80% | 1.52% | 0.9634x |
| modificado_litologico | avulsao | 750 | 1 | 1059167793.00 | 1059167793.00 | 0.00 | 3.31% | 1.64% | 0.9680x |
| modificado_litologico | avulsao | 1000 | 1 | 1774577121.00 | 1774577121.00 | 0.00 | 4.68% | 3.38% | 0.9553x |
| modificado_litologico | avulsao | 1500 | 1 | 3257716659.00 | 3257716659.00 | 0.00 | 6.49% | -5.00% | 0.9391x |
| modificado_litologico | litologia_plana | 500 | 1 | 562168537.00 | 562168537.00 | 0.00 | 2.48% | 0.41% | 0.9758x |
| modificado_litologico | litologia_plana | 750 | 1 | 1069852499.00 | 1069852499.00 | 0.00 | 3.58% | 2.64% | 0.9654x |
| modificado_litologico | litologia_plana | 1000 | 1 | 1754747936.00 | 1754747936.00 | 0.00 | 5.12% | 1.79% | 0.9513x |
| modificado_litologico | litologia_plana | 1500 | 1 | 3066843814.00 | 3066843814.00 | 0.00 | -0.97% | -9.14% | 1.0098x |
| modificado_litologico | plano | 500 | 1 | 566117563.00 | 566117563.00 | 0.00 | 0.68% | -1.60% | 0.9933x |
| modificado_litologico | plano | 750 | 1 | 1063912482.00 | 1063912482.00 | 0.00 | 1.22% | 0.81% | 0.9879x |
| modificado_litologico | plano | 1000 | 1 | 1755533196.00 | 1755533196.00 | 0.00 | 3.44% | 2.16% | 0.9667x |
| modificado_litologico | plano | 1500 | 1 | 3041397294.00 | 3041397294.00 | 0.00 | -0.37% | -10.50% | 1.0037x |
| modificado_litologico | relevo_litologia | 500 | 1 | 1487435529.00 | 1487435529.00 | 0.00 | 14.79% | 10.38% | 0.8711x |
| modificado_litologico | relevo_litologia | 750 | 1 | 2148988471.00 | 2148988471.00 | 0.00 | 6.54% | 6.82% | 0.9387x |
| modificado_litologico | relevo_litologia | 1000 | 1 | 2959513792.00 | 2959513792.00 | 0.00 | 3.49% | 2.87% | 0.9663x |
| modificado_litologico | relevo_litologia | 1500 | 1 | 4523537142.00 | 4523537142.00 | 0.00 | -17.67% | -16.78% | 1.2146x |
| modificado_litologico | terreno | 500 | 1 | 1400745895.00 | 1400745895.00 | 0.00 | 9.68% | 6.51% | 0.9117x |
| modificado_litologico | terreno | 750 | 1 | 2066055323.00 | 2066055323.00 | 0.00 | 1.00% | -0.97% | 0.9901x |
| modificado_litologico | terreno | 1000 | 1 | 2935237440.00 | 2935237440.00 | 0.00 | -4.69% | -5.25% | 1.0492x |
| modificado_litologico | terreno | 1500 | 1 | 4776855045.00 | 4776855045.00 | 0.00 | -17.19% | -10.96% | 1.2076x |
| modificado_neutro | avulsao | 500 | 1 | 523602092.00 | 523602092.00 | 0.00 | 2.25% | 0.00% | 0.9780x |
| modificado_neutro | avulsao | 750 | 1 | 1042069549.00 | 1042069549.00 | 0.00 | 1.64% | 0.00% | 0.9839x |
| modificado_neutro | avulsao | 1000 | 1 | 1716504112.00 | 1716504112.00 | 0.00 | 1.25% | 0.00% | 0.9876x |
| modificado_neutro | avulsao | 1500 | 1 | 3429277106.00 | 3429277106.00 | 0.00 | 12.09% | 0.00% | 0.8921x |
| modificado_neutro | litologia_plana | 500 | 1 | 559855775.00 | 559855775.00 | 0.00 | 2.06% | 0.00% | 0.9798x |
| modificado_neutro | litologia_plana | 750 | 1 | 1042291525.00 | 1042291525.00 | 0.00 | 0.91% | 0.00% | 0.9910x |
| modificado_neutro | litologia_plana | 1000 | 1 | 1723887014.00 | 1723887014.00 | 0.00 | 3.27% | 0.00% | 0.9683x |
| modificado_neutro | litologia_plana | 1500 | 1 | 3375465502.00 | 3375465502.00 | 0.00 | 8.99% | 0.00% | 0.9175x |
| modificado_neutro | plano | 500 | 1 | 575293645.00 | 575293645.00 | 0.00 | 2.31% | 0.00% | 0.9774x |
| modificado_neutro | plano | 750 | 1 | 1055368426.00 | 1055368426.00 | 0.00 | 0.41% | 0.00% | 0.9959x |
| modificado_neutro | plano | 1000 | 1 | 1718425315.00 | 1718425315.00 | 0.00 | 1.26% | 0.00% | 0.9876x |
| modificado_neutro | plano | 1500 | 1 | 3398114719.00 | 3398114719.00 | 0.00 | 11.31% | 0.00% | 0.8984x |
| modificado_neutro | relevo_litologia | 500 | 1 | 1347585196.00 | 1347585196.00 | 0.00 | 4.00% | 0.00% | 0.9615x |
| modificado_neutro | relevo_litologia | 750 | 1 | 2011853557.00 | 2011853557.00 | 0.00 | -0.26% | 0.00% | 1.0026x |
| modificado_neutro | relevo_litologia | 1000 | 1 | 2876829094.00 | 2876829094.00 | 0.00 | 0.60% | 0.00% | 0.9940x |
| modificado_neutro | relevo_litologia | 1500 | 1 | 5435341660.00 | 5435341660.00 | 0.00 | -1.07% | 0.00% | 1.0109x |
| modificado_neutro | terreno | 500 | 1 | 1315181859.00 | 1315181859.00 | 0.00 | 2.98% | 0.00% | 0.9711x |
| modificado_neutro | terreno | 750 | 1 | 2086304882.00 | 2086304882.00 | 0.00 | 1.99% | 0.00% | 0.9805x |
| modificado_neutro | terreno | 1000 | 1 | 3097974949.00 | 3097974949.00 | 0.00 | 0.59% | 0.00% | 0.9941x |
| modificado_neutro | terreno | 1500 | 1 | 5364656389.00 | 5364656389.00 | 0.00 | -7.00% | 0.00% | 1.0753x |
| original | avulsao | 500 | 1 | 512088177.00 | 512088177.00 | 0.00 | 0.00% | -2.20% | 1.0000x |
| original | avulsao | 750 | 1 | 1025251242.00 | 1025251242.00 | 0.00 | 0.00% | -1.61% | 1.0000x |
| original | avulsao | 1000 | 1 | 1695290257.00 | 1695290257.00 | 0.00 | 0.00% | -1.24% | 1.0000x |
| original | avulsao | 1500 | 1 | 3059301692.00 | 3059301692.00 | 0.00 | 0.00% | -10.79% | 1.0000x |
| original | litologia_plana | 500 | 1 | 548570076.00 | 548570076.00 | 0.00 | 0.00% | -2.02% | 1.0000x |
| original | litologia_plana | 750 | 1 | 1032878724.00 | 1032878724.00 | 0.00 | 0.00% | -0.90% | 1.0000x |
| original | litologia_plana | 1000 | 1 | 1669230995.00 | 1669230995.00 | 0.00 | 0.00% | -3.17% | 1.0000x |
| original | litologia_plana | 1500 | 1 | 3096916409.00 | 3096916409.00 | 0.00 | 0.00% | -8.25% | 1.0000x |
| original | plano | 500 | 1 | 562300355.00 | 562300355.00 | 0.00 | 0.00% | -2.26% | 1.0000x |
| original | plano | 750 | 1 | 1051062063.00 | 1051062063.00 | 0.00 | 0.00% | -0.41% | 1.0000x |
| original | plano | 1000 | 1 | 1697110023.00 | 1697110023.00 | 0.00 | 0.00% | -1.24% | 1.0000x |
| original | plano | 1500 | 1 | 3052770586.00 | 3052770586.00 | 0.00 | 0.00% | -10.16% | 1.0000x |
| original | relevo_litologia | 500 | 1 | 1295755221.00 | 1295755221.00 | 0.00 | 0.00% | -3.85% | 1.0000x |
| original | relevo_litologia | 750 | 1 | 2017160674.00 | 2017160674.00 | 0.00 | 0.00% | 0.26% | 1.0000x |
| original | relevo_litologia | 1000 | 1 | 2859672586.00 | 2859672586.00 | 0.00 | 0.00% | -0.60% | 1.0000x |
| original | relevo_litologia | 1500 | 1 | 5494373381.00 | 5494373381.00 | 0.00 | 0.00% | 1.09% | 1.0000x |
| original | terreno | 500 | 1 | 1277109983.00 | 1277109983.00 | 0.00 | 0.00% | -2.89% | 1.0000x |
| original | terreno | 750 | 1 | 2045542270.00 | 2045542270.00 | 0.00 | 0.00% | -1.95% | 1.0000x |
| original | terreno | 1000 | 1 | 3079732665.00 | 3079732665.00 | 0.00 | 0.00% | -0.59% | 1.0000x |
| original | terreno | 1500 | 1 | 5768591318.00 | 5768591318.00 | 0.00 | 0.00% | 7.53% | 1.0000x |

## Resultados geométricos

| Variante | Cenário | Passos | Sinuosidade média | Desvio da sinuosidade | Deslocamento lateral médio | Valores inválidos |
| --- | --- | ---: | ---: | ---: | ---: | ---: |
| modificado_litologico | avulsao | 500 | 1.88131378 | 0.00000000 | 4881.73165862 | 0 |
| modificado_litologico | avulsao | 750 | 2.82159890 | 0.00000000 | 6926.29546119 | 0 |
| modificado_litologico | avulsao | 1000 | 2.85565792 | 0.00000000 | 6485.42812623 | 0 |
| modificado_litologico | avulsao | 1500 | 3.72385786 | 0.00000000 | 7374.96511327 | 0 |
| modificado_litologico | litologia_plana | 500 | 1.69607697 | 0.00000000 | 5302.97956233 | 0 |
| modificado_litologico | litologia_plana | 750 | 3.23878973 | 0.00000000 | 7117.09492671 | 0 |
| modificado_litologico | litologia_plana | 1000 | 2.85565792 | 0.00000000 | 6485.42812623 | 0 |
| modificado_litologico | litologia_plana | 1500 | 2.69238361 | 0.00000000 | 7895.87008246 | 0 |
| modificado_litologico | plano | 500 | 1.69607697 | 0.00000000 | 5302.97956233 | 0 |
| modificado_litologico | plano | 750 | 3.23878973 | 0.00000000 | 7117.09492671 | 0 |
| modificado_litologico | plano | 1000 | 2.85565792 | 0.00000000 | 6485.42812623 | 0 |
| modificado_litologico | plano | 1500 | 2.69238361 | 0.00000000 | 7895.87008246 | 0 |
| modificado_litologico | relevo_litologia | 500 | 3.04317816 | 0.00000000 | 8258.69732260 | 0 |
| modificado_litologico | relevo_litologia | 750 | 2.57004820 | 0.00000000 | 6674.32280505 | 0 |
| modificado_litologico | relevo_litologia | 1000 | 2.96824336 | 0.00000000 | 7232.17386962 | 0 |
| modificado_litologico | relevo_litologia | 1500 | 2.78349898 | 0.00000000 | 7095.35887571 | 0 |
| modificado_litologico | terreno | 500 | 2.18024279 | 0.00000000 | 7523.63866240 | 0 |
| modificado_litologico | terreno | 750 | 2.73521260 | 0.00000000 | 8876.95596648 | 0 |
| modificado_litologico | terreno | 1000 | 3.22408465 | 0.00000000 | 9462.45713190 | 0 |
| modificado_litologico | terreno | 1500 | 2.80375133 | 0.00000000 | 7376.64987849 | 0 |
| modificado_neutro | avulsao | 500 | 1.88131378 | 0.00000000 | 4881.73165862 | 0 |
| modificado_neutro | avulsao | 750 | 2.82159890 | 0.00000000 | 6926.29546119 | 0 |
| modificado_neutro | avulsao | 1000 | 2.50423665 | 0.00000000 | 6457.70750651 | 0 |
| modificado_neutro | avulsao | 1500 | 3.90339939 | 0.00000000 | 7345.83869999 | 0 |
| modificado_neutro | litologia_plana | 500 | 1.69607697 | 0.00000000 | 5302.97956233 | 0 |
| modificado_neutro | litologia_plana | 750 | 3.23878973 | 0.00000000 | 7117.09492671 | 0 |
| modificado_neutro | litologia_plana | 1000 | 2.50423665 | 0.00000000 | 6457.70750651 | 0 |
| modificado_neutro | litologia_plana | 1500 | 3.90339939 | 0.00000000 | 7345.83869999 | 0 |
| modificado_neutro | plano | 500 | 1.69607697 | 0.00000000 | 5302.97956233 | 0 |
| modificado_neutro | plano | 750 | 3.23878973 | 0.00000000 | 7117.09492671 | 0 |
| modificado_neutro | plano | 1000 | 2.50423665 | 0.00000000 | 6457.70750651 | 0 |
| modificado_neutro | plano | 1500 | 3.90339939 | 0.00000000 | 7345.83869999 | 0 |
| modificado_neutro | relevo_litologia | 500 | 2.77923704 | 0.00000000 | 9065.31671045 | 0 |
| modificado_neutro | relevo_litologia | 750 | 2.69662181 | 0.00000000 | 9373.42833688 | 0 |
| modificado_neutro | relevo_litologia | 1000 | 3.23175634 | 0.00000000 | 9743.14211916 | 0 |
| modificado_neutro | relevo_litologia | 1500 | 3.74755465 | 0.00000000 | 11172.39908835 | 0 |
| modificado_neutro | terreno | 500 | 2.31909661 | 0.00000000 | 7923.05186964 | 0 |
| modificado_neutro | terreno | 750 | 2.88456094 | 0.00000000 | 9910.74567910 | 0 |
| modificado_neutro | terreno | 1000 | 3.38194940 | 0.00000000 | 10533.46300310 | 0 |
| modificado_neutro | terreno | 1500 | 3.49371220 | 0.00000000 | 10414.22870261 | 0 |
| original | avulsao | 500 | 1.88131378 | 0.00000000 | 4881.73165862 | 0 |
| original | avulsao | 750 | 2.85390513 | 0.00000000 | 6926.34219892 | 0 |
| original | avulsao | 1000 | 2.97289537 | 0.00000000 | 6703.21185443 | 0 |
| original | avulsao | 1500 | 2.83859561 | 0.00000000 | 8146.90593503 | 0 |
| original | litologia_plana | 500 | 1.69607697 | 0.00000000 | 5302.97956234 | 0 |
| original | litologia_plana | 750 | 3.24150913 | 0.00000000 | 7040.54491934 | 0 |
| original | litologia_plana | 1000 | 2.97289537 | 0.00000000 | 6703.21185443 | 0 |
| original | litologia_plana | 1500 | 2.83859561 | 0.00000000 | 8146.90593503 | 0 |
| original | plano | 500 | 1.69607697 | 0.00000000 | 5302.97956234 | 0 |
| original | plano | 750 | 3.24150913 | 0.00000000 | 7040.54491934 | 0 |
| original | plano | 1000 | 2.97289537 | 0.00000000 | 6703.21185443 | 0 |
| original | plano | 1500 | 2.83859561 | 0.00000000 | 8146.90593503 | 0 |
| original | relevo_litologia | 500 | 2.77923704 | 0.00000000 | 9065.31671044 | 0 |
| original | relevo_litologia | 750 | 2.69662181 | 0.00000000 | 9373.42833688 | 0 |
| original | relevo_litologia | 1000 | 3.23175653 | 0.00000000 | 9743.14211896 | 0 |
| original | relevo_litologia | 1500 | 4.02478616 | 0.00000000 | 11728.00728097 | 0 |
| original | terreno | 500 | 2.31909661 | 0.00000000 | 7923.05186964 | 0 |
| original | terreno | 750 | 2.88456094 | 0.00000000 | 9910.74567911 | 0 |
| original | terreno | 1000 | 3.53369559 | 0.00000000 | 10590.79860034 | 0 |
| original | terreno | 1500 | 3.54497321 | 0.00000000 | 10296.96239387 | 0 |

## Critério de desempenho e qualidade

O limite de 5% é um critério de custo, não uma reprovação automática. Até 5% indica custo compatível. Acima de 5%, a extensão precisa ser justificada por ganho ou diferença geométrica relevante, especialmente em dados reais.

| Variante | Cenário | Passos | Overhead vs original | Variação da sinuosidade | Variação do deslocamento | Classificação |
| --- | --- | ---: | ---: | ---: | ---: | --- |
| modificado_litologico | avulsao | 500 | 3.80% | -0.00% | -0.00% | dentro do limite de 5% |
| modificado_litologico | avulsao | 750 | 3.31% | -1.13% | -0.00% | dentro do limite de 5% |
| modificado_litologico | avulsao | 1000 | 4.68% | -3.94% | -3.25% | dentro do limite de 5% |
| modificado_litologico | avulsao | 1500 | 6.49% | 31.19% | -9.48% | justificar com ganho de qualidade |
| modificado_litologico | litologia_plana | 500 | 2.48% | 0.00% | -0.00% | dentro do limite de 5% |
| modificado_litologico | litologia_plana | 750 | 3.58% | -0.08% | 1.09% | dentro do limite de 5% |
| modificado_litologico | litologia_plana | 1000 | 5.12% | -3.94% | -3.25% | justificar com ganho de qualidade |
| modificado_litologico | litologia_plana | 1500 | -0.97% | -5.15% | -3.08% | dentro do limite de 5% |
| modificado_litologico | plano | 500 | 0.68% | 0.00% | -0.00% | dentro do limite de 5% |
| modificado_litologico | plano | 750 | 1.22% | -0.08% | 1.09% | dentro do limite de 5% |
| modificado_litologico | plano | 1000 | 3.44% | -3.94% | -3.25% | dentro do limite de 5% |
| modificado_litologico | plano | 1500 | -0.37% | -5.15% | -3.08% | dentro do limite de 5% |
| modificado_litologico | relevo_litologia | 500 | 14.79% | 9.50% | -8.90% | justificar com ganho de qualidade |
| modificado_litologico | relevo_litologia | 750 | 6.54% | -4.69% | -28.80% | justificar com ganho de qualidade |
| modificado_litologico | relevo_litologia | 1000 | 3.49% | -8.15% | -25.77% | dentro do limite de 5% |
| modificado_litologico | relevo_litologia | 1500 | -17.67% | -30.84% | -39.50% | justificar com ganho de qualidade |
| modificado_litologico | terreno | 500 | 9.68% | -5.99% | -5.04% | justificar com ganho de qualidade |
| modificado_litologico | terreno | 750 | 1.00% | -5.18% | -10.43% | dentro do limite de 5% |
| modificado_litologico | terreno | 1000 | -4.69% | -8.76% | -10.65% | dentro do limite de 5% |
| modificado_litologico | terreno | 1500 | -17.19% | -20.91% | -28.36% | justificar com ganho de qualidade |
| modificado_neutro | avulsao | 500 | 2.25% | -0.00% | -0.00% | dentro do limite de 5% |
| modificado_neutro | avulsao | 750 | 1.64% | -1.13% | -0.00% | dentro do limite de 5% |
| modificado_neutro | avulsao | 1000 | 1.25% | -15.76% | -3.66% | dentro do limite de 5% |
| modificado_neutro | avulsao | 1500 | 12.09% | 37.51% | -9.83% | justificar com ganho de qualidade |
| modificado_neutro | litologia_plana | 500 | 2.06% | 0.00% | -0.00% | dentro do limite de 5% |
| modificado_neutro | litologia_plana | 750 | 0.91% | -0.08% | 1.09% | dentro do limite de 5% |
| modificado_neutro | litologia_plana | 1000 | 3.27% | -15.76% | -3.66% | dentro do limite de 5% |
| modificado_neutro | litologia_plana | 1500 | 8.99% | 37.51% | -9.83% | justificar com ganho de qualidade |
| modificado_neutro | plano | 500 | 2.31% | 0.00% | -0.00% | dentro do limite de 5% |
| modificado_neutro | plano | 750 | 0.41% | -0.08% | 1.09% | dentro do limite de 5% |
| modificado_neutro | plano | 1000 | 1.26% | -15.76% | -3.66% | dentro do limite de 5% |
| modificado_neutro | plano | 1500 | 11.31% | 37.51% | -9.83% | justificar com ganho de qualidade |
| modificado_neutro | relevo_litologia | 500 | 4.00% | 0.00% | 0.00% | dentro do limite de 5% |
| modificado_neutro | relevo_litologia | 750 | -0.26% | -0.00% | 0.00% | dentro do limite de 5% |
| modificado_neutro | relevo_litologia | 1000 | 0.60% | -0.00% | 0.00% | dentro do limite de 5% |
| modificado_neutro | relevo_litologia | 1500 | -1.07% | -6.89% | -4.74% | dentro do limite de 5% |
| modificado_neutro | terreno | 500 | 2.98% | 0.00% | 0.00% | dentro do limite de 5% |
| modificado_neutro | terreno | 750 | 1.99% | 0.00% | -0.00% | dentro do limite de 5% |
| modificado_neutro | terreno | 1000 | 0.59% | -4.29% | -0.54% | dentro do limite de 5% |
| modificado_neutro | terreno | 1500 | -7.00% | -1.45% | 1.14% | justificar com ganho de qualidade |
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
