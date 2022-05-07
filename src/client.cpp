#include "Dependencies.hpp"




bool init(){
    // initialize SDL
	if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 )
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


                //Initialize SDL_ttf
                if( TTF_Init() == -1 )
                {
                    std::cout<<"SDL_ttf could not initialize! SDL_ttf Error: "<<TTF_GetError()<<std::endl;
                    error_occ = true;
                }

                //Initialize SDL_mixer
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    std::cout<<"SDL_mixer could not initialize! SDL_mixer Error: "<< Mix_GetError()<< endl;
                    error_occ = true;
                }


            }
        }
	}

	return error_occ;
}




void close()
{

    //Free loaded image
    SDL_DestroyTexture( gTexture );
    gTexture = NULL;

    SDL_DestroyTexture( gTexture2 );
    gTexture2 = NULL;

    SDL_DestroyTexture( gTexture4 );
    gTexture4 = NULL;

    SDL_DestroyTexture( gTexture5 );
    gTexture5 = NULL;

    SDL_DestroyTexture( gTexture_emp );
    gTexture_emp = NULL;

    SDL_DestroyTexture( gTexture_shield );
    gTexture_shield = NULL;

    SDL_DestroyTexture( gTexture_blue_acid );
    gTexture_blue_acid = NULL;

    SDL_DestroyTexture( gTexture_blue_fire );
    gTexture_blue_fire = NULL;

    SDL_DestroyTexture( gTexture_blue_wall );
    gTexture_blue_wall = NULL;

    SDL_DestroyTexture( gTexture_freeze );
    gTexture_freeze = NULL;

    SDL_DestroyTexture( gSelect_image );
    gSelect_image = NULL;


    SDL_DestroyTexture( gTexture_fire_button );
    gTexture_fire_button = NULL;

    SDL_DestroyTexture( gTexture_wall_button );
    gTexture_wall_button = NULL;

    SDL_DestroyTexture( gTexture_acid_button );
    gTexture_acid_button = NULL;

    SDL_DestroyTexture( gTexture_emp_button );
    gTexture_emp_button = NULL;

    SDL_DestroyTexture( gTexture_shield_button );
    gTexture_shield_button = NULL;

    SDL_DestroyTexture( gTexture_freeze_button );
    gTexture_freeze_button = NULL;






    SDL_DestroyTexture(gTexture_instructions_text);
    gTexture_instructions_text = NULL;

    SDL_DestroyTexture(gTexture_powers_text);
    gTexture_powers_text = NULL;

    


    //Free loaded images
    SDL_DestroyTexture( gTextTexture );
    gTextTexture = NULL;

    //Free gflappy font
    TTF_CloseFont( gflappy );
    gflappy = NULL;

    //Free gaerobusdotty font
    TTF_CloseFont( gaerobusdotty );
    gaerobusdotty = NULL;

    TTF_CloseFont( gPacifico );
    gPacifico = NULL;

    





    //Free the sound effects
    Mix_FreeChunk( gbegin_sound );
    Mix_FreeChunk( gSelect_sound );
    Mix_FreeChunk( gVictory_sound );

    gbegin_sound = NULL;
    gSelect_sound = NULL;
    gVictory_sound = NULL;


    Mix_FreeChunk(gShield_sound);
    Mix_FreeChunk(gEMP_sound);
    Mix_FreeChunk(gFreeze_sound);
    Mix_FreeChunk(gAcid_sound);
    Mix_FreeChunk(gFire_sound);
    Mix_FreeChunk(gWall_sound);
    Mix_FreeChunk(gCannon_sound);
    Mix_FreeChunk(gSoldier_start_sound);
    Mix_FreeChunk(gSoldier_attack_sound);

    gShield_sound = NULL;
    gEMP_sound = NULL;
    gFreeze_sound = NULL;
    gAcid_sound = NULL;
    gFire_sound = NULL;
    gWall_sound = NULL;
    gCannon_sound = NULL;
    gSoldier_start_sound = NULL;
    gSoldier_attack_sound = NULL;



    
    //Free the music
    Mix_FreeMusic( gMusic );
    Mix_FreeMusic(gPlay_Music);
    gMusic = NULL;
    gPlay_Music = NULL;




    //Destroy window    
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}



int main( int argc, char* args[] )
{
    //Start up SDL and create window
    
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
            Start_State* start_state = new Start_State();
            Options_State* options_state = new Options_State();
            Play_State* play_state = new Play_State();
            Powers_State* powers_state = new Powers_State();
            GameOver_State* gameover_state = new GameOver_State();

            my_loyalty = "Red";

            SDLNet_Init();
            IPaddress ip;
            SDLNet_ResolveHost(&ip,"127.0.0.1",1234);

            TCPsocket client=SDLNet_TCP_Open(&ip);

            float text2[11];
            float* check;
            // text[] = {state, clicked, isleft, isright, click_x, click_y, Current_view_x, Current_view_y, SCALING_FACTOR_X, SCALING_FACTOR_Y,isquit}
            float text[11] = {0,0,0,0,0,0,0,0,0,0,0};
            check = text;


            while (!quit){
                temp_time = SDL_GetTicks();
                dt = temp_time - previous_time;

                SDLNet_TCP_Send(client,check,sizeof(float)*11);
                SDLNet_TCP_Recv(client,text2,11*sizeof(float));


                if (dt>1000/60) {
                    int w; int h;
                    SDL_GetWindowSize(gWindow, &w, &h);
                    SCALING_FACTOR_X = w/SCREEN_WIDTH;
                    SCALING_FACTOR_Y = h/SCREEN_HEIGHT;
                    
                    if (gState == "Start"){
                        start_state->update(dt/1000, text2[10]);
                    }else if (gState == "Options"){
                        options_state->update(dt/1000, text2[10]);
                    }else if (gState == "Powers"){
                        powers_state->update(dt/1000, text2[10]);
                    }else if (gState == "Play"){
                        play_state->render();
                        play_state->update(dt/1000, text2);
                        float arr[11] = {1, play_state->clicked, play_state->isleft, play_state->isright, play_state->click_x, play_state->click_y, play_state->Current_view_x, play_state->Current_view_y, SCALING_FACTOR_X, SCALING_FACTOR_Y,play_state->isquit};
                        check = arr;
                    }else if (gState == "GameOver"){
                        float arr[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
                        check = arr;
                        gameover_state->update(dt/1000, text2[10]);
                    }
                    else{
                        quit = true;
                    }
                    previous_time = temp_time;
                    dt = 0;
                }                
            }

            float arr[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
            check = arr;


            SDLNet_TCP_Send(client,check,sizeof(float)*11);
            SDLNet_TCP_Recv(client,text2,11*sizeof(float));

            SDLNet_TCP_Close(client);
            SDLNet_Quit();
        }
    }

    //Free resources and close SDL
    close();

    return 0;
}


