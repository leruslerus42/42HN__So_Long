# So_Long
## GENERAL
A small 2D game that helped me to learn how to work with windows, colors, events and textures.

As a graphic design project, the program will create a game inside a window corresponding to the map that you used as input.

The goal the player should archieve is to collect all the coins on a map, before reaching the exit.
In the bonus version, the player will be chased from a computerized enemy player, that will try to reach you: the goal is to collect all the coins and reaching the exit before the enemy reaches you.

## RESULT 
<img width="999" alt="Screen Shot 2021-12-16 at 2 23 44 PM" src="https://user-images.githubusercontent.com/85942176/146380241-ed53aeb4-65fe-45f0-8076-2954b3b16647.png">


## COMPILATION

First you have to compile the Minilibx Library in the MLX folder, responsable for the graphic operations.
After, in order to launch the game, you can run the Makefile for the compilation process, either selecting:
- make: for playing in solo modus.
- make bonus: for playing against an computerized enemy.

Then in order to launch the the game select the ./so_long executable and the map.ber that you want to use:
for exmaple -> ./so_long ./maps/map.ber


## REQUIREMENTS

Example of a valid map (formatted as *.ber):

1111111111111  
10010000000C1  
1000011111001  
1P0011E000001  
1111111111111

The map must be closed/surrounded by walls, if not the program must return an error.
Map must have at least one exit, one collectible, and one starting position.
You don’t need to check if there’s a valid path in the map.
The map must be rectangular.

### MAP'S LEGENDA
- Wall -> 1
- Floor -> 0
- Collectable -> C
- Player -> P
- Exit -> P

### CONTROLS
- You move the Player by using W (up), A (left), S (down), D (right).
- You win if you get in the exit after collecting all the 'coins'
- You can end the game by pressing 'esc' or clicking the 'red cross' at the top left


## NORMINETTE

As all other C projects at the 42 school, the code has to written in accordance with the norm:
- only 25 lines per function
- only 5 functions per file
- the only predefined functions allowed for this project are: open, close, read, write, malloc, free, perror, strerror, exit plus all the functions of the math and miniLibx Library.




Enjoy ;-)
