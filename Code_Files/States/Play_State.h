class Play_State{
    

	public:
		Play_State(){
			//constructor; not necessary
		}

        DoublyLinkedList all_soldiers;

        bool power_is_selected = false;
        string selected_power = "None";


        // initializing all planets
        Planet Hospital = Planet(1128, 515, "Hospital", "Shield"); 
        Planet LHC = Planet(2095,687, "LHC", "Freeze"); 
        Planet Library = Planet(1723,504, "Library", "Cannon"); 
        HomePlanet Blue_Home = HomePlanet("Blue", 798,258, "Vindhyachal"); 
        HomePlanet Red_Home = HomePlanet("Red",2309,222, "Himadri"); 
        Planet Jwala = Planet(409, 242, "Jwala", "None"); 
        Planet Kara = Planet(397, 570, "Kara", "None"); 
        Planet Apartments_boys = Planet(227, 808, "Apartments boys", "Fire Circle"); 
        Planet Apartments_girls = Planet(2627, 783, "Apartments girls", "Acid Circle"); 
        Planet Playground = Planet(1329, 747, "Playground", "Fast Move"); 
        Planet Research = Planet(1522, 990, "Research Park", "EMP"); 
        Planet Masala = Planet(877, 517, "Masala Mix", "Cannon"); 
        Planet Main_building = Planet(1674, 305, "Main Building", "Fast Spawn"); 
        Planet Market = Planet(2663, 486, "IITD Market", "None"); 
        Planet School = Planet(2305, 484, "Kendriya Vidyalaya", "None"); 
        Planet Amaltas = Planet(2666, 307, "Amaltas", "None"); 
        Planet OAT = Planet(823, 861, "OAT", "Road Block");
    

        Planet* selected_origin = NULL;
        Planet* selected_destination = NULL;


        CannonBall cannon1 = CannonBall(&Masala);
        CannonBall cannon2 = CannonBall(&Library);


        float Current_view_x = 0;
        float Current_view_y = 0;
        float Current_view_speed = 10;
        float CAMPUS_WIDTH = 3017;
        float CAMPUS_HEIGHT = 1187;


        void create_packet(int outgoing, Planet* selected_origin, Planet* selected_destination){
            //std::cout<<"create_packet"<<std::endl;
            SoldierPacket* temp = new SoldierPacket(outgoing, selected_destination, selected_origin);
            //std::cout<<"create_packet_mid"<<std::endl;
            all_soldiers.insert(temp);
            //std::cout<<"create_packet_end"<<std::endl;
            temp = NULL;
        }

		void render(){

            //Clear screen
            SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 255 );
            SDL_RenderClear( gRenderer );

            SDL_Rect campus_view_rect;
            campus_view_rect.w = SCREEN_WIDTH*(SCALING_FACTOR_X);
            campus_view_rect.h = SCREEN_HEIGHT*(SCALING_FACTOR_Y);
            campus_view_rect.x = Current_view_x*(SCALING_FACTOR_X);
            campus_view_rect.y = Current_view_y*(SCALING_FACTOR_Y);

            SDL_RenderCopy( gRenderer, gTexture5, &campus_view_rect, NULL );


            all_soldiers.render(Current_view_x, Current_view_y);


            LHC.render(Current_view_x, Current_view_y);
            Library.render(Current_view_x, Current_view_y);
            Blue_Home.render(Current_view_x, Current_view_y);
            Red_Home.render(Current_view_x, Current_view_y);
            OAT.render(Current_view_x, Current_view_y);
            Jwala.render(Current_view_x, Current_view_y);
            Kara.render(Current_view_x, Current_view_y);
            Apartments_boys.render(Current_view_x, Current_view_y);
            Masala.render(Current_view_x, Current_view_y);
            Hospital.render(Current_view_x, Current_view_y);
            Apartments_girls.render(Current_view_x, Current_view_y);
            School.render(Current_view_x, Current_view_y);
            Market.render(Current_view_x, Current_view_y);
            Amaltas.render(Current_view_x, Current_view_y);
            Research.render(Current_view_x, Current_view_y);
            Playground.render(Current_view_x, Current_view_y);
            Main_building.render(Current_view_x, Current_view_y);


            //Render black outlined quad
            if (selected_origin!=NULL){
                SDL_Rect outlineRect = { selected_origin->x - 20 - Current_view_x, selected_origin->y - 20 - Current_view_y, 40, 40 };
                SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 255 );        
                SDL_RenderDrawRect( gRenderer, &outlineRect );
            }










            // Power visuals

            // all powers of two colours for the two players
            SDL_Rect power_pos;

            if (Apartments_boys.power_stay_time>0){
                power_pos.w = Apartments_boys.radius*SCALING_FACTOR_X;
                power_pos.h = Apartments_boys.radius*SCALING_FACTOR_Y;
                power_pos.x = (Apartments_boys.power_circle_centre_x - (Apartments_boys.radius/2) - Current_view_x)*SCALING_FACTOR_X;
                power_pos.y = (Apartments_boys.power_circle_centre_y - (Apartments_boys.radius/2) - Current_view_y)*SCALING_FACTOR_Y;

                // setting up transparency
                SDL_SetTextureBlendMode( gTexture_blue_fire, SDL_BLENDMODE_BLEND );
                SDL_SetTextureAlphaMod( gTexture_blue_fire, 128 );

                if (Apartments_boys.loyalty == "Blue"){
                    //SDL_SetTextureColorMod( gTexture_blue_fire, 0, 0, 180 );
                    SDL_RenderCopy( gRenderer, gTexture_blue_fire , NULL, &power_pos );
                }
                else if (Apartments_boys.loyalty == "Red"){
                    SDL_SetTextureColorMod( gTexture_blue_fire, 180, 0, 0 );
                    SDL_RenderCopy( gRenderer, gTexture_blue_fire , NULL, &power_pos );
                }
            }

            if (Apartments_girls.power_stay_time>0){
                power_pos.w = Apartments_girls.radius*SCALING_FACTOR_X;
                power_pos.h = Apartments_girls.radius*SCALING_FACTOR_Y;
                power_pos.x = (Apartments_girls.power_circle_centre_x - (Apartments_girls.radius/2) - Current_view_x)*SCALING_FACTOR_X;
                power_pos.y = (Apartments_girls.power_circle_centre_y - (Apartments_girls.radius/2) - Current_view_y)*SCALING_FACTOR_Y;

                // setting up transparency
                SDL_SetTextureBlendMode( gTexture_blue_acid, SDL_BLENDMODE_BLEND );
                SDL_SetTextureAlphaMod( gTexture_blue_acid, 128 );

                if (Apartments_girls.loyalty == "Blue"){
                    SDL_SetTextureColorMod( gTexture_blue_acid, 0, 0, 180 );
                    SDL_RenderCopy( gRenderer, gTexture_blue_acid , NULL, &power_pos );
                }
                else if (Apartments_girls.loyalty == "Red"){
                    SDL_SetTextureColorMod( gTexture_blue_acid, 180, 0, 0 );
                    SDL_RenderCopy( gRenderer, gTexture_blue_acid , NULL, &power_pos );
                } 
            }

            if (Hospital.power_stay_time>0){
                power_pos.w = Hospital.radius*SCALING_FACTOR_X;
                power_pos.h = Hospital.radius*SCALING_FACTOR_Y;
                power_pos.x = (Hospital.power_circle_centre_x - (Hospital.radius/2) - Current_view_x)*SCALING_FACTOR_X;
                power_pos.y = (Hospital.power_circle_centre_y - (Hospital.radius/2) - Current_view_y)*SCALING_FACTOR_Y;

                // setting up transparency
                SDL_SetTextureBlendMode( gTexture_shield, SDL_BLENDMODE_BLEND );
                SDL_SetTextureAlphaMod( gTexture_shield, 128 );

                if (Hospital.loyalty == "Blue"){
                    SDL_RenderCopy( gRenderer, gTexture_shield , NULL, &power_pos );
                }
                else if (Hospital.loyalty == "Red"){
                    SDL_RenderCopy( gRenderer, gTexture_shield , NULL, &power_pos );
                } 
            }

            if (Research.power_stay_time>0){
                power_pos.w = Research.radius*SCALING_FACTOR_X;
                power_pos.h = Research.radius*SCALING_FACTOR_Y;
                power_pos.x = (Research.power_circle_centre_x - (Research.radius/2) - Current_view_x)*SCALING_FACTOR_X;
                power_pos.y = (Research.power_circle_centre_y - (Research.radius/2) - Current_view_y)*SCALING_FACTOR_Y;

                // setting up transparency
                SDL_SetTextureBlendMode( gTexture_emp, SDL_BLENDMODE_BLEND );
                SDL_SetTextureAlphaMod( gTexture_emp, 128 );

                if (Research.loyalty == "Blue"){
                    SDL_RenderCopy( gRenderer, gTexture_emp , NULL, &power_pos );
                }
                else if (Research.loyalty == "Red"){
                    SDL_RenderCopy( gRenderer, gTexture_emp , NULL, &power_pos );
                } 
            }

            if (OAT.power_stay_time>0){
                power_pos.w = OAT.radius*SCALING_FACTOR_X;
                power_pos.h = OAT.radius*SCALING_FACTOR_Y;
                power_pos.x = (OAT.power_circle_centre_x - (OAT.radius/2) - Current_view_x)*SCALING_FACTOR_X;
                power_pos.y = (OAT.power_circle_centre_y - (OAT.radius/2) - Current_view_y)*SCALING_FACTOR_Y;

                if (OAT.loyalty == "Blue"){
                    //SDL_SetTextureColorMod( gTexture_blue_wall, 0, 0, 180 );
                    SDL_RenderCopy( gRenderer, gTexture_blue_wall , NULL, &power_pos );
                }
                else if (OAT.loyalty == "Red"){
                    SDL_SetTextureColorMod( gTexture_blue_wall, 180, 0, 0 );
                    SDL_RenderCopy( gRenderer, gTexture_blue_wall, NULL, &power_pos );
                } 
            }



            if (LHC.power_stay_time>0){

                // setting up transparency
                //SDL_SetTextureBlendMode( gTexture_emp, SDL_BLENDMODE_BLEND );
                //SDL_SetTextureAlphaMod( gTexture_emp, 128 );

                if (LHC.loyalty == "Blue"){
                    // do nothing here for the blue player, but show for the red player
                    //SDL_RenderCopy( gRenderer, gTexture_emp , NULL, &power_pos );
                }
                else if (LHC.loyalty == "Red"){
                    // do nothing here for the red player, but show for the blue player
                    //SDL_RenderCopy( gRenderer, gTexture_emp , NULL, &power_pos );
                } 
            }


            if (cannon1.alive){ cannon1.render(Current_view_x, Current_view_y);}
            if (cannon2.alive){ cannon2.render(Current_view_x, Current_view_y);}

















            // the six buttons for the six powers

            // Fire Circle
            SDL_Rect fillRect = { ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*4.25/30))*SCALING_FACTOR_X, (27*SCREEN_HEIGHT/30)*SCALING_FACTOR_Y, (SCREEN_WIDTH/30)*SCALING_FACTOR_X, (SCREEN_HEIGHT/30)*SCALING_FACTOR_Y };
            if ((Apartments_boys.power_available) and (Apartments_boys.loyalty=="Blue")){
                SDL_SetRenderDrawColor( gRenderer, 80, 200, 125, 255 );
            }else{
                SDL_SetRenderDrawColor( gRenderer, 180, 0, 0, 255 );
            }
            
            SDL_RenderFillRect( gRenderer, &fillRect );

            // Shield
            fillRect = { ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*2.75/30))*SCALING_FACTOR_X, (27*SCREEN_HEIGHT/30)*SCALING_FACTOR_Y, (SCREEN_WIDTH/30)*SCALING_FACTOR_X, (SCREEN_HEIGHT/30)*SCALING_FACTOR_Y };
            if ((Hospital.power_available) and (Hospital.loyalty=="Blue")){
                SDL_SetRenderDrawColor( gRenderer, 80, 200, 125, 255 );
            }else{
                SDL_SetRenderDrawColor( gRenderer, 180, 0, 0, 255 );
            }
            SDL_RenderFillRect( gRenderer, &fillRect );

            // EMP
            fillRect = { ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*1.25/30))*SCALING_FACTOR_X, (27*SCREEN_HEIGHT/30)*SCALING_FACTOR_Y, (SCREEN_WIDTH/30)*SCALING_FACTOR_X, (SCREEN_HEIGHT/30)*SCALING_FACTOR_Y };
            if ((Research.power_available) and (Research.loyalty=="Blue")){
                SDL_SetRenderDrawColor( gRenderer, 80, 200, 125, 255 );
            }else{
                SDL_SetRenderDrawColor( gRenderer, 180, 0, 0, 255 );
            }
            SDL_RenderFillRect( gRenderer, &fillRect );

            // Road Block
            fillRect = { ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*0.25/30))*SCALING_FACTOR_X, (27*SCREEN_HEIGHT/30)*SCALING_FACTOR_Y, (SCREEN_WIDTH/30)*SCALING_FACTOR_X, (SCREEN_HEIGHT/30)*SCALING_FACTOR_Y };
            if ((OAT.power_available) and (OAT.loyalty=="Blue")){
                SDL_SetRenderDrawColor( gRenderer, 80, 200, 125, 255 );
            }else{
                SDL_SetRenderDrawColor( gRenderer, 180, 0, 0, 255 );
            }
            SDL_RenderFillRect( gRenderer, &fillRect );

            // Freeze
            fillRect = { ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*1.75/30))*SCALING_FACTOR_X, (27*SCREEN_HEIGHT/30)*SCALING_FACTOR_Y, (SCREEN_WIDTH/30)*SCALING_FACTOR_X, (SCREEN_HEIGHT/30)*SCALING_FACTOR_Y };
            if ((LHC.power_available) and (LHC.loyalty=="Blue")){
                SDL_SetRenderDrawColor( gRenderer, 80, 200, 125, 255 );
            }else{
                SDL_SetRenderDrawColor( gRenderer, 180, 0, 0, 255 );
            }
            SDL_RenderFillRect( gRenderer, &fillRect );

            // Acid Circle
            fillRect = { ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*3.25/30))*SCALING_FACTOR_X, (27*SCREEN_HEIGHT/30)*SCALING_FACTOR_Y, (SCREEN_WIDTH/30)*SCALING_FACTOR_X, (SCREEN_HEIGHT/30)*SCALING_FACTOR_Y };
            if ((Apartments_girls.power_available) and (Apartments_girls.loyalty=="Blue")){
                SDL_SetRenderDrawColor( gRenderer, 80, 200, 125, 255 );
            }else{
                SDL_SetRenderDrawColor( gRenderer, 180, 0, 0, 255 );
            }
            SDL_RenderFillRect( gRenderer, &fillRect );





            //Top right viewport

            SDL_Rect topRightViewport;
            topRightViewport.x = 3*(SCREEN_WIDTH/4)*(SCALING_FACTOR_X);
            topRightViewport.y = 0;
            topRightViewport.w = (SCREEN_WIDTH / 4)*(SCALING_FACTOR_X);
            topRightViewport.h = (SCREEN_HEIGHT / 4)*(SCALING_FACTOR_Y);
            SDL_RenderSetViewport( gRenderer, &topRightViewport );
            
            //Render texture to screen
            SDL_RenderCopy( gRenderer, gTexture5, NULL, NULL );

            //current screen in viewport
            SDL_Rect current_screen_Rect = {(Current_view_x/CAMPUS_WIDTH)*(SCREEN_WIDTH / 4)*(SCALING_FACTOR_X), (Current_view_y/CAMPUS_HEIGHT)*(SCREEN_HEIGHT / 4)*(SCALING_FACTOR_Y), (SCREEN_WIDTH/CAMPUS_WIDTH)*(SCREEN_WIDTH / 4)*(SCALING_FACTOR_X), (SCREEN_HEIGHT/CAMPUS_HEIGHT)*(SCREEN_HEIGHT / 4)*(SCALING_FACTOR_Y) };
            SDL_SetRenderDrawColor( gRenderer, 255, 0, 0, 255 );        
            SDL_RenderDrawRect( gRenderer, &current_screen_Rect );

            SDL_RenderSetViewport( gRenderer, NULL);

            SDL_Rect outlineRect = { 3*(SCREEN_WIDTH/4)*(SCALING_FACTOR_X), 0, (SCREEN_WIDTH / 4)*(SCALING_FACTOR_X), (SCREEN_HEIGHT / 4)*(SCALING_FACTOR_Y) };
            SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 255 );        
            SDL_RenderDrawRect( gRenderer, &outlineRect );

            //Update screen
            SDL_RenderPresent( gRenderer );

		}

















		void update(float dt){
            //std::cout<<"update"<<std::endl;
            //["None", "Cannon", "EMP", "Fire Circle", "Acid Circle", "Road Block", "Fast Spawn", "Fast Move", "Freeze", "Shield"]
 

            LHC.update(dt, &Research, &Hospital);
            Library.update(dt, &Research, &Hospital);
            Jwala.update(dt, &Research, &Hospital);
            Kara.update(dt, &Research, &Hospital);
            Apartments_boys.update(dt, &Research, &Hospital);
            Apartments_girls.update(dt, &Research, &Hospital);
            Amaltas.update(dt, &Research, &Hospital);
            Playground.update(dt, &Research, &Hospital);
            Research.update(dt, &Research, &Hospital);
            Hospital.update(dt, &Research, &Hospital);
            Masala.update(dt, &Research, &Hospital);
            Main_building.update(dt, &Research, &Hospital);
            Market.update(dt, &Research, &Hospital);
            School.update(dt, &Research, &Hospital);
            OAT.update(dt, &Research, &Hospital);


            Blue_Home.update(dt, Main_building.loyalty, &Research, &Hospital);
            Red_Home.update(dt, Main_building.loyalty, &Research, &Hospital);


            if (!(Blue_Home.is_alive() and Red_Home.is_alive())){
                gState = "Game_Over";
                // free / NULL all things
                return;
            }


            if (cannon1.alive){ cannon1.update();}
            if (cannon2.alive){ cannon2.update();}



            all_soldiers.update(dt, &Playground, &Apartments_boys, &Apartments_girls, &OAT, &Hospital, &LHC, &Masala, &Library, &cannon1, &cannon2);



            //Get mouse position
            int mouse_x, mouse_y;
            SDL_GetMouseState( &mouse_x, &mouse_y );
            if (mouse_x<(SCREEN_WIDTH/45)){
                Current_view_x = max(Current_view_x - Current_view_speed, float(0));
            }else if(mouse_x>((SCREEN_WIDTH/45)*44)){
                Current_view_x = min(Current_view_x + Current_view_speed, CAMPUS_WIDTH - SCREEN_WIDTH);
            }
            if (mouse_y<(SCREEN_HEIGHT/30)){
                Current_view_y = max(Current_view_y - Current_view_speed,float(0));
            }else if(mouse_y>((SCREEN_HEIGHT/30)*29)){
                Current_view_y = min(Current_view_y + Current_view_speed, CAMPUS_HEIGHT - SCREEN_HEIGHT);
            }

			SDL_Event e;
        	while(SDL_PollEvent( &e ) != 0 ){
                if( e.type == SDL_QUIT ){
                    quit = true;
                }else if( e.type == SDL_KEYDOWN ){
                    //Select surfaces based on key press
                    switch( e.key.keysym.sym ){

                        case SDLK_ESCAPE:
                        quit = true;
                        break;
                    }
                }else if ((e.type == SDL_MOUSEBUTTONDOWN) and !((LHC.power_stay_time > 0) and (LHC.loyalty == "Red"))){

                    int click_x = e.button.x;// absolute pixels from left side, do not get scaled automatically
                    int click_y = e.button.y;

                    switch (e.button.button){
                        case SDL_BUTTON_LEFT:

                            // the six power buttons
                            std::cout<<"x = "<<click_x + Current_view_x<<"          y = "<<click_y + Current_view_y<<std::endl;
                            if ((click_x > ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*4.25/30))*SCALING_FACTOR_X) and (click_x < ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*3.25/30))*SCALING_FACTOR_X) and (click_y < (SCREEN_HEIGHT*28/30)*SCALING_FACTOR_Y) and (click_y > (SCREEN_HEIGHT*27/30)*SCALING_FACTOR_Y)) {
                                // selected powerup 1 Fire Circle
                                if (Apartments_boys.power_available){
                                    selected_origin = NULL;
                                    if (power_is_selected){
                                        if (selected_power == "Fire Circle"){
                                            power_is_selected = false;
                                        }else{
                                            selected_power = "Fire Circle";
                                        }
                                    }else{
                                        power_is_selected = true;
                                        selected_power = "Fire Circle";
                                    }
                                }

                            }else if ((click_x > ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*2.75/30))*SCALING_FACTOR_X) and (click_x < ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*1.75/30))*SCALING_FACTOR_X) and (click_y < (SCREEN_HEIGHT*28/30)*SCALING_FACTOR_Y) and (click_y > (SCREEN_HEIGHT*27/30)*SCALING_FACTOR_Y)) {
                                //selected powerup 2 Shield
                                if (Hospital.power_available){
                                    selected_origin = NULL;
                                    if (power_is_selected){
                                        if (selected_power == "Shield"){
                                            power_is_selected = false;
                                        }else{
                                            selected_power = "Shield";
                                        }
                                    }else{
                                        power_is_selected = true;
                                        selected_power = "Shield";
                                    }
                                }

                            }else if ((click_x > ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*1.25/30))*SCALING_FACTOR_X) and (click_x < ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*0.25/30))*SCALING_FACTOR_X) and (click_y < (SCREEN_HEIGHT*28/30)*SCALING_FACTOR_Y) and (click_y > (SCREEN_HEIGHT*27/30)*SCALING_FACTOR_Y)) {
                                //selected powerup 3 EMP
                                if (Research.power_available){
                                    selected_origin = NULL;
                                    if (power_is_selected){
                                        if (selected_power == "EMP"){
                                            power_is_selected = false;
                                        }else{
                                            selected_power = "EMP";
                                        }
                                    }else{
                                        power_is_selected = true;
                                        selected_power = "EMP";
                                    }
                                }

                            }else if ((click_x > ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*0.25/30))*SCALING_FACTOR_X) and (click_x < ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*1.25/30))*SCALING_FACTOR_X) and (click_y < (SCREEN_HEIGHT*28/30)*SCALING_FACTOR_Y) and (click_y > (SCREEN_HEIGHT*27/30)*SCALING_FACTOR_Y)) {
                                //selected powerup 4 Road Block
                                if (OAT.power_available){
                                    selected_origin = NULL;
                                    if (power_is_selected){
                                        if (selected_power == "Road Block"){
                                            power_is_selected = false;
                                        }else{
                                            selected_power = "Road Block";
                                        }
                                    }else{
                                        power_is_selected = true;
                                        selected_power = "Road Block";
                                    }
                                }

                            }else if ((click_x > ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*1.75/30))*SCALING_FACTOR_X) and (click_x < ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*2.75/30))*SCALING_FACTOR_X) and (click_y < (SCREEN_HEIGHT*28/30)*SCALING_FACTOR_Y) and (click_y > (SCREEN_HEIGHT*27/30)*SCALING_FACTOR_Y)) {
                                //selected powerup 5 Freeze
                                if (LHC.power_available){
                                    selected_origin = NULL;
                                    if (power_is_selected){
                                        if (selected_power == "Freeze"){
                                            power_is_selected = false;
                                        }else{
                                            selected_power = "Freeze";
                                        }
                                    }else{
                                        power_is_selected = true;
                                        selected_power = "Freeze";
                                    }
                                }

                            }else if ((click_x > ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*3.25/30))*SCALING_FACTOR_X) and (click_x < ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*4.25/30))*SCALING_FACTOR_X) and (click_y < (SCREEN_HEIGHT*28/30)*SCALING_FACTOR_Y) and (click_y > (SCREEN_HEIGHT*27/30)*SCALING_FACTOR_Y)) {
                                //selected powerup 6 Acid Circle
                                if (Apartments_girls.power_available){
                                    selected_origin = NULL;
                                    if (power_is_selected){
                                        if (selected_power == "Acid Circle"){
                                            power_is_selected = false;
                                        }else{
                                            selected_power = "Acid Circle";
                                        }
                                    }else{
                                        power_is_selected = true;
                                        selected_power = "Acid Circle";
                                    }
                                }
                            }


                            // applying the selected power
                            else if (power_is_selected){
                                power_is_selected = false;


                                if (selected_power=="Fire Circle"){// works only on moving soldiers
                                    Apartments_boys.power_available = false;
                                    Apartments_boys.power_circle_centre_x = Current_view_x + (click_x)/(SCALING_FACTOR_X);
                                    Apartments_boys.power_circle_centre_y = Current_view_y + (click_y)/(SCALING_FACTOR_Y);
                                    Apartments_boys.power_stay_time = 2;
                                    Apartments_boys.radius = 180;
                                    Apartments_boys.power_restore_time = 15;
                                    Apartments_boys.power_strength = 10;

                                }
                                else if(selected_power=="Shield"){// works only on buildings


                                    bool correct_place_click = false;

                                    if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 366) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 454) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 169) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 286) and (Jwala.loyalty == Hospital.loyalty) ) {Hospital.power_circle_centre_x = Jwala.x; Hospital.power_circle_centre_y = Jwala.y /* Hospital.target = &Jwala */; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 735) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 881) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 201) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 298) and (Blue_Home.loyalty == Hospital.loyalty) ) {Hospital.power_circle_centre_x = Blue_Home.x; Hospital.power_circle_centre_y = Blue_Home.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 355) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 438) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 507) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 619) and (Kara.loyalty ==  Hospital.loyalty) ) {Hospital.power_circle_centre_x = Kara.x; Hospital.power_circle_centre_y = Kara.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 815) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 936) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 567) and (Masala.loyalty ==  Hospital.loyalty) ) {Hospital.power_circle_centre_x = Masala.x; Hospital.power_circle_centre_y = Masala.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1041) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1187) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 453) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 572) and (Hospital.loyalty == Hospital.loyalty) ) {Hospital.power_circle_centre_x = Hospital.x; Hospital.power_circle_centre_y = Hospital.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1487) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1855) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 231) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 385) and (Main_building.loyalty ==  Hospital.loyalty) ) {Hospital.power_circle_centre_x = Main_building.x; Hospital.power_circle_centre_y = Main_building.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 175) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 267) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 756) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 860) and (Apartments_boys.loyalty ==  Hospital.loyalty) ) {Hospital.power_circle_centre_x = Apartments_boys.x; Hospital.power_circle_centre_y = Apartments_boys.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 763) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 877) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 807) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 914) and (OAT.loyalty ==  Hospital.loyalty) ) {Hospital.power_circle_centre_x = OAT.x; Hospital.power_circle_centre_y = OAT.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1197) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 665) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 836) and (Playground.loyalty ==  Hospital.loyalty) ) {Hospital.power_circle_centre_x = Playground.x; Hospital.power_circle_centre_y = Playground.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1409) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1650) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 927) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 1046) and (Research.loyalty ==  Hospital.loyalty) ) {Hospital.power_circle_centre_x = Research.x; Hospital.power_circle_centre_y = Research.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1627) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1803) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 448) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 564) and (Library.loyalty ==  Hospital.loyalty) ) {Hospital.power_circle_centre_x = Library.x; Hospital.power_circle_centre_y = Library.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2571) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2693) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 712) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 848) and (Apartments_girls.loyalty ==  Hospital.loyalty) ) {Hospital.power_circle_centre_x = Apartments_girls.x; Hospital.power_circle_centre_y = Apartments_girls.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2008) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2230) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 611) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 769) and (LHC.loyalty ==  Hospital.loyalty) ) {Hospital.power_circle_centre_x = LHC.x; Hospital.power_circle_centre_y = LHC.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2229) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2385) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 176) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 278) and (Red_Home.loyalty ==  Hospital.loyalty) ) {Hospital.power_circle_centre_x = Red_Home.x; Hospital.power_circle_centre_y = Red_Home.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2613) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2708) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 444) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 536) and (Market.loyalty ==  Hospital.loyalty) ) {Hospital.power_circle_centre_x = Market.x; Hospital.power_circle_centre_y = Market.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2606) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2727) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 249) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 349) and (Amaltas.loyalty ==  Hospital.loyalty) ) {Hospital.power_circle_centre_x = Amaltas.x; Hospital.power_circle_centre_y = Amaltas.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2208) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2366) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 428) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 542) and (School.loyalty ==  Hospital.loyalty) ) {Hospital.power_circle_centre_x = School.x; Hospital.power_circle_centre_y = School.y; correct_place_click = true;}


                                    if (correct_place_click){
                                        Hospital.power_available = false;
                                        //Hospital.power_circle_centre_x = Current_view_x + (click_x)/(SCALING_FACTOR_X);
                                        //Hospital.power_circle_centre_y = Current_view_y + (click_y)/(SCALING_FACTOR_Y);
                                        Hospital.power_stay_time = 2;
                                        Hospital.radius = 200;
                                        Hospital.power_restore_time = 15;
                                    }
                                }




                                else if(selected_power=="EMP"){// works only on buildings

                                    bool correct_place_click = false;

                                    if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 366) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 454) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 169) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 286) and (Jwala.loyalty != Research.loyalty) ) {Research.power_circle_centre_x = Jwala.x; Research.power_circle_centre_y = Jwala.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 735) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 881) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 201) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 298) and (Blue_Home.loyalty != Research.loyalty) ) {Research.power_circle_centre_x = Blue_Home.x; Research.power_circle_centre_y = Blue_Home.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 355) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 438) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 507) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 619) and (Kara.loyalty != Research.loyalty) ) {Research.power_circle_centre_x = Kara.x; Research.power_circle_centre_y = Kara.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 815) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 936) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 567) and (Masala.loyalty != Research.loyalty) ) {Research.power_circle_centre_x = Masala.x; Research.power_circle_centre_y = Masala.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1041) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1187) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 453) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 572) and (Hospital.loyalty != Research.loyalty) ) {Research.power_circle_centre_x = Hospital.x; Research.power_circle_centre_y = Hospital.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1487) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1855) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 231) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 385) and (Main_building.loyalty != Research.loyalty) ) {Research.power_circle_centre_x = Main_building.x; Research.power_circle_centre_y = Main_building.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 175) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 267) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 756) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 860) and (Apartments_boys.loyalty != Research.loyalty) ) {Research.power_circle_centre_x = Apartments_boys.x; Research.power_circle_centre_y = Apartments_boys.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 763) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 877) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 807) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 914) and (OAT.loyalty != Research.loyalty) ) {Research.power_circle_centre_x = OAT.x; Research.power_circle_centre_y = OAT.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1197) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 665) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 836) and (Playground.loyalty != Research.loyalty) ) {Research.power_circle_centre_x = Playground.x; Research.power_circle_centre_y = Playground.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1409) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1650) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 927) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 1046) and (Research.loyalty != Research.loyalty) ) {Research.power_circle_centre_x = Research.x; Research.power_circle_centre_y = Research.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1627) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1803) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 448) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 564) and (Library.loyalty != Research.loyalty) ) {Research.power_circle_centre_x = Library.x; Research.power_circle_centre_y = Library.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2571) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2693) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 712) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 848) and (Apartments_girls.loyalty != Research.loyalty) ) {Research.power_circle_centre_x = Apartments_girls.x; Research.power_circle_centre_y = Apartments_girls.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2008) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2230) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 611) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 769) and (LHC.loyalty != Research.loyalty) ) {Research.power_circle_centre_x = LHC.x; Research.power_circle_centre_y = LHC.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2229) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2385) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 176) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 278) and (Red_Home.loyalty != Research.loyalty) ) {Research.power_circle_centre_x = Red_Home.x; Research.power_circle_centre_y = Red_Home.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2613) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2708) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 444) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 536) and (Market.loyalty != Research.loyalty) ) {Research.power_circle_centre_x = Market.x; Research.power_circle_centre_y = Market.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2606) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2727) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 249) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 349) and (Amaltas.loyalty != Research.loyalty) ) {Research.power_circle_centre_x = Amaltas.x; Research.power_circle_centre_y = Amaltas.y; correct_place_click = true;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2208) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2366) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 428) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 542) and (School.loyalty != Research.loyalty) ) {Research.power_circle_centre_x = School.x; Research.power_circle_centre_y = School.y; correct_place_click = true;}

                                    if (correct_place_click){
                                        Research.power_stay_time = 1;
                                        Research.radius = 120;
                                        Research.power_restore_time = 15;
                                        Research.power_strength = 18;

                                        //Research.power_circle_centre_x = Current_view_x + (click_x)/(SCALING_FACTOR_X);
                                        //Research.power_circle_centre_y = Current_view_y + (click_y)/(SCALING_FACTOR_Y);

                                    }else{
                                        // display error, click on an enemy building
                                    }



                                }
                                else if (selected_power=="Road Block"){// works only on roads
                                    OAT.power_available = false;
                                    OAT.power_circle_centre_x = Current_view_x + (click_x)/(SCALING_FACTOR_X);
                                    OAT.power_circle_centre_y = Current_view_y + (click_y)/(SCALING_FACTOR_Y);
                                    OAT.power_stay_time = 4;
                                    OAT.radius = 40;
                                    OAT.power_restore_time = 15;
                                }
                                else if (selected_power=="Freeze"){// works on every action of the opponent 
                                    LHC.power_available = false;
                                    LHC.power_stay_time = 4;
                                    LHC.power_restore_time = 15;
                                }
                                else if (selected_power=="Acid Circle"){// works only on moving targets
                                    Apartments_girls.power_available = false;
                                    Apartments_girls.power_circle_centre_x = Current_view_x + (click_x)/(SCALING_FACTOR_X);
                                    Apartments_girls.power_circle_centre_y = Current_view_y + (click_y)/(SCALING_FACTOR_Y);
                                    Apartments_girls.power_stay_time = 2;
                                    Apartments_girls.radius = 180;
                                    Apartments_girls.power_restore_time = 15;
                                    Apartments_girls.power_strength = 10;
                                }

                                selected_power = "None";
                            }

                            // using equation of ellipse: x^2/a^2 + y^2/b^2 < 1 for an inside point

                            //selecting origin
                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 366) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 454) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 169) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 286) and (Jwala.loyalty == "Blue") ) {selected_origin = &Jwala;}
                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 735) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 881) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 201) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 298) and (Blue_Home.loyalty == "Blue") ) {selected_origin = &Blue_Home;}
                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 355) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 438) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 507) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 619) and (Kara.loyalty == "Blue") ) {selected_origin = &Kara;}
                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 815) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 936) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 567) and (Masala.loyalty == "Blue") ) {selected_origin = &Masala;}
                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1041) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1187) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 453) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 572) and (Hospital.loyalty == "Blue") ) {selected_origin = &Hospital;}
                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1487) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1855) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 231) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 385) and (Main_building.loyalty == "Blue") ) {selected_origin = &Main_building;}
                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 175) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 267) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 756) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 860) and (Apartments_boys.loyalty == "Blue") ) {selected_origin = &Apartments_boys;}
                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 763) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 877) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 807) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 914) and (OAT.loyalty == "Blue") ) {selected_origin = &OAT;}
                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1197) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 665) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 836) and (Playground.loyalty == "Blue") ) {selected_origin = &Playground;}
                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1409) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1650) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 927) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 1046) and (Research.loyalty == "Blue") ) {selected_origin = &Research;}
                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1627) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1803) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 448) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 564) and (Library.loyalty == "Blue") ) {selected_origin = &Library;}
                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2571) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2693) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 712) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 848) and (Apartments_girls.loyalty == "Blue") ) {selected_origin = &Apartments_girls;}
                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2008) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2230) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 611) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 769) and (LHC.loyalty == "Blue") ) {selected_origin = &LHC;}
                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2229) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2385) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 176) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 278) and (Red_Home.loyalty == "Blue") ) {selected_origin = &Red_Home;}
                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2613) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2708) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 444) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 536) and (Market.loyalty == "Blue") ) {selected_origin = &Market;}
                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2606) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2727) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 249) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 349) and (Amaltas.loyalty == "Blue") ) {selected_origin = &Amaltas;}
                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2208) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2366) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 428) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 542) and (School.loyalty == "Blue") ) {selected_origin = &School;}

                        break;





                        case SDL_BUTTON_RIGHT:
                            if ((selected_origin!=NULL) and (!power_is_selected)){

                                // how to see which is selected here? Definitely have to take different sizes for diffrent buildingd based on their image sizes.
                                // Rectangle selection instead of ellipse here. Ellipse to be used for power circles. 

                                // selecting destination
                                if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 366) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 454) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 169) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 286) ) {selected_destination = &Jwala;}
                                else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 735) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 881) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 201) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 298) ) {selected_destination = &Blue_Home;}
                                else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 355) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 438) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 507) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 619) ) {selected_destination = &Kara;}
                                else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 815) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 936) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 567) ) {selected_destination = &Masala;}
                                else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1041) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1187) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 453) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 572) ) {selected_destination = &Hospital;}
                                else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1487) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1855) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 231) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 385) ) {selected_destination = &Main_building;}
                                else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 175) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 267) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 756) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 860) ) {selected_destination = &Apartments_boys;}
                                else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 763) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 877) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 807) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 914) ) {selected_destination = &OAT;}
                                else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1197) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 665) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 836) ) {selected_destination = &Playground;}
                                else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1409) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1650) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 927) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 1046) ) {selected_destination = &Research;}
                                else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1627) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1803) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 448) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 564) ) {selected_destination = &Library;}
                                else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2571) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2693) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 712) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 848) ) {selected_destination = &Apartments_girls;}
                                else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2008) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2230) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 611) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 769) ) {selected_destination = &LHC;}
                                else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2229) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2385) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 176) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 278) ) {selected_destination = &Red_Home;}
                                else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2613) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2708) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 444) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 536) ) {selected_destination = &Market;}
                                else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2606) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2727) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 249) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 349) ) {selected_destination = &Amaltas;}
                                else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2208) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2366) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 428) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 542) ) {selected_destination = &School;}

                                else {selected_destination = NULL;}

                                if ((!(selected_origin==selected_destination)) and selected_destination!=NULL){
                                    int outgoing = selected_origin->send_half();
                                    if (outgoing!=0){
                                        create_packet(outgoing, selected_origin, selected_destination);
                                    }
                                }

                                selected_origin = NULL;
                                selected_destination = NULL;

                            }else{
                                // ERROR: select an origin first!
                            }
                        break; 
                    }
                }
            }
		}
};