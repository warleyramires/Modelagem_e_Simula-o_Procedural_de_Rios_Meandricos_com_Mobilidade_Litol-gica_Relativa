# Cronograma de duas semanas

## Objetivo

Ampliar a validação da mobilidade litológica, comparar a baseline original com
a versão da equipe e preparar experimentos com terreno de referência real.

O limite de 5% será usado como critério de custo. Um overhead maior pode ser
aceito quando houver ganho geométrico ou maior realismo demonstrável; overhead
alto sem melhoria observável exige otimização ou revisão.

## Semana 1 — Testes, cenários e matriz de iterações

| Dia | Pedro | Alberto | Entrega |
| --- | --- | --- | --- |
| 1 | Definir métricas de custo e qualidade | Revisar cenários redundantes | Critério de 5% documentado |
| 2 | Separar teste `E=1`, resistente e erodível | Criar campos litológicos controlados | Testes de mobilidade independentes |
| 3 | Testar margem externa e inflexão | Testar limites, fallback e valores inválidos | Cobertura de amostragem |
| 4 | Integrar relevo e litologia | Criar zonas resistente/neutra/erodível | Cenário `relevo_litologia_1000` |
| 5 | Alinhar entradas original/modificado | Conferir métricas e repetições | Benchmark reproduzível |

Todos os cinco tipos de cenário serão executados com 500, 750, 1000 e 1500
passos. O cenário de avulsão dispara as duas avulsões em 70% do total: 350,
525, 700 e 1050 passos, respectivamente.

## Semana 2 — Dados, benchmark e documentação

| Dia | Pedro | Alberto | Entrega |
| --- | --- | --- | --- |
| 6 | Selecionar e documentar terreno de referência | Preparar entrada em `Resources` | Teste de carregamento |
| 7 | Definir campo litológico do cenário | Verificar alinhamento terreno/campo/canal | Execução neutra e litológica |
| 8 | Ampliar o benchmark | Executar e verificar os CSVs | Resultados ampliados |
| 9 | Analisar overhead versus qualidade | Comparar imagens e métricas | Relatório interpretado |
| 10 | Atualizar README e limitações | Reproduzir os testes em ambiente limpo | Documentação final |
| 11 | Revisão conjunta | Revisão conjunta | Cobertura e números conferidos |
| 12 | Registrar cronograma e histórico | Conferir estado do repositório | Entrega pronta para push |

O item de dados reais é executado com `Tools/prepare_real_river.sh`, que gera
o pacote `terrain.png`, `lithology.png`, `centerline.csv` e `manifest.json`.
O cenário `rio_real` entra no benchmark apenas quando
`REAL_RIVER_DATA_DIR` aponta para esse pacote.

## Casos de teste

- `E=1`: equivalência com a baseline em simulação curta.
- Material resistente: `E/E_médio < 1` reduz a migração.
- Material erodível: `E/E_médio > 1` aumenta a migração.
- Margem externa: consulta o lado externo da curva.
- Inflexão: consulta e combina os dois lados.
- Fora do domínio: usa mobilidade neutra sem gerar `NaN`.
- Relevo e litologia: verifica interação entre os dois campos em cada duração.
- Avulsão com litologia: verifica estabilidade durante mudança de trajetória.
- Terreno de referência real: verifica carregamento, execução e saída.
- Rio real: compara as duas implementações usando o mesmo DEM, centerline e
  campo litológico pré-processados.

## Commits planejados

```text
test: separar casos de mobilidade litologica
test: cobrir margem externa inflexao e limites
test: adicionar cenario de interacao entre relevo e litologia
test: alinhar entradas da baseline e da versao modificada
test: adicionar entrada de terreno real
test: adicionar campo litologico ao cenario real
benchmark: ampliar comparacao entre baseline e equipe
docs: analisar custo computacional e ganho geometrico
docs: registrar metodologia final e limitacoes
docs: adicionar cronograma de duas semanas
```

## Critério de conclusão

O trabalho estará pronto quando a baseline e a versão modificada forem
executáveis, os testes cobrirem casos distintos, `E=1` passar na regressão,
campos resistentes e erodíveis produzirem efeitos opostos, não houver valores
inválidos, o benchmark incluir o cenário de interação e houver ao menos um
experimento com terreno de referência real.
