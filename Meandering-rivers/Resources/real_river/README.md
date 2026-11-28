# Pacote de rio real

Este diretório recebe o pacote gerado por `Tools/prepare_real_river.sh`.
Arquivos esperados:

```text
terrain.png
lithology.png
centerline.csv
reference_centerline.csv (opcional)
manifest.json
```

O pacote não deve ser preenchido com um PNG sem procedência. Para o primeiro
experimento, use um trecho meandrante do Rio São Francisco:

- rede hidrográfica: ANA/SNIRH;
- elevação: MDE do IBGE;
- litologia: mapa geológico do SGB/GeoSGB.

O `manifest.json` deve registrar a fonte, a data, o sistema de coordenadas, a
resolução, a extensão e as regras usadas para converter litologia em `E`.

Depois de preparar o pacote, execute os benchmarks assim:

```sh
REAL_RIVER_DATA_DIR="$PWD/Resources/real_river" \
  BENCHMARK_REPETITIONS=3 ./Benchmarks/run_benchmark.sh
```

O benchmark executará o cenário `rio_real` na baseline original e nas duas
variantes modificadas usando os mesmos arquivos e pontos iniciais.

Se `reference_centerline.csv` existir, ele será tratado como o traçado
observado de referência no fim do intervalo. O relatório calculará o erro
médio entre o canal simulado e esse traçado. Sem esse arquivo, o benchmark
continua válido para comparar custo e divergência entre os algoritmos, mas não
afirma que a trajetória final reproduziu a evolução histórica do rio.
