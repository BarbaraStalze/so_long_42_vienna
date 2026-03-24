*This project has been created as part of the 42 curriculum by bastalze.*

# so_long

## Description
so_long is a 2D game project developed as part of the 42 curriculum. The project focuses on creating a small, playable game using the MiniLibX graphical library, emphasizing window management, event handling, and memory management. The player navigates a character through a custom map, collecting items and reaching the exit.
The main challenges are the parsing of the map, rejecting invalid maps (implementing correct error handling) and working with the mlx library to create a window, put the tiles/sprites and handle events and hooks correctly.

## Instruction

### Running the game
To run the program you must have MiniLibX installed on your system: https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html (you might have to adjust the Makefile of the project to link correctly).
After cloning the repository, compile the program inside the root directroy:

         make
Run the game:

         ./so_long maps/map1.ber
You can use any .ber-file in the maps directory. (map1, map2, map3 and map4 are functional). The program can take any .ber-file as a map as long as it follows these rules:
- wall = 1, empty space = 0, player = P, exit = E and collectible = C
- the map must be rectangular and surrounded by walls
- there can be only one player, one exit and at least one collectible
- there must be a valid path
If you use a map that creates a game bigger than your screen height it is not playable. And if the map is bigger than your screen width you have to move the window manually.

### Gameplay
To move the character use the arrow keys. The goal of the game is for the chicke to eat all mice then and go "home". You can quit the game any time by pressing esc or clicking the cross in the top right corner.

## Resources

### References
- I used Asprite to create the pixelart
- https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
- https://www.geeksforgeeks.org/linux-unix/how-to-unzip-tgz-file-using-linux/
- https://www.youtube.com/watch?v=9eAPbNUQD1Y
- https://en.wikipedia.org/wiki/Flood_fill
- https://github.com/S-LucasSerrano/so_long/blob/main/game/open_images.c (for understanding mlx-functions)
- https://medium.com/@ahmadbilla07/understanding-mlx-init-in-minilibx-beginner-friendly-7272b7ac9181
- https://www.w3schools.com/c/c_functions_pointers.php
- https://codebrowser.dev/gtk/include/X11/keysymdef.h.html

### Peers
What would be 42 without the help of our peers? So thanks where thanks is due: Kian helped me debugging. Specifically with the last impossible error and memory leak with the help of strace and gemini (turned out I was accidentally closing a fd that mlx opened before destroying the display). Anton helped me with the hook logic and debugging. Stefan A. likewise gave his best to support me in debugging. Florian answered all my questions regarding the project. Arsella also came to my aid in times of desperation about that aforementioned impossible bug. David helped making the moving smoother in the first eval. Thank you all!

### AI Usage Statement
I mainly used Deepseek to understand concepts better and to understand errors. I also used GitHub Copilot to debugg.
