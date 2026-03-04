# Game Engine - README

## Brief

A simple **2D game engine** built from scratch in **C++** for learning purposes.  
This project helps me practice and deepen my understanding of C++ and game development concepts.

### Current Features

- **ECS (Entity Component System)** type architecture.
- **Tile-based rendering**: A small portion of the map is displayed using a tile set.
- **Player movement**: Control your character with **ZQSD** (WASD equivalent). No animations yet.
- **Collision detection**: Collision with the other character changes the player's size. Map collision not implemented yet.
- **Performance**: ~60 FPS, with FPS counter displayed in the console every second.

### Upcoming Features

- Full map implementation with collision detection.
- Map parsing from external files (currently hardcoded).
- Character animations.

## Getting Started

*NOTE : Will add more informations in later commits.*

### I. Prerequisites

- **C++ Compiler** (e.g., MSVC, GCC, Clang).
- **CMake 3.28+**.
- **SDL3**.

### II. Download & execute the project

#### Download project

- Run `git clone https://github.com/DaveIer/Game_Engine.git` in a terminal.  
**OR**
- Download the ZIP and unzip it.

#### Execute project with CMake

1. In the project folder, create a "build" folder.
2. Go to the "build" folder.
3. Run `cmake ..` to execute the `CMakeLists.txt`.
4. Run `cmake --build .` to build the executable.
5. Run `./Game_Engine` to run the executable.

### III. Download SDL3 libraries

Libraries needed : **SDL3** and **SDL3_image**. Github links :
- [SDL3](https://github.com/libsdl-org/SDL)
- [SDL3_image](https://github.com/libsdl-org/SDL_image)  

The same steps can be repeated for every library.

#### 1. Download source code 

- Run `git clone https://github.com/libsdl-org/SDL.git` in a terminal.  
**OR**
- Download the ZIP and unzip it.

#### 2. Building the library 

1. Go to the downloaded folder.
2. Create a "build" folder.
3. Go to the "build" folder.
4. Run `cmake ..` to execute the `CMakeLists.txt`.
5. Run `cmake --build .` to build the library.
6. Run `cmake --install .` to install it on your system.
7. You can now uninstall the whole downloaded folder.

## Contact

Author : David RODRIGUES  
E-mail : d.rodrigues.pro@proton.me
