# Relatório do benchmark comparativo

## Configuração

| Campo | Valor |
| --- | --- |
| `benchmark_version` | `1` |
| `baseline_commit` | `c86c93a` |
| `modified_commit` | `c8e26eb01e165ed62c35bea57e45a92e9aadf9b6` |
| `repetitions` | `3` |
| `compiler` | `g++ (Alpine 15.2.0) 15.2.0` |
| `flags` | `-std=c++17 -O2` |
| `system` | `Linux 6.18.58.1-microsoft-standard-WSL2 x86_64 Linux` |

Foram usadas três variantes, 5 cenários, 4 quantidades de passos e 3 repetições por combinação.
Os tempos estão em nanossegundos e foram medidos apenas durante os passos da simulação.

## Resultados de tempo

| Variante | Cenário | Passos | Amostras | Mediana (ns) | p95 (ns) | Desvio (ns) | Overhead vs original | Overhead vs neutro | Speedup |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| modificado_litologico | avulsao | 500 | 3 | 1704247884.00 | 1711170648.00 | 11330234.58 | -2.46% | -15.42% | 1.0252x |
| modificado_litologico | avulsao | 750 | 3 | 3046220496.00 | 3128176835.00 | 158375629.34 | -2.53% | -15.01% | 1.0260x |
| modificado_litologico | avulsao | 1000 | 3 | 4599145444.00 | 5373609069.00 | 376878314.80 | -4.71% | -11.32% | 1.0494x |
| modificado_litologico | avulsao | 1500 | 3 | 9006472734.00 | 9995029394.00 | 730405509.66 | 2.91% | -0.41% | 0.9717x |
| modificado_litologico | litologia_plana | 500 | 3 | 1952091155.00 | 1986279556.00 | 71026787.96 | 2.71% | 13.27% | 0.9737x |
| modificado_litologico | litologia_plana | 750 | 3 | 3327149321.00 | 3538831229.00 | 106884531.19 | 1.04% | 4.31% | 0.9897x |
| modificado_litologico | litologia_plana | 1000 | 3 | 4696819680.00 | 4713821631.00 | 20651629.72 | -16.94% | -6.35% | 1.2040x |
| modificado_litologico | litologia_plana | 1500 | 3 | 7795853019.00 | 7954849765.00 | 178685692.17 | -15.95% | -8.02% | 1.1897x |
| modificado_litologico | plano | 500 | 3 | 1842958122.00 | 1950872732.00 | 58073340.25 | -13.30% | 7.39% | 1.1534x |
| modificado_litologico | plano | 750 | 3 | 3400043045.00 | 3512300732.00 | 122803301.15 | -5.85% | 5.63% | 1.0621x |
| modificado_litologico | plano | 1000 | 3 | 5357606629.00 | 5977424181.00 | 355781060.27 | 1.07% | 6.86% | 0.9895x |
| modificado_litologico | plano | 1500 | 3 | 8637054604.00 | 8940483793.00 | 425957590.85 | -9.19% | 4.69% | 1.1012x |
| modificado_litologico | relevo_litologia | 500 | 3 | 3134704741.00 | 6063743327.00 | 1551994508.32 | 24.40% | 21.09% | 0.8039x |
| modificado_litologico | relevo_litologia | 750 | 3 | 5500316464.00 | 8190438227.00 | 1340918627.05 | 9.51% | 7.80% | 0.9131x |
| modificado_litologico | relevo_litologia | 1000 | 3 | 8194787212.00 | 10860083569.00 | 1295990034.38 | 5.78% | 6.37% | 0.9454x |
| modificado_litologico | relevo_litologia | 1500 | 3 | 13577626637.00 | 16136712872.00 | 1281851352.70 | 2.85% | 2.97% | 0.9723x |
| modificado_litologico | terreno | 500 | 3 | 3109400720.00 | 7746212872.00 | 2372278638.55 | 33.13% | 49.26% | 0.7512x |
| modificado_litologico | terreno | 750 | 3 | 5285805762.00 | 10326991700.00 | 2592091556.27 | 14.04% | 19.52% | 0.8769x |
| modificado_litologico | terreno | 1000 | 3 | 7885302255.00 | 12652480235.00 | 2629520672.54 | 3.47% | 0.01% | 0.9665x |
| modificado_litologico | terreno | 1500 | 3 | 12929718564.00 | 17374373040.00 | 2145087639.44 | -7.17% | -11.05% | 1.0773x |
| modificado_neutro | avulsao | 500 | 3 | 2014925262.00 | 2017755532.00 | 65482405.85 | 15.32% | 0.00% | 0.8671x |
| modificado_neutro | avulsao | 750 | 3 | 3584149084.00 | 3778555163.00 | 120562869.62 | 14.68% | 0.00% | 0.8720x |
| modificado_neutro | avulsao | 1000 | 3 | 5186156632.00 | 5784300688.00 | 356240744.19 | 7.46% | 0.00% | 0.9306x |
| modificado_neutro | avulsao | 1500 | 3 | 9043307811.00 | 9519860432.00 | 525455930.97 | 3.34% | 0.00% | 0.9677x |
| modificado_neutro | litologia_plana | 500 | 3 | 1723434246.00 | 1744543933.00 | 18061332.93 | -9.32% | 0.00% | 1.1028x |
| modificado_neutro | litologia_plana | 750 | 3 | 3189688801.00 | 3355585044.00 | 138307996.74 | -3.13% | 0.00% | 1.0323x |
| modificado_neutro | litologia_plana | 1000 | 3 | 5015443620.00 | 5474257118.00 | 282462650.40 | -11.31% | 0.00% | 1.1275x |
| modificado_neutro | litologia_plana | 1500 | 3 | 8475361875.00 | 8901464475.00 | 349409942.97 | -8.62% | 0.00% | 1.0943x |
| modificado_neutro | plano | 500 | 3 | 1716107625.00 | 1752894015.00 | 18903055.57 | -19.27% | 0.00% | 1.2387x |
| modificado_neutro | plano | 750 | 3 | 3218927308.00 | 3311942356.00 | 52199596.61 | -10.86% | 0.00% | 1.1219x |
| modificado_neutro | plano | 1000 | 3 | 5013838879.00 | 5406402507.00 | 299663172.44 | -5.42% | 0.00% | 1.0573x |
| modificado_neutro | plano | 1500 | 3 | 8250306934.00 | 8950839485.00 | 356194095.42 | -13.26% | 0.00% | 1.1528x |
| modificado_neutro | relevo_litologia | 500 | 3 | 2588659718.00 | 6244296247.00 | 1835165075.55 | 2.73% | 0.00% | 0.9735x |
| modificado_neutro | relevo_litologia | 750 | 3 | 5102191911.00 | 9155585358.00 | 1989017394.71 | 1.59% | 0.00% | 0.9844x |
| modificado_neutro | relevo_litologia | 1000 | 3 | 7704252520.00 | 11210323459.00 | 1815754047.81 | -0.55% | 0.00% | 1.0056x |
| modificado_neutro | relevo_litologia | 1500 | 3 | 13185683111.00 | 19890693408.00 | 3361177468.78 | -0.12% | 0.00% | 1.0012x |
| modificado_neutro | terreno | 500 | 3 | 2083256973.00 | 7425038078.00 | 2538859187.95 | -10.81% | 0.00% | 1.1212x |
| modificado_neutro | terreno | 750 | 3 | 4422663285.00 | 11121634383.00 | 3224799584.97 | -4.58% | 0.00% | 1.0480x |
| modificado_neutro | terreno | 1000 | 3 | 7884578781.00 | 13924971716.00 | 3071492919.44 | 3.46% | 0.00% | 0.9666x |
| modificado_neutro | terreno | 1500 | 3 | 14536311613.00 | 22143191910.00 | 3821359360.50 | 4.36% | 0.00% | 0.9582x |
| original | avulsao | 500 | 3 | 1747241868.00 | 1829988676.00 | 45560808.05 | 0.00% | -13.29% | 1.0000x |
| original | avulsao | 750 | 3 | 3125301086.00 | 3153083807.00 | 149489305.28 | 0.00% | -12.80% | 1.0000x |
| original | avulsao | 1000 | 3 | 4826251949.00 | 5748449487.00 | 488319338.50 | 0.00% | -6.94% | 1.0000x |
| original | avulsao | 1500 | 3 | 8751434533.00 | 9134558701.00 | 185855667.19 | 0.00% | -3.23% | 1.0000x |
| original | litologia_plana | 500 | 3 | 1900667394.00 | 2315917065.00 | 235343920.05 | 0.00% | 10.28% | 1.0000x |
| original | litologia_plana | 750 | 3 | 3292775228.00 | 3421355582.00 | 94068032.12 | 0.00% | 3.23% | 1.0000x |
| original | litologia_plana | 1000 | 3 | 5654826306.00 | 6088381573.00 | 253233663.80 | 0.00% | 12.75% | 1.0000x |
| original | litologia_plana | 1500 | 3 | 9275010551.00 | 9731996626.00 | 385402577.45 | 0.00% | 9.43% | 1.0000x |
| original | plano | 500 | 3 | 2125726357.00 | 2140539002.00 | 74873735.83 | 0.00% | 23.87% | 1.0000x |
| original | plano | 750 | 3 | 3611284741.00 | 4017622822.00 | 244464424.28 | 0.00% | 12.19% | 1.0000x |
| original | plano | 1000 | 3 | 5301138326.00 | 5634876261.00 | 207588587.49 | 0.00% | 5.73% | 1.0000x |
| original | plano | 1500 | 3 | 9511138618.00 | 10257838787.00 | 531542623.18 | 0.00% | 15.28% | 1.0000x |
| original | relevo_litologia | 500 | 3 | 2519931500.00 | 6418883608.00 | 1907220119.09 | 0.00% | -2.65% | 1.0000x |
| original | relevo_litologia | 750 | 3 | 5022471113.00 | 8249040331.00 | 1764806347.20 | 0.00% | -1.56% | 1.0000x |
| original | relevo_litologia | 1000 | 3 | 7747035009.00 | 11813450094.00 | 1970580574.07 | 0.00% | 0.56% | 1.0000x |
| original | relevo_litologia | 1500 | 3 | 13201631622.00 | 18448919766.00 | 2901037125.46 | 0.00% | 0.12% | 1.0000x |
| original | terreno | 500 | 3 | 2335675526.00 | 7907650394.00 | 2650205703.32 | 0.00% | 12.12% | 1.0000x |
| original | terreno | 750 | 3 | 4634960728.00 | 11099221911.00 | 3069651712.95 | 0.00% | 4.80% | 1.0000x |
| original | terreno | 1000 | 3 | 7621217519.00 | 13815468885.00 | 2938709962.54 | 0.00% | -3.34% | 1.0000x |
| original | terreno | 1500 | 3 | 13928731904.00 | 21798296228.00 | 3879720022.43 | 0.00% | -4.18% | 1.0000x |

## Resultados geométricos

| Variante | Cenário | Passos | Sinuosidade média | Desvio da sinuosidade | Deslocamento lateral médio | Valores inválidos |
| --- | --- | ---: | ---: | ---: | ---: | ---: |
| modificado_litologico | avulsao | 500 | 2.19090148 | 0.12456876 | 6030.22399434 | 0 |
| modificado_litologico | avulsao | 750 | 2.69874420 | 0.15256518 | 7596.94807394 | 0 |
| modificado_litologico | avulsao | 1000 | 2.81880471 | 0.45010948 | 6674.22357244 | 0 |
| modificado_litologico | avulsao | 1500 | 2.61694354 | 0.14913908 | 6295.77547614 | 0 |
| modificado_litologico | litologia_plana | 500 | 2.59012842 | 0.09101371 | 5844.99944383 | 0 |
| modificado_litologico | litologia_plana | 750 | 2.59160100 | 0.09497664 | 5991.99173606 | 0 |
| modificado_litologico | litologia_plana | 1000 | 2.86313571 | 0.33278984 | 6311.10620422 | 0 |
| modificado_litologico | litologia_plana | 1500 | 2.71318368 | 0.25077054 | 6884.37373393 | 0 |
| modificado_litologico | plano | 500 | 2.26236896 | 0.01194503 | 5989.28225912 | 0 |
| modificado_litologico | plano | 750 | 2.92530517 | 0.48245060 | 7506.94292962 | 0 |
| modificado_litologico | plano | 1000 | 3.06157468 | 0.28545319 | 7370.30702277 | 0 |
| modificado_litologico | plano | 1500 | 2.68358004 | 0.23143415 | 6665.06957777 | 0 |
| modificado_litologico | relevo_litologia | 500 | 2.60274098 | 0.12662190 | 7777.13674552 | 0 |
| modificado_litologico | relevo_litologia | 750 | 2.79917775 | 0.26218939 | 7236.28322154 | 0 |
| modificado_litologico | relevo_litologia | 1000 | 2.89563362 | 0.26097239 | 8474.27980822 | 0 |
| modificado_litologico | relevo_litologia | 1500 | 3.02339815 | 0.26911992 | 9874.84872489 | 0 |
| modificado_litologico | terreno | 500 | 2.43080689 | 0.30149775 | 7028.71901658 | 0 |
| modificado_litologico | terreno | 750 | 2.40618076 | 0.26093494 | 7169.25427153 | 0 |
| modificado_litologico | terreno | 1000 | 2.48210416 | 0.06629511 | 7317.23253712 | 0 |
| modificado_litologico | terreno | 1500 | 2.77177040 | 0.27923646 | 7453.15529686 | 0 |
| modificado_neutro | avulsao | 500 | 2.19090148 | 0.12456876 | 6030.22399434 | 0 |
| modificado_neutro | avulsao | 750 | 2.69874420 | 0.15256518 | 7596.94807394 | 0 |
| modificado_neutro | avulsao | 1000 | 2.71006218 | 0.36664052 | 6520.62197421 | 0 |
| modificado_neutro | avulsao | 1500 | 2.92195029 | 0.19948095 | 7339.38024251 | 0 |
| modificado_neutro | litologia_plana | 500 | 2.26236896 | 0.01194503 | 5989.28225912 | 0 |
| modificado_neutro | litologia_plana | 750 | 2.92530517 | 0.48245060 | 7506.94292962 | 0 |
| modificado_neutro | litologia_plana | 1000 | 2.69131417 | 0.38278833 | 6417.02563688 | 0 |
| modificado_neutro | litologia_plana | 1500 | 2.72581004 | 0.29089206 | 7065.54153739 | 0 |
| modificado_neutro | plano | 500 | 2.26236896 | 0.01194503 | 5989.28225912 | 0 |
| modificado_neutro | plano | 750 | 2.92530517 | 0.48245060 | 7506.94292962 | 0 |
| modificado_neutro | plano | 1000 | 2.69131417 | 0.38278833 | 6417.02563688 | 0 |
| modificado_neutro | plano | 1500 | 2.72581004 | 0.29089206 | 7065.54153739 | 0 |
| modificado_neutro | relevo_litologia | 500 | 2.18550965 | 0.16094222 | 7007.20516856 | 0 |
| modificado_neutro | relevo_litologia | 750 | 2.74752294 | 0.27908928 | 8412.52154824 | 0 |
| modificado_neutro | relevo_litologia | 1000 | 2.92381629 | 0.32508040 | 9108.55278759 | 0 |
| modificado_neutro | relevo_litologia | 1500 | 3.13556708 | 0.51543918 | 8733.10693942 | 0 |
| modificado_neutro | terreno | 500 | 2.32421775 | 0.27739071 | 7416.36831153 | 0 |
| modificado_neutro | terreno | 750 | 2.72236520 | 0.15028132 | 8776.89895312 | 0 |
| modificado_neutro | terreno | 1000 | 2.89039117 | 0.17027030 | 8526.69308410 | 0 |
| modificado_neutro | terreno | 1500 | 3.28929586 | 0.21117972 | 9322.67687249 | 0 |
| original | avulsao | 500 | 2.19090148 | 0.12456876 | 6030.22399436 | 0 |
| original | avulsao | 750 | 2.69874383 | 0.15256534 | 7596.94824236 | 0 |
| original | avulsao | 1000 | 2.74062182 | 0.53032652 | 6505.37492937 | 0 |
| original | avulsao | 1500 | 2.97624177 | 0.41242972 | 7881.49076740 | 0 |
| original | litologia_plana | 500 | 2.26236896 | 0.01194503 | 5989.28225913 | 0 |
| original | litologia_plana | 750 | 2.92518910 | 0.48231897 | 7506.49743120 | 0 |
| original | litologia_plana | 1000 | 2.96074713 | 0.37548398 | 6675.67184736 | 0 |
| original | litologia_plana | 1500 | 2.88858386 | 0.38929538 | 7235.08526821 | 0 |
| original | plano | 500 | 2.26236896 | 0.01194503 | 5989.28225913 | 0 |
| original | plano | 750 | 2.92518910 | 0.48231897 | 7506.49743120 | 0 |
| original | plano | 1000 | 2.96074713 | 0.37548398 | 6675.67184736 | 0 |
| original | plano | 1500 | 2.88858386 | 0.38929538 | 7235.08526821 | 0 |
| original | relevo_litologia | 500 | 2.18550965 | 0.16094222 | 7007.20516856 | 0 |
| original | relevo_litologia | 750 | 2.74752294 | 0.27908928 | 8412.52154823 | 0 |
| original | relevo_litologia | 1000 | 2.93660196 | 0.33308381 | 9104.88729768 | 0 |
| original | relevo_litologia | 1500 | 2.92445477 | 0.58816912 | 9028.90665909 | 0 |
| original | terreno | 500 | 2.32421775 | 0.27739071 | 7416.36831153 | 0 |
| original | terreno | 750 | 2.72236520 | 0.15028132 | 8776.89895306 | 0 |
| original | terreno | 1000 | 2.88033124 | 0.17303642 | 8636.45920379 | 0 |
| original | terreno | 1500 | 3.43042515 | 0.56846023 | 9384.83327463 | 0 |

## Critério de desempenho e qualidade

O limite de 5% é um critério de custo, não uma reprovação automática. Até 5% indica custo compatível. Acima de 5%, a extensão precisa ser justificada por ganho ou diferença geométrica relevante, especialmente em dados reais.

| Variante | Cenário | Passos | Overhead vs original | Variação da sinuosidade | Variação do deslocamento | Classificação |
| --- | --- | ---: | ---: | ---: | ---: | --- |
| modificado_litologico | avulsao | 500 | -2.46% | -0.00% | -0.00% | dentro do limite de 5% |
| modificado_litologico | avulsao | 750 | -2.53% | 0.00% | -0.00% | dentro do limite de 5% |
| modificado_litologico | avulsao | 1000 | -4.71% | 2.85% | 2.60% | dentro do limite de 5% |
| modificado_litologico | avulsao | 1500 | 2.91% | -12.07% | -20.12% | dentro do limite de 5% |
| modificado_litologico | litologia_plana | 500 | 2.71% | 14.49% | -2.41% | dentro do limite de 5% |
| modificado_litologico | litologia_plana | 750 | 1.04% | -11.40% | -20.18% | dentro do limite de 5% |
| modificado_litologico | litologia_plana | 1000 | -16.94% | -3.30% | -5.46% | dentro do limite de 5% |
| modificado_litologico | litologia_plana | 1500 | -15.95% | -6.07% | -4.85% | dentro do limite de 5% |
| modificado_litologico | plano | 500 | -13.30% | -0.00% | -0.00% | dentro do limite de 5% |
| modificado_litologico | plano | 750 | -5.85% | 0.00% | 0.01% | dentro do limite de 5% |
| modificado_litologico | plano | 1000 | 1.07% | 3.41% | 10.41% | dentro do limite de 5% |
| modificado_litologico | plano | 1500 | -9.19% | -7.10% | -7.88% | dentro do limite de 5% |
| modificado_litologico | relevo_litologia | 500 | 24.40% | 19.09% | 10.99% | justificar com ganho de qualidade |
| modificado_litologico | relevo_litologia | 750 | 9.51% | 1.88% | -13.98% | justificar com ganho de qualidade |
| modificado_litologico | relevo_litologia | 1000 | 5.78% | -1.40% | -6.93% | justificar com ganho de qualidade |
| modificado_litologico | relevo_litologia | 1500 | 2.85% | 3.38% | 9.37% | dentro do limite de 5% |
| modificado_litologico | terreno | 500 | 33.13% | 4.59% | -5.23% | justificar com ganho de qualidade |
| modificado_litologico | terreno | 750 | 14.04% | -11.61% | -18.32% | justificar com ganho de qualidade |
| modificado_litologico | terreno | 1000 | 3.47% | -13.83% | -15.28% | dentro do limite de 5% |
| modificado_litologico | terreno | 1500 | -7.17% | -19.20% | -20.58% | dentro do limite de 5% |
| modificado_neutro | avulsao | 500 | 15.32% | -0.00% | -0.00% | justificar com ganho de qualidade |
| modificado_neutro | avulsao | 750 | 14.68% | 0.00% | -0.00% | justificar com ganho de qualidade |
| modificado_neutro | avulsao | 1000 | 7.46% | -1.12% | 0.23% | justificar com ganho de qualidade |
| modificado_neutro | avulsao | 1500 | 3.34% | -1.82% | -6.88% | dentro do limite de 5% |
| modificado_neutro | litologia_plana | 500 | -9.32% | -0.00% | -0.00% | dentro do limite de 5% |
| modificado_neutro | litologia_plana | 750 | -3.13% | 0.00% | 0.01% | dentro do limite de 5% |
| modificado_neutro | litologia_plana | 1000 | -11.31% | -9.10% | -3.87% | dentro do limite de 5% |
| modificado_neutro | litologia_plana | 1500 | -8.62% | -5.64% | -2.34% | dentro do limite de 5% |
| modificado_neutro | plano | 500 | -19.27% | -0.00% | -0.00% | dentro do limite de 5% |
| modificado_neutro | plano | 750 | -10.86% | 0.00% | 0.01% | dentro do limite de 5% |
| modificado_neutro | plano | 1000 | -5.42% | -9.10% | -3.87% | dentro do limite de 5% |
| modificado_neutro | plano | 1500 | -13.26% | -5.64% | -2.34% | dentro do limite de 5% |
| modificado_neutro | relevo_litologia | 500 | 2.73% | 0.00% | -0.00% | dentro do limite de 5% |
| modificado_neutro | relevo_litologia | 750 | 1.59% | 0.00% | 0.00% | dentro do limite de 5% |
| modificado_neutro | relevo_litologia | 1000 | -0.55% | -0.44% | 0.04% | dentro do limite de 5% |
| modificado_neutro | relevo_litologia | 1500 | -0.12% | 7.22% | -3.28% | dentro do limite de 5% |
| modificado_neutro | terreno | 500 | -10.81% | -0.00% | 0.00% | dentro do limite de 5% |
| modificado_neutro | terreno | 750 | -4.58% | 0.00% | 0.00% | dentro do limite de 5% |
| modificado_neutro | terreno | 1000 | 3.46% | 0.35% | -1.27% | dentro do limite de 5% |
| modificado_neutro | terreno | 1500 | 4.36% | -4.11% | -0.66% | dentro do limite de 5% |
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
