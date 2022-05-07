class Start_State{
	
	public:
		Start_State(){
            Mix_PlayMusic( gMusic, -1 );
		}


        bool finished = false;
        float finished_time = 3;


		void update(float dt, int other_player_quit){

			SDL_Event e;
        	while((SDL_PollEvent( &e ) != 0 ) and (other_player_quit != 1)){
                if( e.type == SDL_QUIT ){
                    quit = true;
                }else if( e.type == SDL_KEYDOWN ){
                    //Select actions based on key press
                    switch( e.key.keysym.sym ){

                        case SDLK_KP_ENTER:     //keypad side enter only
                        gState= "Options";
                        Mix_PlayChannel( -1, gSelect_sound, 0 );
                        break;

                        case SDLK_RETURN:   //main enter pressed
                        gState = "Options";
                        Mix_PlayChannel( -1, gSelect_sound, 0 );
                        break;

                        case SDLK_ESCAPE:
                        quit = true;
                        break;
                    }
                }
            }



            SDL_Rect title_pos;
            title_pos.w = (0.9375*SCREEN_WIDTH)*(SCALING_FACTOR_X);
            title_pos.h = (0.417*SCREEN_HEIGHT)*(SCALING_FACTOR_Y);
            title_pos.x = (0.039*SCREEN_WIDTH)*(SCALING_FACTOR_X);
            title_pos.y = (0.139*SCREEN_HEIGHT)*(SCALING_FACTOR_Y);


            //Clear screen
            SDL_RenderClear( gRenderer );

            //Render texture to screen
            SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
            SDL_RenderCopy( gRenderer, gTexture4, NULL, &title_pos );


            //Render text
            SDL_Color textColor = { 200, 200, 0 };
            if( !loadFromRenderedText("Press 'Enter' to Start", textColor, gflappy)) {
                std::cout<<"Failed to render text texture!"<<std::endl;
                error_occ = true;
            }
        
            // setting text position on screen
            SDL_Rect titl_pos;
            titl_pos.w = (0.390625*SCREEN_WIDTH)*(SCALING_FACTOR_X);
            titl_pos.h = (0.07*SCREEN_HEIGHT)*(SCALING_FACTOR_Y);
            titl_pos.x = (0.3125*SCREEN_WIDTH)*(SCALING_FACTOR_X);
            titl_pos.y = (0.764*SCREEN_HEIGHT)*(SCALING_FACTOR_Y);

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


