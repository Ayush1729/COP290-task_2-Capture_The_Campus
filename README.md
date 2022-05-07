# Capture The Campus
## COP290 Task-2

### About the game
This is a 2-player game that.....
To know more about the game, refer to Game_Info.pdf file.

### Setting up SDL environment
Before running the game, first set up the required SDL environment and install the below mentioned libraries and packages.  
**NOTE:** The below mentioned steps and commands are for *linux based operating systems.*

- Installing the development package of SDL2
```
sudo apt-get install libsdl2-dev

```

- Installing various SDL extension libraries

   SDL extension libraries allow you do things like load image files besides BMP, render TTF fonts, play music, connect to other players and lot more. Install the below mentioned extension libraries to be able to play the game:

   - Insalling the development version of SDL_image library
   ```
   sudo apt-get install libsdl2-image-dev
   ```

   - Installing the development version of SDL_ttf library
   ```
   sudo apt-get install libsdl2-ttf-dev
   ```

   - Installing the development version of SDL_mixer library
   ```
   sudo apt-get install libsdl2-mixer-dev
   ```

   - Installing the development version of SDL_net library 
    ```
    sudo apt-get install libsdl2-net-dev
    ```

### How to run the game
The game files consists of two main CPP files. One of the server (Player 1) and one of the client (Player 2). 

To run the server side, go to the current directory of cloned git repo and run
```
cd ./src
make server
./server.out
```

To connect the client side and start the multiplayer game, run the below mentioned code snippet
```
make client
./client.out
```

You should now see the game start screen on both server and client side. Enjoy the game!!


### Authors
Ayush Meena 2019EE10468   
Garv Kumar 2019EE10477

### References
- https://wiki.libsdl.org/FrontPage
- https://lazyfoo.net/tutorials/SDL/index.php
- http://www.sdltutorials.com
- https://www.libsdl.org/projects/SDL_net/docs/index.html
- http://www.sdltutorials.com/sdl-net-part-1-user-tutorial

