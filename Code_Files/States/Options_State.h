class Options_State{
	
	public:
		Options_State(){
			//constructor; not necessary
		}

        float Current_view_y = 0;
        float Current_view_speed = 10;


		void update(float dt){

            
			SDL_Event e;
        	while(SDL_PollEvent( &e ) != 0 ){
                if( e.type == SDL_QUIT ){
                    quit = true;
                }else if( e.type == SDL_KEYDOWN ){
                    //Select surfaces based on key press
                    switch( e.key.keysym.sym ){
                        case SDLK_KP_ENTER:
                        //std::cout<<"keypad side enter only"<<std::endl;
                        gState= "Powers";
                        Mix_PlayChannel( -1, gSelect_sound, 0 );
                        Current_view_y = 0;
                        break;

                        case SDLK_RETURN:
                        //std::cout<<"main enter pressed"<<std::endl;
                        gState = "Powers";
                        Mix_PlayChannel( -1, gSelect_sound, 0 );
                        Current_view_y = 0;
                        break;

                        case SDLK_ESCAPE:
                        quit = true;
                        break;
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
                if (mouse_y < (SCREEN_HEIGHT*0.10)*SCALING_FACTOR_Y){
                    Current_view_y = max(Current_view_y - Current_view_speed, float(0));
                }else if(mouse_y > ((SCREEN_HEIGHT*0.84)*SCALING_FACTOR_Y)){
                    Current_view_y = min(Current_view_y + Current_view_speed, float(2816));
                }

                SDL_Rect text_view_rect;

                text_view_rect.w = 2048;
                text_view_rect.h = 1280;
                text_view_rect.x = 0;
                text_view_rect.y = Current_view_y;


                SDL_RenderCopy( gRenderer, gTexture_instructions_text, &text_view_rect, &text_pos );





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







                //Update screen
                SDL_RenderPresent( gRenderer );
                //options_state.render();

            }
		}
};


