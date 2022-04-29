#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_net.h>

using namespace std;

#include "Global.h"
#include "Planet.h"
#include "HomePlanet.h"
#include "PathPoint.h"
#include "SoldierPacket.h"
#include "CannonBall.h"
#include "States/DoublyLinkedList.h"
#include "load.h"


#include "States/Start_State.h"
#include "States/Options_State.h"
#include "States/Play_State.h"