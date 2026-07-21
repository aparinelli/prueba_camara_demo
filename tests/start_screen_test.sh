#!/usr/bin/env bash
set -euo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
main_file="$root/src/main.cpp"
header_file="$root/src/ofApp.h"
app_file="$root/src/ofApp.cpp"
workflow_file="$root/.github/workflows/deploy.yml"
font_file="$root/bin/data/fonts/CaslonCPswash.otf"
secondary_font_file="$root/bin/data/fonts/Arial.ttf"
addons_file="$root/addons.make"

test -s "$font_file"
test -s "$secondary_font_file"

grep -Eq 'settings\.setSize\(1024,[[:space:]]*768\)' "$main_file"
! grep -Eq 'settings\.setSize\(1920,[[:space:]]*1080\)' "$main_file"

grep -Eq 'bool[[:space:]]+startScreenActive[[:space:]]*=[[:space:]]*true' "$header_file"
grep -Eq 'ofTrueTypeFont[[:space:]]+startTitleFont' "$header_file"
grep -Eq 'ofTrueTypeFont[[:space:]]+startPromptFont' "$header_file"
grep -Eq 'void[[:space:]]+configurarPantallaInicio\(\)' "$header_file"
grep -Eq 'void[[:space:]]+dibujarPantallaInicio\(\)' "$header_file"
! grep -Eq 'ofVideoGrabber|ofxCvHaarFinder|ofxSvg|ofShader|ofFbo|Spiral|Star' "$header_file"

grep -Eq 'CaslonCPswash\.otf' "$app_file"
grep -Eq 'Arial\.ttf' "$app_file"
grep -Eq 'startTitleFont\.load' "$app_file"
grep -Eq 'startPromptFont\.load' "$app_file"
grep -Eq 'void ofApp::dibujarPantallaInicio\(\)' "$app_file"
grep -Eq 'Prueba Camara|Prueba Cámara' "$app_file"
grep -Eq 'Apreta|Apretá' "$app_file"
grep -Eq 'para empezar' "$app_file"
grep -Eq 'pulse' "$app_file"
grep -Eq 'OF_KEY_RETURN|OF_KEY_ENTER' "$app_file"
grep -Eq 'startScreenActive[[:space:]]*=[[:space:]]*false' "$app_file"
grep -Eq 'APP_W[[:space:]]*=[[:space:]]*1024' "$app_file"
grep -Eq 'APP_H[[:space:]]*=[[:space:]]*768' "$app_file"
! grep -Eq 'path144|ofVideoGrabber|Haar|SVG_W|SVG_H|dibujarPatron|dibujarCaja|dibujarEstrellas|dibujarEspirales|dibujarHUD' "$app_file"

! grep -Eq '^ofx(OpenCv|Svg)$' "$addons_file"
grep -Eq 'branches:[[:space:]]*\[[[:space:]]*main[[:space:]]*\]' "$workflow_file"
! grep -Eq 'branches:[[:space:]]*\[[^]]*demo[^]]*\]' "$workflow_file"
