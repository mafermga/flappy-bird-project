# flappy-bird-project

# Proyecto: Juego de Flappy Bird

## Descripción
Este proyecto consiste en la implementación del popular juego Flappy Bird desarrollado en C++ y utilizando la biblioteca SFML para la interfaz de usuario. El juego presenta un pájaro que el jugador controla para evitar obstáculos y acumular puntos.

## Estructura de proyecto
El proyecto cuenta con los siguientes componentes hasta el momento:

- **Assets**: Contiene las imágenes para generar los sprites, tanto del bird, como de los tubos, como de la base. Contiene una font, y contiene los sonidos que son utilizados para la banda sonora, para el clic al volar del bird, y para el sonido de colisión.
- **Diagrama UML**: Se realizó el diagrama UML que consiste en la documentación de la estructura del proyecto. El diagrama incluye las siguientes clases y relaciones:

    - **Clase Juego**: Controla el flujo del juego y maneja la puntuación, el pájaro y los tubos.
    - **Clase Bird**: Modela al pájaro con atributos como posición y vida, y métodos para saltar.
    - **Clase Habilidad**: Define las habilidades que puede tener el pájaro, como impulso.
    - **Clase Tubo**: Modela un tubo en el juego con atributos como posición, alto y ancho.
    - **Clase Parallax**: Con esta clase se tiene en gestion el movimiento de la base del juego, agregando una nueva cada que este sprite va terminando su recorrido en X de la pantalla, eliminandolo para que no haya lentitudes en el juego y sea eficiente.

## Funcionalidades Implementadas
Hasta el momento, se han implementado las ssiguientes funcionalidades:

- Movimiento horizontal de los tubos.
- Movimiento vertical del pájaro (simulando el vuelo ascendente y descendente mediante gravedad y clics).
- Renderizado del juego en la pantalla utilizando la biblioteca SFML
- Musica de fondo para cada clic de vuelo, banda sonora, sonido de colisión, pantalla de inicio antes de jugar.



## Integrantes del Equipo:
- [Juan Salvador Fierros Leal   23110169](#)
- [María Fernanda Murillo García    23110195](#)

Cada integrante del equipo contribuye con el desarrollo, diseño y documentación del proyecto.


