# cub3D

This project is inspired by the game Wolfenstein 3D. The goal of the project is to create a simple graphic engine capable of rendering a 3D maze using the Raycasting technique.

This project was developed in colaboration with [teroVF](https://github.com/teroVF).

## Features

- 3D maze rendering using Raycasting.
- Wall textures support.
- Player movement with WASD keys.
- Player vision rotation with arrow keys.
- Map defined in a .cub file.

## Prerequisites

Before compiling and running the project, make sure you have the MiniLibX installed in project folder. For that, after cloning, it's necessary to extract the contents of the `minilibx-Linux.tgz` file, rename the folder with the name `mlx`, and copy and paste this in the folder `lib`.

## Compilation

To compile the project, run:
```shell
make
```
This will compile the source files and generate the `cub3D` executable.

## Execution
After compilation, you can run the game using the following command:

```shell
./cub3D <map>
```

Replace `<map>` with the path to the map file you want to use. The map file should have the `.cub` extension and follow the format specified in the project. Inside the `assets/maps` folder there are folders with some examples of valid and invalid maps.

## Map

The maze map is defined in a .cub file. Example:

```plaintext
NO path_to_north_texture
SO path_to_south_texture
WE path_to_west_texture
EA path_to_east_texture

F 220,100,0
C 15,15,15

111111
100001
101101
10N001
111111
```

- `NO`, `SO`, `WE`, `EA`: Paths to wall textures.
- `F`: Floor color in RGB format.
- `C`: Ceiling color in RGB format.
- The map is represented using the letters `0` (empty space) and `1` (wall), and the spawn point with the orientation `N`, `S`, `E` or `W`. The map must be surrounded by walls.

## Controls

- W: Move forward.
- S: Move backward.
- A: Move left.
- D: Move right.
- Arrow keys: Rotate player's vision.
- ESC: Exit game.

## Grade: 105/100