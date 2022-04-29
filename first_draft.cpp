#include "Code_Files/Dependencies.hpp"


/*

What all to include in this main file:
>> load all images
>> load all sounds
>> load all fonts
>> set a common timer/clock
>> initialize game (set up screen)
>> set scaling factors for everything (= Window width/SCREEN_WIDTH  and similarly for height)
>> set permanent images/sounds (like background image and infinite loop music)
>> create statemachine
>> check for keypressed (should do it here????????????????????)
>> function to call the current state to update
>> diplay FPS
>> render basic all time images like background and call upon the state to render its specificies

*/




bool init(){
    // initialize SDL
	if( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		std::cout<<"SDL could not initialize! SDL_Error: " << SDL_GetError();
		error_occ = true;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "Capture The Campus", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
		if( gWindow == NULL )
		{
			std::cout<<"Window could not be created! SDL_Error: "<< SDL_GetError();
			error_occ = true;
		}
		else
		{

            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                std::cout<<"Renderer could not be created! SDL Error: "<< SDL_GetError();
                error_occ = true;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                /*int imgFlags = IMG_INIT_JPG|IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    std::cout<<"SDL_image could not initialize! SDL_image Error: "<< IMG_GetError() ;
                    error_occ = true;
                }*/


                //Initialize SDL_ttf
                if( TTF_Init() == -1 )
                {
                    std::cout<<"SDL_ttf could not initialize! SDL_ttf Error: "<<TTF_GetError()<<std::endl;
                    error_occ = true;
                }
            }
        }
	}

	return error_occ;
}


/*

SDL_Texture* loadTexture(char* path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path);
    if( loadedSurface == NULL )
    {
        std::cout<<"Unable to load image ! SDL_image Error: "<< IMG_GetError();
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            std::cout<<"Unable to create texture from! SDL Error: "<< SDL_GetError() ;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
        loadedSurface = NULL;
    }

    return newTexture;
}


bool loadFromRenderedText(std::string textureText, SDL_Color textColor )
{
    //Get rid of preexisting texture
    //free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
    if( textSurface == NULL )
    {
        std::cout<<"Unable to render text surface! SDL_ttf Error: "<<TTF_GetError()<<std::endl;
    }
    else
    {
        //Create texture from surface pixels
        gTextTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
        if( gTextTexture == NULL )
        {
            std::cout<<"Unable to create texture from rendered text! SDL Error: "<< SDL_GetError()<<std::endl;
        }
        /*else
        {
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }*/
/*
        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }
    
    //Return success
    return gTextTexture != NULL;
}


/*
bool loadMedia()
{

    //Load PNG texture
    gTexture =  loadTexture("Graphics/background.jpg");
    gTexture2 =  loadTexture("Graphics/wallpaper.jpg");
    gTexture3 = loadTexture("Graphics/wolf.png");
    gTexture4 =  loadTexture("Graphics/Title.png");
    gTexture5 =  loadTexture("Graphics/iitd-campus.png");
    gTexture_blue_fire =  loadTexture("Graphics/Blue_Fire.png");
    gTexture_blue_wall =  loadTexture("Graphics/Blue_Wall.jpg");
    gTexture_red_wall =  loadTexture("Graphics/Red_Wall.jpg");
    gTexture_red_fire =  loadTexture("Graphics/Red_Fire.png");
    gTexture_emp =  loadTexture("Graphics/Purple_Orb.png");
    gTexture_shield =  loadTexture("Graphics/Green_Orb.png");
    gTexture_blue_acid =  loadTexture("Graphics/Blue_Acid.png");
    gTexture_red_acid =  loadTexture("Graphics/Red_Acid.png");




    if( gTexture == NULL or gTexture2 == NULL or gTexture3 == NULL or gTexture4 == NULL or gTexture5 == NULL)
    {
        std::cout<<"Failed to load texture image!\n";
        error_occ = true;
    }


    //Open the font
    gFont = TTF_OpenFont( "16_true_type_fonts/lazy.ttf", 28 );
    if( gFont == NULL )
    {
        std::cout<<"Failed to load lazy font! SDL_ttf Error: "<< TTF_GetError()<<std::endl;
        error_occ = true;
    }
    else
    {
        //Render text
        SDL_Color textColor = { 0, 0, 0 };
        if( !loadFromRenderedText("The quick brown fox jumps over the lazy dog", textColor ) )
        {
            std::cout<<"Failed to render text texture!"<<std::endl;
            error_occ = true;
        }
    }



    return error_occ;    
}

*/


void close()
{

    //Free loaded image
    SDL_DestroyTexture( gTexture );
    gTexture = NULL;

    SDL_DestroyTexture( gTexture2 );
    gTexture2 = NULL;

    SDL_DestroyTexture( gTexture3 );
    gTexture3 = NULL;

    SDL_DestroyTexture( gTexture4 );
    gTexture4 = NULL;

    SDL_DestroyTexture( gTexture5 );
    gTexture5 = NULL;

    SDL_DestroyTexture( gTexture_emp );
    gTexture_emp = NULL;

    SDL_DestroyTexture( gTexture_shield );
    gTexture_shield = NULL;

    SDL_DestroyTexture( gTexture_red_acid );
    gTexture_red_acid = NULL;

    SDL_DestroyTexture( gTexture_red_fire );
    gTexture_red_fire = NULL;

    SDL_DestroyTexture( gTexture_red_wall );
    gTexture_red_wall = NULL;

    SDL_DestroyTexture( gTexture_blue_acid );
    gTexture_blue_acid = NULL;

    SDL_DestroyTexture( gTexture_blue_fire );
    gTexture_blue_fire = NULL;

    SDL_DestroyTexture( gTexture_blue_wall );
    gTexture_blue_wall = NULL;

    


    //Free loaded images
    SDL_DestroyTexture( gTextTexture );
    gTextTexture = NULL;

    //Free global font
    TTF_CloseFont( gFont );
    gFont = NULL;


    //Destroy window    
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}



int main( int argc, char* args[] )
{
    //Start up SDL and create window
    
    //int FPS=60;
    int previous_time = 0;
    float dt;
    int temp_time;

    if( init() ){
        std::cout<<"Failed to initialize!\n";
        SDL_Quit();
        return 0;
    }else{
        //Load media
        if(loadMedia()){
            std::cout<<"Failed to load media!\n";
        }else{

            //create all state objects
            Start_State start_state;
            Options_State options_state;
            Play_State play_state;

            /*map <string, State> gStateMachine;
            gStateMachine["Start"] = start_state;*/


            while (!quit){
                temp_time = SDL_GetTicks();
                dt = temp_time - previous_time;

                if (dt>1000/60) {
                    int w; int h;
                    SDL_GetWindowSize(gWindow, &w, &h);
                    SCALING_FACTOR_X = w/SCREEN_WIDTH;
                    SCALING_FACTOR_Y = h/SCREEN_HEIGHT;
                    
                    if (gState == "Start"){
                        start_state.update(dt/1000);
                        //start_state.render();
                    }else if (gState == "Options"){
                        options_state.update(dt/1000);
                    }else if (gState == "Play"){
                        play_state.update(dt/1000);
                        play_state.render();
                    }
                    else{
                        quit = true;
                    }
                    previous_time = temp_time;
                    dt = 0;
                }                
	        }
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}




























