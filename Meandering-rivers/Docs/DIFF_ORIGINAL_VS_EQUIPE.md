# Diferenças entre a baseline e a implementação da equipe

Este documento compara o código público original de `aparis69/Meandering-rivers`
com a versão desenvolvida por **Warley Ramires, Alberto Henrique e Pedro
Henrique Braga**.

## Resumo da contribuição

| Área | Código original | Implementação da equipe |
| --- | --- | --- |
| Migração | Curvatura local, influência a montante, declividade e controles | Mantém esses termos e adiciona mobilidade litológica |
| Terreno | `ScalarField2D` usado para relevo e gradiente | Novo `ScalarField2D` independente para `E(x,y)` |
| Entrada | Terreno procedural ou imagem de altura | Campo litológico adicional por imagem grayscale |
| Margem | Migração baseada na normal do canal | Consulta na margem externa a `width/2` |
| Taxa | `mu_base` | `mu_lito = clamp(E/E_medio) * mu_base` |
| Validação | Exemplos visuais | Regressão `E=1`, cenário heterogêneo e verificação de NaN |

## Arquivos alterados

- `Code/Include/basics.h`: média dos valores de `ScalarField2D`.
- `Code/Include/meanders.h`: novos dados, construtor, setter, overload de
  `Migrate` e acesso somente-leitura aos canais.
- `Code/Source/meanders-simulation.cpp`: gerenciamento do campo litológico e
  ativação opt-in da modulação.
- `Code/Source/meanders-channel.cpp`: amostragem da margem externa e aplicação
  do fator de mobilidade.
- `Code/Source/main.cpp`: carregamento de imagem e exemplo litológico.
- `Tests/lithology_regression.cpp`: testes de paridade e heterogeneidade.

## Diferença da interface pública

### Baseline

```cpp
MeanderSimulation(int seed, const ScalarField2D& hf);

void Migrate(
    const Box2D& domain,
    const Grid2<Vector2>& terrainGrad,
    const std::vector<PointConstraint>& constraints);
```

### Versão da equipe

```cpp
MeanderSimulation(
    int seed,
    const ScalarField2D& hf,
    const ScalarField2D& lithology);

void SetLithologyField(const ScalarField2D& lithology);
void ClearLithologyField();

void Migrate(
    const Box2D& domain,
    const Grid2<Vector2>& terrainGrad,
    const std::vector<PointConstraint>& constraints,
    const ScalarField2D& lithology,
    double lithologyMean,
    double mobilityMinimum,
    double mobilityMaximum);
```

Os construtores originais continuam válidos e deixam a modulação desativada.

## Diferença no algoritmo de migração

Na baseline, o deslocamento lateral é calculado diretamente com a taxa
geomorfológica e os pesos de declividade e extremidade:

```cpp
outPoints[i][0] = pts[i][0]
    + w * MeanderSimulation::Dt
    * ptsMigrationRates[i] * normalMigration[0];
```

A versão da equipe calcula primeiro a margem externa. Para curvatura positiva
usa o lado oposto à normal; para curvatura negativa usa o lado correspondente.
Em inflexões, consulta os dois lados e calcula a média disponível:

```cpp
const Vector2 externalOffset = curvature > epsilon
    ? -normal * halfWidth
    : (curvature < -epsilon ? normal * halfWidth : Vector2(0.0));
```

Depois, a mobilidade é normalizada, limitada e aplicada à taxa original:

```cpp
mobility = Math::Clamp(
    selected / lithologyMean,
    mobilityMinimum,
    mobilityMaximum);

const double migration = baseWeight
    * mobility
    * MeanderSimulation::Dt
    * ptsMigrationRates[i];
```

Assim:

- `E < E_medio` reduz a migração lateral;
- `E > E_medio` aumenta a migração lateral;
- `E = E_medio` mantém o fator neutro `1.0`;
- amostras inválidas ou fora do domínio usam mobilidade neutra.

## Diferença no fluxo da simulação

O caminho original continua sendo usado quando não há litologia:

```cpp
if (lithologyEnabled)
    channel.Migrate(..., lithology, lithologyMean, 0.25, 2.0);
else
    channel.Migrate(...);
```

Isso permite comparar a contribuição isoladamente, mantendo iguais a
geometria inicial, a semente, a discretização, o relevo e os demais controles.

## Validação realizada

O teste em `Tests/lithology_regression.cpp` verifica:

1. campo uniforme `E=1` contra a baseline, com tolerância `1e-9`;
2. alteração da trajetória em campo heterogêneo;
3. ausência de `NaN` nos pontos do canal.

Para reproduzir a comparação textual completa entre versões, no clone original
é possível executar:

```sh
git diff f5a8ef3..b94d098 -- Code README.md Tests
```

O commit `f5a8ef3` representa a baseline original e `b94d098` representa a
versão da extensão antes da importação para o repositório principal.
