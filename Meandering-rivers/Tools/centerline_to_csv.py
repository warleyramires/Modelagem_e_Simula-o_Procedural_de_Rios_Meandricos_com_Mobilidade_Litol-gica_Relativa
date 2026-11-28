#!/usr/bin/env python3
"""Convert the first GeoJSON LineString into normalized simulator points."""

import json
import sys


def line_coordinates(geometry):
    kind = geometry["type"]
    coordinates = geometry["coordinates"]
    if kind == "LineString":
        return coordinates
    if kind == "MultiLineString":
        return [point for segment in coordinates for point in segment]
    raise ValueError(f"unsupported geometry: {kind}")


def main():
    if len(sys.argv) != 4:
        print("uso: centerline_to_csv.py input.geojson output.csv domain_size", file=sys.stderr)
        return 2

    source, destination, domain_size = sys.argv[1], sys.argv[2], float(sys.argv[3])
    with open(source, encoding="utf-8") as handle:
        document = json.load(handle)

    feature = document["features"][0]
    points = line_coordinates(feature["geometry"])
    if len(points) < 4:
        raise ValueError("centerline must contain at least four points")

    xs = [point[0] for point in points]
    ys = [point[1] for point in points]
    min_x, max_x = min(xs), max(xs)
    min_y, max_y = min(ys), max(ys)
    span_x = max(max_x - min_x, 1.0)
    span_y = max(max_y - min_y, 1.0)

    with open(destination, "w", encoding="utf-8") as handle:
        handle.write("# normalized centerline; x,y; domain is 0..20000\n")
        for x, y, *_ in points:
            normalized_x = 1000.0 + (x - min_x) / span_x * (domain_size - 2000.0)
            normalized_y = 1000.0 + (y - min_y) / span_y * (domain_size - 2000.0)
            handle.write(f"{normalized_x:.9f},{normalized_y:.9f}\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
