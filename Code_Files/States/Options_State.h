class Options_State{
	
	public:
		Options_State(){
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
            SDL_BlitScaled( gWallpaper, NULL, gScreenSurface, &stretchRect );

            //Update the surface
            SDL_UpdateWindowSurface( gWindow );
		}*/

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
                        gState= "Play";
                        break;

                        case SDLK_RETURN:
                        //std::cout<<"main enter pressed"<<std::endl;
                        gState = "Play";
                        break;

                        case SDLK_ESCAPE:
                        quit = true;
                        break;
                    }
                }





                SDL_Rect image_pos;
                image_pos.w = 60;
                image_pos.h = 60;
                image_pos.x = 120;
                image_pos.y = 120;


                //Clear screen
                SDL_RenderClear( gRenderer );

                //Render texture to screen
                SDL_RenderCopy( gRenderer, gTexture2, NULL, NULL );
                SDL_RenderCopy( gRenderer, gTexture3, NULL, &image_pos );

                //Update screen
                SDL_RenderPresent( gRenderer );
                //options_state.render();

            }
		}
};


