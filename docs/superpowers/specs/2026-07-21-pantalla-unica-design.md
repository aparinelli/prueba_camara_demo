# Pantalla Unica Design

## Objetivo

Convertir el proyecto en una pantalla unica de comienzo, eliminando la escena anterior de camara, SVG, patron, estrellas, espirales, HUD y controles.

## Requisitos

- Resolucion base: `1024x768`, igual que `/Users/alejoparinelli/facu/AM2/timber_parte_2/05_incremento_barra_tiempo`.
- Titulo: `Prueba Cámara`.
- Fuente del titulo: `bin/data/fonts/CaslonCPswash.otf`.
- Prompt: `Apretá [Enter] para empezar`.
- Fuente secundaria del prompt: `bin/data/fonts/Arial.ttf`.
- Animacion del prompt: `pulse`, un fade in/fade out ciclico.
- El repo original `aparinelli/prueba_camara` no despliega `demo` a su Pages anterior.
- La version nueva se publica en un sitio Pages separado.

## Diseno

`ofApp` queda reducido a cargar dos fuentes y dibujar la pantalla inicial escalada dentro de una superficie logica de `1024x768`. Enter solo cambia un flag visual interno; no hay segunda escena ni camara despues.

El workflow del repo original vuelve a escuchar solo `main`. La publicacion de esta version usa otro repo de Pages para evitar pisar `https://aparinelli.github.io/prueba_camara/`.

## Pruebas

`tests/start_screen_test.sh` verifica resolucion, fuentes, texto, animacion `pulse`, ausencia de la escena vieja y workflow sin `demo`. `tests/gh_pages_workflow_test.sh` conserva la cobertura del workflow.
