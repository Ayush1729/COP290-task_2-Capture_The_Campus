class Powers_State{
	
	public:
		Powers_State(){
			//constructor; not necessary
		}

        float Current_view_y = 0;
        float Current_view_speed = 20;

        bool finished = false;
        float finished_time = 3;


		void update(float dt, int other_player_quit){
			SDL_Event e;
        	while((SDL_PollEvent( &e ) != 0 ) and (other_player_quit != 1)){
                if( e.type == SDL_QUIT ){
                    quit = true;
                }else if( e.type == SDL_KEYDOWN ){
                    //Select surfaces based on key press
                    switch( e.key.keysym.sym ){

                        case SDLK_KP_ENTER:
                        gState= "Play";
                        Mix_HaltMusic();
                        Mix_PlayChannel( -1, gbegin_sound, 0 );
                        Mix_PlayMusic( gPlay_Music, -1 );
                        Current_view_y = 0;
                        break;

                        case SDLK_RETURN:
                        gState = "Play";
                        Mix_HaltMusic();
                        Mix_PlayChannel( -1, gbegin_sound, 0 );
                        Mix_PlayMusic( gPlay_Music, -1 );
                        Current_view_y = 0;
                        break;

                        case SDLK_ESCAPE:
                        quit = true;
                        break;
                    }
                }
            }



            //Clear screen
            SDL_RenderClear( gRenderer );

            //Render texture to screen
            SDL_RenderCopy( gRenderer, gTexture2, NULL, NULL );


            SDL_Rect text_pos;
            text_pos.w = (SCREEN_WIDTH*0.90)*SCALING_FACTOR_X;
            text_pos.h = (SCREEN_HEIGHT*0.84)*SCALING_FACTOR_Y;
            text_pos.x = (SCREEN_WIDTH*0.05)*SCALING_FACTOR_X;
            text_pos.y = (SCREEN_HEIGHT*0.05)*SCALING_FACTOR_Y;


            //Get mouse position for text scrolling
            int mouse_x, mouse_y;
            SDL_GetMouseState( &mouse_x, &mouse_y );
            if (mouse_y < (SCREEN_HEIGHT*0.1)*SCALING_FACTOR_Y){
                Current_view_y = max(Current_view_y - Current_view_speed, float(0));
            }else if(mouse_y > ((SCREEN_HEIGHT*0.8)*SCALING_FACTOR_Y)){
                Current_view_y = min(Current_view_y + Current_view_speed, float(7589));
            }

            SDL_Rect text_view_rect;

            text_view_rect.w = 3559;
            text_view_rect.h = 2224;
            text_view_rect.x = 0;
            text_view_rect.y = Current_view_y;


            SDL_RenderCopy( gRenderer, gTexture_powers_text, &text_view_rect, &text_pos );




            //Render text
            SDL_Color textColor = { 200, 200, 0 };
            if( !loadFromRenderedText("Press 'Enter' to continue", textColor, gflappy)) {
                std::cout<<"Failed to render text texture!"<<std::endl;
                error_occ = true;
            }


            SDL_Rect titl_pos;
            titl_pos.w = (0.390625*SCREEN_WIDTH)*(SCALING_FACTOR_X);
            titl_pos.h = (0.07*SCREEN_HEIGHT)*(SCALING_FACTOR_Y);
            titl_pos.x = (0.3125*SCREEN_WIDTH)*(SCALING_FACTOR_X);
            titl_pos.y = (0.91*SCREEN_HEIGHT)*(SCALING_FACTOR_Y);
            // Text on screen
            SDL_RenderCopy( gRenderer, gTextTexture, NULL, &titl_pos );





            // In case the other player quits the game in between wait for three seconds and then close the program here as well after displaying the message of quit 
            if (other_player_quit == 1){finished = true;}

            if (finished){
                if (finished_time > 0){
                    finished_time-=dt;

                    // Background rectangle for the quit message
                    SDL_Rect fillRect = { (0.25*SCREEN_WIDTH)*(SCALING_FACTOR_X), (0.4*SCREEN_HEIGHT)*(SCALING_FACTOR_Y), (0.5*SCREEN_WIDTH)*(SCALING_FACTOR_X), (0.2*SCREEN_HEIGHT)*(SCALING_FACTOR_Y) };
                    SDL_SetRenderDrawColor( gRenderer, 125, 125, 125, 200 );
                    SDL_RenderFillRect( gRenderer, &fillRect );



                    SDL_Color textColor = { 255, 0, 0 };
                    if( !loadFromRenderedText("Your opponent has disconnected!", textColor, gPacifico)) {
                        std::cout<<"Failed to render text texture!"<<std::endl;
                        error_occ = true;
                    }
                    
                    SDL_Rect titl_pos;
                    titl_pos.w = (0.45*SCREEN_WIDTH)*(SCALING_FACTOR_X);
                    titl_pos.h = (0.15*SCREEN_HEIGHT)*(SCALING_FACTOR_Y);
                    titl_pos.x = (0.275*SCREEN_WIDTH)*(SCALING_FACTOR_X);
                    titl_pos.y = (0.425*SCREEN_HEIGHT)*(SCALING_FACTOR_Y);
                    // Text on screen
                    SDL_RenderCopy( gRenderer, gTextTexture, NULL, &titl_pos );

                }else{
                    quit = true;
                }
            }



            //Update screen
            SDL_RenderPresent( gRenderer );

            
		}
};


