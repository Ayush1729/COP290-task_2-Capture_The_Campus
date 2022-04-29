class Start_State{
	
	public:
		Start_State(){
			//constructor; not necessary
		}

		/*void render(){
			//
			int w; int h;
            SDL_GetWindowSize(gWindow, &w, &h);
            
            //SDL_GL_GetDrawableSize(gWindow, &w, &h);

            //Apply the image stretched
            SDL_Rect stretchRect;
            stretchRect.x = 0;
            stretchRect.y = 0;
            stretchRect.w = w;
            stretchRect.h = h;
            SDL_BlitScaled( gBackground, NULL, gScreenSurface, &stretchRect );

            //Update the surface
            SDL_UpdateWindowSurface( gWindow );
		}*/

		void update(float dt){
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
                        break;

                        case SDLK_RETURN:
                        //std::cout<<"main enter pressed"<<std::endl;
                        gState = "Options";
                        break;

                        case SDLK_ESCAPE:
                        quit = true;
                        break;
                    }
                }




                SDL_Rect title_pos;
                title_pos.w = 1100*(SCALING_FACTOR_X);
                title_pos.h = 220*(SCALING_FACTOR_Y);
                title_pos.x = 100*(SCALING_FACTOR_X);
                title_pos.y = 100*(SCALING_FACTOR_Y);


                //Clear screen
                SDL_RenderClear( gRenderer );
                //Render texture to screen
                SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
                SDL_RenderCopy( gRenderer, gTexture4, NULL, &title_pos );









                if( gFont == NULL ){
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


                SDL_Rect titl_pos;
                titl_pos.w = 1100*(SCALING_FACTOR_X);
                titl_pos.h = 220*(SCALING_FACTOR_Y);
                titl_pos.x = 100*(SCALING_FACTOR_X);
                titl_pos.y = 350*(SCALING_FACTOR_Y);
                // Text on screen
                SDL_RenderCopy( gRenderer, gTextTexture, NULL, &titl_pos );


                if( gFont != NULL ){
                    //Render text
                    SDL_Color textColor = { 0, 0, 0 };
                    if( !loadFromRenderedText("Victory", textColor ) )
                    {
                        std::cout<<"Failed to render text texture!"<<std::endl;
                        error_occ = true;
                    }
                }

                SDL_Rect tit_pos;
                tit_pos.w = 1100*(SCALING_FACTOR_X);
                tit_pos.h = 220*(SCALING_FACTOR_Y);
                tit_pos.x = 100*(SCALING_FACTOR_X);
                tit_pos.y = 600*(SCALING_FACTOR_Y);

                // Text on screen
                SDL_RenderCopy( gRenderer, gTextTexture, NULL, &tit_pos );


                //Update screen
                SDL_RenderPresent( gRenderer );

            }
		}
};


