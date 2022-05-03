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
TTF_Font *gflappy = NULL;
TTF_Font *gaerobusdotty = NULL;
TTF_Font *gPacifico = NULL;

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
SDL_Texture* gSelect_image = NULL;
SDL_Texture* gTexture_freeze = NULL;
SDL_Texture* gTexture_cannon = NULL;


SDL_Texture* gTexture_fire_button = NULL;
SDL_Texture* gTexture_wall_button = NULL;
SDL_Texture* gTexture_acid_button = NULL;
SDL_Texture* gTexture_emp_button = NULL;
SDL_Texture* gTexture_shield_button = NULL;
SDL_Texture* gTexture_freeze_button = NULL;


SDL_Texture* gTexture_instructions_text = NULL; 
SDL_Texture* gTexture_powers_text = NULL; 


SDL_Texture* gTextTexture = NULL;



//The music that will be played
Mix_Music *gMusic = NULL;
Mix_Music *gPlay_Music = NULL;

//The sound effects that will be used
Mix_Chunk *gbegin_sound = NULL;
Mix_Chunk *gSelect_sound = NULL;
Mix_Chunk *gVictory_sound = NULL;
Mix_Chunk *gLow = NULL;
