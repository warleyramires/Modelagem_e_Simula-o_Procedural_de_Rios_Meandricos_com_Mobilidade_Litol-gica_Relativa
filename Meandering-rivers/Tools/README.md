# Preparação de dados geográficos

## Fontes recomendadas

Para o primeiro experimento, escolha um trecho meandrante do Rio São Francisco
na região Juazeiro–Petrolina e baixe:

1. a rede hidrográfica na ANA/SNIRH;
2. o MDE em GeoTIFF no IBGE;
3. o mapa geológico vetorial no GeoSGB/SGB.

Fontes oficiais:

- [ANA/SNIRH](https://www2.snirh.gov.br/portal/snirh)
- [MDE do IBGE](https://www.ibge.gov.br/geociencias/modelos-digitais-de-superficie/modelos-digitais-de-superficie/10856-.html)
- [downloads do GeoSGB](https://geosgb.sgb.gov.br/downloads/)
- [HydroSHEDS, alternativa global](https://www.hydrosheds.org/products)

O trecho deve ser um recorte espacial pequeno, com uma única linha de rio e
sem barragens ou bifurcações dentro da área escolhida. O MDE e o mapa
geológico precisam cobrir exatamente esse recorte.

## Conversão

O script exige GDAL (`gdalwarp`, `gdal_translate`, `gdal_rasterize` e
`ogr2ogr`) e recebe um atributo numérico no mapa geológico. Esse atributo é uma
proxy inicial para a litologia; ele não é automaticamente uma medida física de
erodibilidade.

Exemplo para o sistema SIRGAS 2000 / UTM 24S:

```sh
TARGET_SRS=EPSG:31984 PIXEL_SIZE=100 \
  ./Tools/prepare_real_river.sh \
  dem.tif rio.gpkg geologia.gpkg E \
  Resources/real_river \
  300000 8900000 340000 8940000 \
  300 600 0.0 1.0
```

Os limites devem estar no sistema projetado escolhido. `DEM_MIN` e `DEM_MAX`
são as altitudes usadas para converter o DEM em grayscale. `GEOLOGY_MIN` e
`GEOLOGY_MAX` são os limites do atributo geológico usado para gerar o campo
litológico.

O resultado contém:

```text
terrain.png       relevo normalizado para 0..2500
lithology.png     valor 0..255, convertido depois para E=0.25..1.75
centerline.csv    pontos x,y no domínio 0..20000
manifest.json     fontes, projeção, resolução e escalas
```

Antes de usar a litologia, registre no `manifest.json` como cada unidade
geológica foi convertida para `E`. Para uma avaliação física, essa tabela deve
ser calibrada com dados locais de granulometria, resistência ou erodibilidade.

## Execução comparável

Os dois algoritmos carregam os mesmos arquivos por meio da variável:

```sh
REAL_RIVER_DATA_DIR="$PWD/Resources/real_river" \
  BENCHMARK_REPETITIONS=3 ./Benchmarks/run_benchmark.sh
```

O resultado inclui `rio_real` com 500, 750, 1000 e 1500 passos. A baseline
ignora `lithology.png`; a versão modificada usa o mesmo campo para a variante
litológica.
