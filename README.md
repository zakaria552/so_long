# So long
## Overview
This project involves developing a small 2D game using a minimal graphics library to render sprites. The objective of the game is to collect all the collectibles scattered throughout the map while navigating with limited vision. As the player gathers more coins, their field of vision gradually expands. The player must avoid being detected by patrolling enemy, which will begin to chase the player if they get too close. Once all collectibles have been gathered, the player must reach the exit point to complete the game.

## Demo
https://github.com/user-attachments/assets/b6b54e2b-c655-4818-9410-fe6a584e87e8

## What I Learned
This was my first 2D game, and some of the interesting concepts I learned include sprite animation, vision effects, basic enemy AI, and pathfinding using DFS and BFS.

## Map format
```bash
1111111111111111
1101011100000011
1001001000000001
1000C00001100101
10001011X1100101
11101011C0000101
1100100000011101
1000011111000001
11P0C0000000C0E1
1111111111111111
```

- **Extension:** `.ber`  
- **1** – Wall  
- **0** – Floor  
- **P** – Player starting position  
- **E** – Exit  
- **C** – Collectible  
- **X** – Enemy  

> The map must be rectangular, fully surrounded by walls, and all collectibles and the exit must be accessible to the player.

## Run locally
Currently supporting **Unix-like systems**, including **Linux** and **macOS (ARM)**.
#### Clone the repository
```bash
git clone https://github.com/zakaria552/so_long.git && cd so_long
```
#### Build the project
```bash
make
```
#### Run the game with a map file
```bash
./so_long maps/<map_name>.ber
```
