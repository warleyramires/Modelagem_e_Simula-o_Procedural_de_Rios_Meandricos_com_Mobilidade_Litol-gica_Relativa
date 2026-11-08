# Modelagem e Simulação Procedural de Rios Meândricos

Extensão acadêmica do código de referência *Authoring and Simulating
Meandering Rivers*, desenvolvida por **Warley Ramires, Alberto Henrique e
Pedro Henrique Braga**.

O projeto investiga como a mobilidade litológica relativa do substrato altera
a migração lateral de rios meândricos procedurais. A implementação mantém o
método geométrico do artigo e adiciona um campo espacial `E(x,y)` independente
do relevo: margens externas sobre materiais resistentes migram mais lentamente,
enquanto materiais erodíveis aceleram a migração.

## O que foi desenvolvido

- Campo 2D opcional de mobilidade litológica `E(x,y)`, representado por
  `ScalarField2D`.
- Amostragem na margem externa do canal, a meia largura do centroline.
- Normalização por `E_medio` e fator `clamp(E/E_medio, 0.25, 2.0)`.
- Entrada de litologia por imagem grayscale, com valores normalizados para
  `[0, 1]`.
- Compatibilidade com a baseline: sem campo litológico, o comportamento
  original é preservado.
- Cenário de demonstração e teste de regressão para `E=1` e campos
  heterogêneos.

## Organização

| Pasta | Conteúdo |
| --- | --- |
| `Code/Include` | Cabeçalhos e estruturas do simulador |
| `Code/Source` | Implementação da simulação e exemplos |
| `Resources` | Imagens de entrada |
| `Results` | Saídas `.ppm` dos exemplos |
| `Tests` | Testes de regressão da extensão litológica |
| `Docs` | Comparação entre a baseline e a implementação da equipe |
| `VS2022` | Solução original para Visual Studio 2022 |

## Compilação e execução

O código não exige bibliotecas externas além dos arquivos incluídos no
repositório. Com GCC:

```sh
g++ -std=c++17 -O2 -ICode/Include Code/Source/*.cpp \
  -o /tmp/meandering
(cd VS2022 && /tmp/meandering)
```

Os exemplos geram imagens na pasta `Results/`. O exemplo litológico gera
`meander_lithology.ppm`.

Para executar a regressão:

```sh
g++ -std=c++17 -O2 -ICode/Include Tests/lithology_regression.cpp \
  Code/Source/cubic-curve-set.cpp Code/Source/cubic-curve.cpp \
  Code/Source/cubic.cpp Code/Source/linear.cpp \
  Code/Source/meanders-channel.cpp Code/Source/meanders-simulation.cpp \
  Code/Source/quadric.cpp -o /tmp/lithology_regression
/tmp/lithology_regression
```

O teste verifica que um campo uniforme reproduz a baseline e que um campo
heterogêneo modifica a trajetória sem produzir valores inválidos.

## Uso do campo litológico

```cpp
ScalarField2D terrain = LoadScalarFieldFromFile(
    200.0, 200.0, 2500.0, "../Resources/hf.png");
ScalarField2D mobility = LoadLithologyFromFile(
    200.0, 200.0, "../Resources/lithology.png");

MeanderSimulation simulation(1234, terrain, mobility);
```

Uma matriz constante é neutra, pois `E/E_medio = 1`. O campo é consultado
durante a migração, sem substituir a influência da declividade do terreno,
das restrições autorais, dos cutoffs ou das avulsões.

## Referência científica

A implementação parte do artigo:

> Paris, Axel; Guérin, Eric; Collon, Pauline; Galin, Eric. *Authoring and
> Simulating Meandering Rivers*. ACM Transactions on Graphics, 2023.

O artigo original e os materiais do projeto estão em
[HAL](https://hal.science/hal-04227965). A comparação detalhada entre a
baseline e a contribuição da equipe está em
[Docs/DIFF_ORIGINAL_VS_EQUIPE.md](Docs/DIFF_ORIGINAL_VS_EQUIPE.md).

## Licença e atribuição

O código de referência possui licença MIT. A utilização do método original
deve citar o artigo acima; a extensão litológica deve ser atribuída a Warley
Ramires, Alberto Henrique e Pedro Henrique Braga.
