class GameOver_State{
	
	public:
		GameOver_State(){
			//constructor; not necessary
		}


		void update(float dt){

/*
            //If there is no music playing
            if( Mix_PlayingMusic() == 0){
                //Play the music
                Mix_PlayMusic( gMusic, -1 );
            }
            */

            
			SDL_Event e;
        	while(SDL_PollEvent( &e ) != 0 ){
                if( e.type == SDL_QUIT ){
                    quit = true;
                }else if( e.type == SDL_KEYDOWN ){
                    //Select actions based on key press
                    switch( e.key.keysym.sym ){
                        case SDLK_KP_ENTER:
                        //std::cout<<"keypad side enter only"<<std::endl;
                        gState= "Options";
                        Mix_PlayChannel( -1, gSelect_sound, 0 );
                        break;

                        case SDLK_RETURN:
                        //std::cout<<"main enter pressed"<<std::endl;
                        gState = "Options";
                        Mix_PlayChannel( -1, gSelect_sound, 0 );
                        break;

                        case SDLK_ESCAPE:
                        quit = true;
                        break;
                    }
                }



/*
                SDL_Rect title_pos;
                title_pos.w = (0.9375*SCREEN_WIDTH)*(SCALING_FACTOR_X);
                title_pos.h = (0.417*SCREEN_HEIGHT)*(SCALING_FACTOR_Y);
                title_pos.x = (0.039*SCREEN_WIDTH)*(SCALING_FACTOR_X);
                title_pos.y = (0.139*SCREEN_HEIGHT)*(SCALING_FACTOR_Y);
*/

                //Clear screen
                SDL_RenderClear( gRenderer );
                //Render texture to screen
                SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
                //SDL_RenderCopy( gRenderer, gTexture4, NULL, &title_pos );








                //Render text
                SDL_Color textColor = { 200, 200, 0 };
                if( !loadFromRenderedText("Press 'Enter' to play again", textColor, gflappy)) {
                    std::cout<<"Failed to render text texture!"<<std::endl;
                    error_occ = true;
                }
            

                SDL_Rect titl_pos;
                titl_pos.w = (0.465625*SCREEN_WIDTH)*(SCALING_FACTOR_X);
                titl_pos.h = (0.07*SCREEN_HEIGHT)*(SCALING_FACTOR_Y);
                titl_pos.x = (0.275*SCREEN_WIDTH)*(SCALING_FACTOR_X);
                titl_pos.y = (0.364*SCREEN_HEIGHT)*(SCALING_FACTOR_Y);
                // Text on screen
                SDL_RenderCopy( gRenderer, gTextTexture, NULL, &titl_pos );


                //Render text
                if( !loadFromRenderedText("Press 'Escape' to quit", textColor, gflappy)) {
                    std::cout<<"Failed to render text texture!"<<std::endl;
                    error_occ = true;
                }
            

                titl_pos;
                titl_pos.w = (0.390625*SCREEN_WIDTH)*(SCALING_FACTOR_X);
                titl_pos.h = (0.07*SCREEN_HEIGHT)*(SCALING_FACTOR_Y);
                titl_pos.x = (0.3125*SCREEN_WIDTH)*(SCALING_FACTOR_X);
                titl_pos.y = (0.564*SCREEN_HEIGHT)*(SCALING_FACTOR_Y);
                // Text on screen
                SDL_RenderCopy( gRenderer, gTextTexture, NULL, &titl_pos );



                //Update screen
                SDL_RenderPresent( gRenderer );

            }
		}
};


