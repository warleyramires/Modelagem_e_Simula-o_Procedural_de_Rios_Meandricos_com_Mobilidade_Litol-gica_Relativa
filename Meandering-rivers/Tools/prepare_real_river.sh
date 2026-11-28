#!/usr/bin/env bash
set -euo pipefail

if [[ "$#" -ne 13 ]]; then
	cat >&2 <<'USAGE'
uso: prepare_real_river.sh DEM.tif CENTERLINE_VECTOR GEOLOGY_VECTOR GEOLOGY_FIELD \
  OUTPUT_DIR XMIN YMIN XMAX YMAX DEM_MIN DEM_MAX GEOLOGY_MIN GEOLOGY_MAX
USAGE
	exit 2
fi

DEM="$1"
CENTERLINE="$2"
GEOLOGY="$3"
GEOLOGY_FIELD="$4"
OUTPUT="$5"
XMIN="$6"
YMIN="$7"
XMAX="$8"
YMAX="$9"
DEM_MIN="${10}"
DEM_MAX="$11"
GEOLOGY_MIN="$12"
GEOLOGY_MAX="$13"

if [[ -z "$DEM_MAX" ]]; then
	echo "DEM_MIN e DEM_MAX são obrigatórios" >&2
	exit 2
fi

PIXEL_SIZE="${PIXEL_SIZE:-100}"
TARGET_SRS="${TARGET_SRS:-EPSG:31984}"
mkdir -p "$OUTPUT"

for command in gdalwarp gdal_translate gdal_rasterize ogr2ogr; do
	command -v "$command" >/dev/null || {
		echo "dependência ausente: $command" >&2
		exit 3
	}
done

gdalwarp -overwrite -t_srs "$TARGET_SRS" \
	-te "$XMIN" "$YMIN" "$XMAX" "$YMAX" \
	-tr "$PIXEL_SIZE" "$PIXEL_SIZE" -r bilinear -of GTiff \
	"$DEM" "$OUTPUT/terrain_raw.tif"

gdal_translate -ot Byte -scale "$DEM_MIN" "$DEM_MAX" 0 255 \
	"$OUTPUT/terrain_raw.tif" "$OUTPUT/terrain.png"

ogr2ogr -overwrite -f GeoJSON -t_srs "$TARGET_SRS" \
	"$OUTPUT/centerline.geojson" "$CENTERLINE"

gdal_rasterize -overwrite -a "$GEOLOGY_FIELD" \
	-te "$XMIN" "$YMIN" "$XMAX" "$YMAX" \
	-tr "$PIXEL_SIZE" "$PIXEL_SIZE" -a_nodata 0 -ot Float32 \
	"$GEOLOGY" "$OUTPUT/lithology_raw.tif"

gdal_translate -ot Byte -scale "$GEOLOGY_MIN" "$GEOLOGY_MAX" 0 255 \
	"$OUTPUT/lithology_raw.tif" "$OUTPUT/lithology.png"

python3 "$(dirname "$0")/centerline_to_csv.py" \
	"$OUTPUT/centerline.geojson" "$OUTPUT/centerline.csv" 20000

cat > "$OUTPUT/manifest.json" <<EOF
{
  "name": "rio_sao_francisco",
  "target_srs": "$TARGET_SRS",
  "pixel_size": $PIXEL_SIZE,
  "domain_size": 20000,
  "terrain_source": "$DEM",
  "centerline_source": "$CENTERLINE",
  "geology_source": "$GEOLOGY",
  "geology_field": "$GEOLOGY_FIELD",
  "dem_range": [$DEM_MIN, $DEM_MAX],
  "geology_range": [$GEOLOGY_MIN, $GEOLOGY_MAX],
  "lithology_encoding": "PNG 0..255 maps linearly to E 0.25..1.75"
}
EOF

echo "Pacote preparado em $OUTPUT"
