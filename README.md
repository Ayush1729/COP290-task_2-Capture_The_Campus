# Capture The Campus
## COP290 Task-2

### About the game


### Setting up SDL environment
Before cloning the git repo, first set up the required SDL environment and install the below mentioned libraries and packages

- Installing the the development package of SDL 2
```
sudo apt-get install libsdl2-dev

```

SDL extension libraries allow you do things like load image files besides BMP, render TTF fonts, and play music.

- Insalling the development version of SDL_image
```
sudo apt-get install libsdl2-image-dev
```

- Installing the development version of SDL_ttf
```
sudo apt-get install libsdl2-ttf-dev
```

- Installing the development version of SDL_mixer
```
sudo apt-get install libsdl2-mixer-dev
```

- Installing the development version of SDLNet for networking and socket programming
 ```
 sudo apt-get install libsdl2-net-dev
 ```

### How to run the game
The game files consists of two main cpp files. One of the server(Player 1) and one of the client(Player 2). 

To run the server side, go to the current directory of installed git repo and run
```
cd ./src
make server
```
And then
```
./server.out
```

To connect the client side and start the multiplayer game, run
```
make client
./client.out
```

You should now see the game start screen on both server and client side. Enjoy the game!!


### Authors
Ayush Meena 2019EE10468
Garv Kumar 2019EE10477

### References
- https://lazyfoo.net/tutorials/SDL/index.php
- 

