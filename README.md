# CUB3D

## Project Navigation

This project, `cub3d-42`, implements a raycasting engine. The codebase is organized into several modules to ensure clarity and maintainability.

### Directory Structure

The primary directories you'll encounter are:

* **`inc/`**: This directory contains all **public header files** (`.h`). If you are looking for the function prototypes and data structures that define the interface of a module, this is the place to start.
* **`src/`**: This directory holds all **source code files** (`.c`) and **private header files** (usually suffixed with `_private.h`).
    * **`src/<module_name>/`**: Each logical module of the engine resides in its own subdirectory within `src/`. This is where the implementation details of each module are found.
    * **`src/main.c`**: This is the main entry point of the application. It orchestrates the initialization and execution of the game.

---
### Modules Overview

Here's a brief description of each module, its purpose, and typical file placement:

* **`assets`**
    * **Header**: `inc/assets.h`
    * **Source**: `src/assets/`
    * **Meaning**: Manages game assets, primarily textures. This includes loading textures from files and providing access to them for rendering.
    * **File Placement**: Functions for loading and managing texture data.

* **`camera`**
    * **Header**: `inc/camera.h`
    * **Source**: `src/camera/`
    * **Meaning**: Handles the player's viewpoint, including position, direction, and the camera plane used for raycasting calculations.
    * **File Placement**: Logic for camera transformations, player movement updates affecting the camera, and view matrix calculations.

* **`engine`**
    * **Header**: `inc/engine.h`
    * **Source**: `src/engine/`
    * **Meaning**: The heart of the game. It's responsible for initializing all game systems, running the main game loop, and cleaning up resources upon exit.
    * **File Placement**: The main game loop function, initialization routines for various modules, and resource deallocation functions.

* **`input`**
    * **Header**: `inc/input.h`
    * **Source**: `src/input/`
    * **Meaning**: Processes all user input, such as keyboard presses and mouse movements, to control the player and game state.
    * **File Placement**: Event handlers for keyboard and mouse events, functions to update game state based on input.

* **`raycaster`**
    * **Header**: `inc/raycaster.h`
    * **Source**: `src/raycaster/`
    * **Meaning**: Implements the core raycasting algorithm. This module calculates distances to walls and determines what is visible from the camera's perspective.
    * **File Placement**: Ray casting logic, Digital Differential Analysis (DDA) algorithm implementation, collision detection with walls, and calculation of wall heights for rendering.

* **`render`**
    * **Header**: `inc/render.h`
    * **Source**: `src/render/`
    * **Meaning**: Handles the actual drawing of the game world to the screen. This includes rendering walls, floor, ceiling, and potentially sprites or other visual elements based on the raycaster's output.
    * **File Placement**: Functions for drawing pixels to a buffer, applying textures to walls, and managing the frame buffer.

* **`utils`**
    * **Header**: `inc/utils.h`
    * **Source**: `src/utils/`
    * **Meaning**: Contains miscellaneous helper functions and utility tools used across different modules. This often includes MiniLibX (MLX) initialization, error handling, memory management wrappers, or mathematical helpers.
    * **File Placement**: General-purpose functions, MLX setup code, and any other shared utilities.

* **`world`**
    * **Header**: `inc/world.h`
    * **Source**: `src/world/`
    * **Meaning**: Manages the game map or level. This includes parsing the map file, storing the map data, and providing information about the game world to other modules.
    * **File Placement**: Map parsing logic, map data structures, and functions to query map properties (e.g., checking if a location is a wall).

---
### General Guidelines for Contribution

* **Public Interfaces**: Define all public functions and data structures in header files (`.h`) located in the `inc/` directory.
* **Implementations**: Place the corresponding source code files (`.c`) in the respective `src/<module_name>/` directory.
* **Private Details**: If a module requires internal helper functions or data structures that should not be exposed publicly, declare them in a private header file (e.g., `src/<module_name>/<module_name>_private.h`) or keep them static within the `.c` files.
* **Entry Point**: The `src/main.c` file should be kept concise, primarily responsible for initializing the engine and starting the main game loop.
