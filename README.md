# 3D Engine (not)

Using the capabilities of the minilibx library, my project partner and I implemented a basic engine based on raycasting
Project, a reference to Wolfenstein, Duke Nuken and Quake
The game can accept any valid card created by the user, and it looks like this:


## Technologies

1. C
2. Make

## Launch

1. Build a project using Makefile

   ```sh
   $ make
   ```

# Developer hell

In this project, a simple 2D game was implemented about a developer who is in a hurry to get down to work, but first he needs to solve a more important problem!
The entire visual part is fully supported by the minilibx library for C
The game can accept any valid card created by the user, and it looks like this:

   ```sh
   1111111111111111111111111111111111
   1000000000000000000000000000000001
   1010010100100000101001000000010101
   1010010010101010001001000000010101
   1W00000000000000000000000000000001
   1111111111111111111111111111111111
   ```

    "1" is a wall
    "0" is the play space
    "W, E, N or S" is the player (and the direction of his gaze: West, East, North, South) 


## Technologies

1. C
2. Make

## Launch

1. Build a project using Makefile

   ```sh
   $ make
   ```

2. Run the program with one argument (map), like this:

   ```sh
   $ ./cub3D maps/valud1.cub
   ```
   
3. Control

  - W             = UP
  - S             = DOWN
  - A             = LEFT
  - D             = RIGHT
  - Left Arrow    = ROTATE LEFT
  - Right Arrow   = ROTATE RIGHT
  - Mouse Move    = ROTATE
  

## Game

  <img src="./screen/game.gif" width="500" alt="game">
