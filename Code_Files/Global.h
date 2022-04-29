float SCREEN_WIDTH = 1280;
float SCREEN_HEIGHT = 720;
float SCALING_FACTOR_X = 1;
float SCALING_FACTOR_Y = 1;

bool error_occ = false;

bool quit = false;

string gState = "Start";

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;


//Globally used font
TTF_Font *gFont = NULL;

//Current displayed texture
SDL_Texture* gTexture = NULL;
SDL_Texture* gTexture2 = NULL;
SDL_Texture* gTexture3 = NULL;
SDL_Texture* gTexture4 = NULL;
SDL_Texture* gTexture5 = NULL;
SDL_Texture* gTexture_blue_fire = NULL;
SDL_Texture* gTexture_red_fire = NULL;
SDL_Texture* gTexture_blue_wall = NULL;
SDL_Texture* gTexture_red_wall = NULL;
SDL_Texture* gTexture_blue_acid = NULL;
SDL_Texture* gTexture_red_acid = NULL;
SDL_Texture* gTexture_emp = NULL;
SDL_Texture* gTexture_shield = NULL;


SDL_Texture* gTextTexture = NULL;