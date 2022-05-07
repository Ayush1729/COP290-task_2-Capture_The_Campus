class Play_State{
    

	public:


		Play_State(){
			//constructor; not necessary
		}

        DoublyLinkedList* all_soldiers = new DoublyLinkedList();



        bool power_is_selected_red = false;
        string selected_power_red = "None";

        bool power_is_selected_blue = false;
        string selected_power_blue = "None";

        bool finished = false;
        float finished_time = 3;


        // initializing all planets
        Planet* Hospital = new Planet(1128, 515, "Hospital", "Shield"); 
        Planet* LHC = new Planet(2095,687, "LHC", "Freeze"); 
        Planet* Library = new Planet(1723,504, "Library", "Cannon"); 
        HomePlanet* Blue_Home = new HomePlanet("Blue", 798,258, "Vindhyachal"); 
        HomePlanet* Red_Home = new HomePlanet("Red",2309,222, "Himadri"); 
        Planet* Jwala = new Planet(409, 242, "Jwala", "None"); 
        Planet* Kara = new Planet(397, 570, "Kara", "None"); 
        Planet* Apartments_boys = new Planet(227, 808, "Apartments boys", "Fire Circle"); 
        Planet* Apartments_girls = new Planet(2627, 783, "Apartments girls", "Acid Circle"); 
        Planet* Playground = new Planet(1329, 747, "Playground", "Fast Move"); 
        Planet* Research = new Planet(1522, 990, "Research Park", "EMP"); 
        Planet* Masala = new Planet(877, 517, "Masala Mix", "Cannon"); 
        Planet* Main_building = new Planet(1674, 305, "Main Building", "Fast Spawn"); 
        Planet* Market = new Planet(2663, 486, "IITD Market", "None"); 
        Planet* School = new Planet(2305, 484, "Kendriya Vidyalaya", "None"); 
        Planet* Amaltas = new Planet(2666, 307, "Amaltas", "None"); 
        Planet* OAT = new Planet(823, 861, "OAT", "Road Block");
    


        Planet* selected_origin_red = NULL;
        Planet* selected_destination_red = NULL;

        Planet* selected_origin_blue = NULL;
        Planet* selected_destination_blue = NULL;


        CannonBall* cannon1 = new CannonBall(Masala);
        CannonBall* cannon2 = new CannonBall(Library);


        float Current_view_x = (my_loyalty == "Red")?1700:0;
        float Current_view_y = 0;

        float Current_view_speed = 15;
        float CAMPUS_WIDTH = 3017;
        float CAMPUS_HEIGHT = 1187;
        float click_x = 0;
        float click_y = 0;
        float clicked = 0;
        float isright = 0;
        float isleft = 0;
        float isquit = 0;


        void create_packet(int outgoing, Planet* selected_origin, Planet* selected_destination){
            SoldierPacket* temp = new SoldierPacket(outgoing, selected_destination, selected_origin);
            Mix_PlayChannel( -1, gSoldier_start_sound, 0 );
            all_soldiers->insert(temp);
            temp = NULL;
        }


		void render(){

            //Clear screen
            SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 255 );
            SDL_RenderClear( gRenderer );

            SDL_Rect campus_view_rect;
            campus_view_rect.w = SCREEN_WIDTH;
            campus_view_rect.h = SCREEN_HEIGHT;
            campus_view_rect.x = Current_view_x;
            campus_view_rect.y = Current_view_y;

            SDL_RenderCopy( gRenderer, gTexture5, &campus_view_rect, NULL );


            all_soldiers->render(Current_view_x, Current_view_y);


            LHC->render(Current_view_x, Current_view_y);
            Library->render(Current_view_x, Current_view_y);
            Blue_Home->render(Current_view_x, Current_view_y);
            Red_Home->render(Current_view_x, Current_view_y);
            OAT->render(Current_view_x, Current_view_y);
            Jwala->render(Current_view_x, Current_view_y);
            Kara->render(Current_view_x, Current_view_y);
            Apartments_boys->render(Current_view_x, Current_view_y);
            Masala->render(Current_view_x, Current_view_y);
            Hospital->render(Current_view_x, Current_view_y);
            Apartments_girls->render(Current_view_x, Current_view_y);
            School->render(Current_view_x, Current_view_y);
            Market->render(Current_view_x, Current_view_y);
            Amaltas->render(Current_view_x, Current_view_y);
            Research->render(Current_view_x, Current_view_y);
            Playground->render(Current_view_x, Current_view_y);
            Main_building->render(Current_view_x, Current_view_y);



            SDL_Rect select_rect;
            if (selected_origin_blue != NULL) {
             
                if (selected_origin_blue->identity ==  "LHC") {select_rect = { (1998 - Current_view_x)*SCALING_FACTOR_X, (601 - Current_view_y)*SCALING_FACTOR_Y, (242)*SCALING_FACTOR_X, (178)*SCALING_FACTOR_Y };}
                else if (selected_origin_blue->identity ==  "Library") {select_rect = { (1617 - Current_view_x)*SCALING_FACTOR_X, (438 - Current_view_y)*SCALING_FACTOR_Y, (196)*SCALING_FACTOR_X, (136)*SCALING_FACTOR_Y  };}
                else if (selected_origin_blue->identity ==  "Vindhyachal") {select_rect = { (725 - Current_view_x)*SCALING_FACTOR_X, (191 - Current_view_y)*SCALING_FACTOR_Y, (166)*SCALING_FACTOR_X, (117)*SCALING_FACTOR_Y  };}
                else if (selected_origin_blue->identity ==  "Himadri") {select_rect = { (2219 - Current_view_x)*SCALING_FACTOR_X, (166 - Current_view_y)*SCALING_FACTOR_Y, (176)*SCALING_FACTOR_X, (122)*SCALING_FACTOR_Y  };}
                else if (selected_origin_blue->identity ==  "OAT") {select_rect = { (753 - Current_view_x)*SCALING_FACTOR_X, (797 - Current_view_y)*SCALING_FACTOR_Y, (134)*SCALING_FACTOR_X, (127)*SCALING_FACTOR_Y  };}
                else if (selected_origin_blue->identity ==  "Jwala") {select_rect = { (356 - Current_view_x)*SCALING_FACTOR_X, (159 - Current_view_y)*SCALING_FACTOR_Y, (108)*SCALING_FACTOR_X, (137)*SCALING_FACTOR_Y  };}
                else if (selected_origin_blue->identity ==  "Kara") {select_rect = { (345 - Current_view_x)*SCALING_FACTOR_X, (497 - Current_view_y)*SCALING_FACTOR_Y, (103)*SCALING_FACTOR_X, (132)*SCALING_FACTOR_Y  };}
                else if (selected_origin_blue->identity ==  "Apartments boys") {select_rect = { (165 - Current_view_x)*SCALING_FACTOR_X, (746 - Current_view_y)*SCALING_FACTOR_Y, (112)*SCALING_FACTOR_X, (124)*SCALING_FACTOR_Y  };}
                else if (selected_origin_blue->identity ==  "Masala Mix") {select_rect = { (805 - Current_view_x)*SCALING_FACTOR_X, (461 - Current_view_y)*SCALING_FACTOR_Y, (141)*SCALING_FACTOR_X, (116)*SCALING_FACTOR_Y  };}
                else if (selected_origin_blue->identity ==  "Hospital") {select_rect = { (1031 - Current_view_x)*SCALING_FACTOR_X, (443 - Current_view_y)*SCALING_FACTOR_Y, (166)*SCALING_FACTOR_X, (139)*SCALING_FACTOR_Y  };}
                else if (selected_origin_blue->identity ==  "Apartments girls") {select_rect = { (2561 - Current_view_x)*SCALING_FACTOR_X, (702 - Current_view_y)*SCALING_FACTOR_Y, (142)*SCALING_FACTOR_X, (156)*SCALING_FACTOR_Y  };}
                else if (selected_origin_blue->identity ==  "Kendriya Vidyalaya") {select_rect = { (2198 - Current_view_x)*SCALING_FACTOR_X, (418 - Current_view_y)*SCALING_FACTOR_Y, (178)*SCALING_FACTOR_X, (134)*SCALING_FACTOR_Y  };}
                else if (selected_origin_blue->identity ==  "IITD Market") {select_rect = { (2603 - Current_view_x)*SCALING_FACTOR_X, (434 - Current_view_y)*SCALING_FACTOR_Y, (115)*SCALING_FACTOR_X, (112)*SCALING_FACTOR_Y  };}
                else if (selected_origin_blue->identity ==  "Amaltas") {select_rect = { (2596 - Current_view_x)*SCALING_FACTOR_X, (239 - Current_view_y)*SCALING_FACTOR_Y, (141)*SCALING_FACTOR_X, (120)*SCALING_FACTOR_Y  };}
                else if (selected_origin_blue->identity ==  "Research Park") {select_rect = { (1399 - Current_view_x)*SCALING_FACTOR_X, (917 - Current_view_y)*SCALING_FACTOR_Y, (291)*SCALING_FACTOR_X, (139)*SCALING_FACTOR_Y  };}
                else if (selected_origin_blue->identity ==  "Playground") {select_rect = { (1187 - Current_view_x)*SCALING_FACTOR_X, (655 - Current_view_y)*SCALING_FACTOR_Y, (294)*SCALING_FACTOR_X, (191)*SCALING_FACTOR_Y  };}
                else if (selected_origin_blue->identity ==  "Main Building") {select_rect = { (1477 - Current_view_x)*SCALING_FACTOR_X, (221 - Current_view_y)*SCALING_FACTOR_Y, (388)*SCALING_FACTOR_X, (174)*SCALING_FACTOR_Y  };}

                SDL_SetTextureColorMod( gSelect_image, 0, 0, 90 ); // for blue
                SDL_RenderCopy( gRenderer, gSelect_image , NULL, &select_rect );

                //Render text
                SDL_Color textColor = { 255, 255, 255 };
                if( !loadFromRenderedText(selected_origin_blue->identity, textColor, gPacifico)) {
                    std::cout<<"Failed to render text texture in planet!"<<std::endl;
                    error_occ = true;
                }
            
                SDL_Rect identity_pos = { select_rect.x + 10*SCALING_FACTOR_X, select_rect.y + 10*SCALING_FACTOR_Y, select_rect.w - 20*SCALING_FACTOR_X, 30*SCALING_FACTOR_Y  };
                // Text on screen
                SDL_RenderCopy( gRenderer, gTextTexture, NULL, &identity_pos );

            }

            if (selected_origin_red != NULL) {
             
                if (selected_origin_red->identity ==  "LHC") {select_rect = { (1998 - Current_view_x)*SCALING_FACTOR_X, (601 - Current_view_y)*SCALING_FACTOR_Y, (242)*SCALING_FACTOR_X, (178)*SCALING_FACTOR_Y };}
                else if (selected_origin_red->identity ==  "Library") {select_rect = { (1617 - Current_view_x)*SCALING_FACTOR_X, (438 - Current_view_y)*SCALING_FACTOR_Y, (196)*SCALING_FACTOR_X, (136)*SCALING_FACTOR_Y  };}
                else if (selected_origin_red->identity ==  "Vindhyachal") {select_rect = { (725 - Current_view_x)*SCALING_FACTOR_X, (191 - Current_view_y)*SCALING_FACTOR_Y, (166)*SCALING_FACTOR_X, (117)*SCALING_FACTOR_Y  };}
                else if (selected_origin_red->identity ==  "Himadri") {select_rect = { (2219 - Current_view_x)*SCALING_FACTOR_X, (166 - Current_view_y)*SCALING_FACTOR_Y, (176)*SCALING_FACTOR_X, (122)*SCALING_FACTOR_Y  };}
                else if (selected_origin_red->identity ==  "OAT") {select_rect = { (753 - Current_view_x)*SCALING_FACTOR_X, (797 - Current_view_y)*SCALING_FACTOR_Y, (134)*SCALING_FACTOR_X, (127)*SCALING_FACTOR_Y  };}
                else if (selected_origin_red->identity ==  "Jwala") {select_rect = { (356 - Current_view_x)*SCALING_FACTOR_X, (159 - Current_view_y)*SCALING_FACTOR_Y, (108)*SCALING_FACTOR_X, (137)*SCALING_FACTOR_Y  };}
                else if (selected_origin_red->identity ==  "Kara") {select_rect = { (345 - Current_view_x)*SCALING_FACTOR_X, (497 - Current_view_y)*SCALING_FACTOR_Y, (103)*SCALING_FACTOR_X, (132)*SCALING_FACTOR_Y  };}
                else if (selected_origin_red->identity ==  "Apartments boys") {select_rect = { (165 - Current_view_x)*SCALING_FACTOR_X, (746 - Current_view_y)*SCALING_FACTOR_Y, (112)*SCALING_FACTOR_X, (124)*SCALING_FACTOR_Y  };}
                else if (selected_origin_red->identity ==  "Masala Mix") {select_rect = { (805 - Current_view_x)*SCALING_FACTOR_X, (461 - Current_view_y)*SCALING_FACTOR_Y, (141)*SCALING_FACTOR_X, (116)*SCALING_FACTOR_Y  };}
                else if (selected_origin_red->identity ==  "Hospital") {select_rect = { (1031 - Current_view_x)*SCALING_FACTOR_X, (443 - Current_view_y)*SCALING_FACTOR_Y, (166)*SCALING_FACTOR_X, (139)*SCALING_FACTOR_Y  };}
                else if (selected_origin_red->identity ==  "Apartments girls") {select_rect = { (2561 - Current_view_x)*SCALING_FACTOR_X, (702 - Current_view_y)*SCALING_FACTOR_Y, (142)*SCALING_FACTOR_X, (156)*SCALING_FACTOR_Y  };}
                else if (selected_origin_red->identity ==  "Kendriya Vidyalaya") {select_rect = { (2198 - Current_view_x)*SCALING_FACTOR_X, (418 - Current_view_y)*SCALING_FACTOR_Y, (178)*SCALING_FACTOR_X, (134)*SCALING_FACTOR_Y  };}
                else if (selected_origin_red->identity ==  "IITD Market") {select_rect = { (2603 - Current_view_x)*SCALING_FACTOR_X, (434 - Current_view_y)*SCALING_FACTOR_Y, (115)*SCALING_FACTOR_X, (112)*SCALING_FACTOR_Y  };}
                else if (selected_origin_red->identity ==  "Amaltas") {select_rect = { (2596 - Current_view_x)*SCALING_FACTOR_X, (239 - Current_view_y)*SCALING_FACTOR_Y, (141)*SCALING_FACTOR_X, (120)*SCALING_FACTOR_Y  };}
                else if (selected_origin_red->identity ==  "Research Park") {select_rect = { (1399 - Current_view_x)*SCALING_FACTOR_X, (917 - Current_view_y)*SCALING_FACTOR_Y, (291)*SCALING_FACTOR_X, (139)*SCALING_FACTOR_Y  };}
                else if (selected_origin_red->identity ==  "Playground") {select_rect = { (1187 - Current_view_x)*SCALING_FACTOR_X, (655 - Current_view_y)*SCALING_FACTOR_Y, (294)*SCALING_FACTOR_X, (191)*SCALING_FACTOR_Y  };}
                else if (selected_origin_red->identity ==  "Main Building") {select_rect = { (1477 - Current_view_x)*SCALING_FACTOR_X, (221 - Current_view_y)*SCALING_FACTOR_Y, (388)*SCALING_FACTOR_X, (174)*SCALING_FACTOR_Y  };}

                SDL_SetTextureColorMod( gSelect_image, 90, 0, 0 ); // for red
                SDL_RenderCopy( gRenderer, gSelect_image , NULL, &select_rect );

                //Render text
                SDL_Color textColor = { 255, 255, 255 };
                if( !loadFromRenderedText(selected_origin_red->identity, textColor, gPacifico)) {
                    std::cout<<"Failed to render text texture in planet!"<<std::endl;
                    error_occ = true;
                }
            
                SDL_Rect identity_pos = { select_rect.x + 10*SCALING_FACTOR_X, select_rect.y + 10*SCALING_FACTOR_Y, select_rect.w - 20*SCALING_FACTOR_X, 30*SCALING_FACTOR_Y  };
                // Text on screen
                SDL_RenderCopy( gRenderer, gTextTexture, NULL, &identity_pos );

            }

            


            // Power visuals

            // all powers of two colours for the two players
            SDL_Rect power_pos;

            if (Apartments_boys->power_stay_time>0){
                power_pos.w = Apartments_boys->radius*SCALING_FACTOR_X;
                power_pos.h = Apartments_boys->radius*SCALING_FACTOR_Y;
                power_pos.x = (Apartments_boys->power_circle_centre_x - (Apartments_boys->radius/2) - Current_view_x)*SCALING_FACTOR_X;
                power_pos.y = (Apartments_boys->power_circle_centre_y - (Apartments_boys->radius/2) - Current_view_y)*SCALING_FACTOR_Y;
                

                if (Apartments_boys->loyalty == "Blue"){
                    SDL_SetTextureColorMod( gTexture_blue_fire, 0, 0, 180 );
                    SDL_RenderCopy( gRenderer, gTexture_blue_fire , NULL, &power_pos );
                }
                else if (Apartments_boys->loyalty == "Red"){
                    SDL_SetTextureColorMod( gTexture_blue_fire, 180, 0, 0 );
                    SDL_RenderCopy( gRenderer, gTexture_blue_fire , NULL, &power_pos );
                }
            }

            if (Apartments_girls->power_stay_time>0){
                power_pos.w = Apartments_girls->radius*SCALING_FACTOR_X;
                power_pos.h = Apartments_girls->radius*SCALING_FACTOR_Y;
                power_pos.x = (Apartments_girls->power_circle_centre_x - (Apartments_girls->radius/2) - Current_view_x)*SCALING_FACTOR_X;
                power_pos.y = (Apartments_girls->power_circle_centre_y - (Apartments_girls->radius/2) - Current_view_y)*SCALING_FACTOR_Y;


                if (Apartments_girls->loyalty == "Blue"){
                    SDL_SetTextureColorMod( gTexture_blue_acid, 0, 0, 180 );
                    SDL_RenderCopy( gRenderer, gTexture_blue_acid , NULL, &power_pos );
                }
                else if (Apartments_girls->loyalty == "Red"){
                    SDL_SetTextureColorMod( gTexture_blue_acid, 180, 0, 0 );
                    SDL_RenderCopy( gRenderer, gTexture_blue_acid , NULL, &power_pos );
                } 
            }

            if (Hospital->power_stay_time>0){
                power_pos.w = Hospital->radius*SCALING_FACTOR_X;
                power_pos.h = Hospital->radius*SCALING_FACTOR_Y;
                power_pos.x = (Hospital->power_circle_centre_x - (Hospital->radius/2) - Current_view_x)*SCALING_FACTOR_X;
                power_pos.y = (Hospital->power_circle_centre_y - (Hospital->radius/2) - Current_view_y)*SCALING_FACTOR_Y;


                if (Hospital->loyalty == "Blue"){
                    SDL_RenderCopy( gRenderer, gTexture_shield , NULL, &power_pos );
                }
                else if (Hospital->loyalty == "Red"){
                    SDL_RenderCopy( gRenderer, gTexture_shield , NULL, &power_pos );
                } 
            }

            if (Research->power_stay_time>0){
                power_pos.w = Research->radius*SCALING_FACTOR_X;
                power_pos.h = Research->radius*SCALING_FACTOR_Y;
                power_pos.x = (Research->power_circle_centre_x - (Research->radius/2) - Current_view_x)*SCALING_FACTOR_X;
                power_pos.y = (Research->power_circle_centre_y - (Research->radius/2) - Current_view_y)*SCALING_FACTOR_Y;


                if (Research->loyalty == "Blue"){
                    SDL_RenderCopy( gRenderer, gTexture_emp , NULL, &power_pos );
                }
                else if (Research->loyalty == "Red"){
                    SDL_RenderCopy( gRenderer, gTexture_emp , NULL, &power_pos );
                } 
            }

            if (OAT->power_stay_time>0){
                power_pos.w = OAT->radius*SCALING_FACTOR_X;
                power_pos.h = OAT->radius*SCALING_FACTOR_Y;
                power_pos.x = (OAT->power_circle_centre_x - (OAT->radius/2) - Current_view_x)*SCALING_FACTOR_X;
                power_pos.y = (OAT->power_circle_centre_y - (OAT->radius/2) - Current_view_y)*SCALING_FACTOR_Y;

                if (OAT->loyalty == "Blue"){
                    //SDL_SetTextureColorMod( gTexture_blue_wall, 0, 0, 180 );
                    SDL_RenderCopy( gRenderer, gTexture_blue_wall , NULL, &power_pos );
                }
                else if (OAT->loyalty == "Red"){
                    //SDL_SetTextureColorMod( gTexture_blue_wall, 180, 0, 0 );
                    SDL_RenderCopy( gRenderer, gTexture_blue_wall, NULL, &power_pos );
                } 
            }



            if (LHC->power_stay_time>0){
                if (LHC->loyalty != my_loyalty){
                    // do nothing here for the other player, but show for the current player
                    SDL_RenderCopy( gRenderer, gTexture_freeze, NULL, NULL );
                } 
            }


            if (cannon1->alive){ cannon1->render(Current_view_x, Current_view_y);}
            if (cannon2->alive){ cannon2->render(Current_view_x, Current_view_y);}








            // the six buttons for the six powers

            SDL_SetTextureColorMod( gSelect_image, 230, 230, 230 );

            // Fire Circle
            SDL_Rect fillRect = { ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*7.25/30))*SCALING_FACTOR_X, (27*SCREEN_HEIGHT/30)*SCALING_FACTOR_Y, (SCREEN_WIDTH/15)*SCALING_FACTOR_X, (SCREEN_HEIGHT/15)*SCALING_FACTOR_Y };
            if ((Apartments_boys->power_available) and (Apartments_boys->loyalty == my_loyalty)){
                SDL_SetTextureColorMod( gTexture_fire_button, 255, 255, 0 );
            }else{
                SDL_SetTextureColorMod( gTexture_fire_button, 70, 70, 70 );
            }
            SDL_RenderCopy( gRenderer, gTexture_fire_button, NULL, &fillRect );

            if ((Apartments_boys->power_available) and (Apartments_boys->loyalty == my_loyalty)){
                if ((my_loyalty=="Blue") and (selected_power_blue == "Fire Circle")) {SDL_RenderCopy( gRenderer, gSelect_image, NULL, &fillRect );}
                if ((my_loyalty=="Red") and (selected_power_red == "Fire Circle")) {SDL_RenderCopy( gRenderer, gSelect_image, NULL, &fillRect );}
            }
            

            // Shield
            fillRect = { ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*4.75/30))*SCALING_FACTOR_X, (27*SCREEN_HEIGHT/30)*SCALING_FACTOR_Y, (SCREEN_WIDTH/15)*SCALING_FACTOR_X, (SCREEN_HEIGHT/15)*SCALING_FACTOR_Y };
            if ((Hospital->power_available) and (Hospital->loyalty == my_loyalty)){
                SDL_SetTextureColorMod( gTexture_shield_button, 64, 225, 64 );
            }else{
                SDL_SetTextureColorMod( gTexture_shield_button, 70, 70, 70 );
            }
            SDL_RenderCopy( gRenderer, gTexture_shield_button, NULL, &fillRect );

            if ((Hospital->power_available) and (Hospital->loyalty == my_loyalty)){
                if ((my_loyalty=="Blue") and (selected_power_blue == "Shield")) {SDL_RenderCopy( gRenderer, gSelect_image, NULL, &fillRect );}
                if ((my_loyalty=="Red") and (selected_power_red == "Shield")) {SDL_RenderCopy( gRenderer, gSelect_image, NULL, &fillRect );}
            }


            // EMP
            fillRect = { ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*2.25/30))*SCALING_FACTOR_X, (27*SCREEN_HEIGHT/30)*SCALING_FACTOR_Y, (SCREEN_WIDTH/15)*SCALING_FACTOR_X, (SCREEN_HEIGHT/15)*SCALING_FACTOR_Y };
            if ((Research->power_available) and (Research->loyalty == my_loyalty)){
                SDL_SetTextureColorMod( gTexture_emp_button, 255, 255, 0 );
            }else{
                SDL_SetTextureColorMod( gTexture_emp_button, 70, 70, 70 );
            }
            SDL_RenderCopy( gRenderer, gTexture_emp_button, NULL, &fillRect );

            if ((Research->power_available) and (Research->loyalty == my_loyalty)){
                if ((my_loyalty=="Blue") and (selected_power_blue == "EMP")) {SDL_RenderCopy( gRenderer, gSelect_image, NULL, &fillRect );}
                if ((my_loyalty=="Red") and (selected_power_red == "EMP")) {SDL_RenderCopy( gRenderer, gSelect_image, NULL, &fillRect );}
            }


            // Road Block
            fillRect = { ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*0.25/30))*SCALING_FACTOR_X, (27*SCREEN_HEIGHT/30)*SCALING_FACTOR_Y, (SCREEN_WIDTH/15)*SCALING_FACTOR_X, (SCREEN_HEIGHT/15)*SCALING_FACTOR_Y };
            if ((OAT->power_available) and (OAT->loyalty == my_loyalty)){
                SDL_SetTextureColorMod( gTexture_wall_button, 140, 150, 170 );
            }else{
                SDL_SetTextureColorMod( gTexture_wall_button, 70, 70, 70 );
            }
            SDL_RenderCopy( gRenderer, gTexture_wall_button, NULL, &fillRect );

            if ((OAT->power_available) and (OAT->loyalty == my_loyalty)){
                if ((my_loyalty=="Blue") and (selected_power_blue == "Road Block")) {SDL_RenderCopy( gRenderer, gSelect_image, NULL, &fillRect );}
                if ((my_loyalty=="Red") and (selected_power_red == "Road Block")) {SDL_RenderCopy( gRenderer, gSelect_image, NULL, &fillRect );}
            }


            // Freeze
            fillRect = { ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*2.75/30))*SCALING_FACTOR_X, (27*SCREEN_HEIGHT/30)*SCALING_FACTOR_Y, (SCREEN_WIDTH/15)*SCALING_FACTOR_X, (SCREEN_HEIGHT/15)*SCALING_FACTOR_Y };
            if ((LHC->power_available) and (LHC->loyalty == my_loyalty)){
                SDL_SetTextureColorMod( gTexture_freeze_button, 77, 225, 225 );
            }else{
                SDL_SetTextureColorMod( gTexture_freeze_button, 70, 70, 70 );
            }
            SDL_RenderCopy( gRenderer, gTexture_freeze_button, NULL, &fillRect );

            if ((LHC->power_available) and (LHC->loyalty == my_loyalty)) {
                if ((my_loyalty=="Blue") and (selected_power_blue == "Freeze")) {SDL_RenderCopy( gRenderer, gSelect_image, NULL, &fillRect );}
                if ((my_loyalty=="Red") and (selected_power_red == "Freeze")) {SDL_RenderCopy( gRenderer, gSelect_image, NULL, &fillRect );}
            }


            // Acid Circle
            fillRect = { ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*5.25/30))*SCALING_FACTOR_X, (27*SCREEN_HEIGHT/30)*SCALING_FACTOR_Y, (SCREEN_WIDTH/15)*SCALING_FACTOR_X, (SCREEN_HEIGHT/15)*SCALING_FACTOR_Y };
            if ((Apartments_girls->power_available) and (Apartments_girls->loyalty == my_loyalty)){
                SDL_SetTextureColorMod( gTexture_acid_button, 24, 218, 128 );
            }else{
                SDL_SetTextureColorMod( gTexture_acid_button, 70, 70, 70 );
            }
            SDL_RenderCopy( gRenderer, gTexture_acid_button, NULL, &fillRect );

            if ((Apartments_girls->power_available) and (Apartments_girls->loyalty == my_loyalty)){
                if ((my_loyalty=="Blue") and (selected_power_blue == "Acid Circle")) {SDL_RenderCopy( gRenderer, gSelect_image, NULL, &fillRect );}
                if ((my_loyalty=="Red") and (selected_power_red == "Acid Circle")) {SDL_RenderCopy( gRenderer, gSelect_image, NULL, &fillRect );}
            }





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







            if (finished){

                if (Blue_Home->is_alive()){
                    //Blue player wins
                    //Render text
                    SDL_Color textColor = { 0, 0, 255 };
                    if( !loadFromRenderedText("Blue Wins", textColor, gaerobusdotty)) {
                        std::cout<<"Failed to render text texture!"<<std::endl;
                        error_occ = true;
                    }
                }else{
                    //Red player wins
                    SDL_Color textColor = { 255, 0, 0 };
                    if( !loadFromRenderedText("Red Wins", textColor, gaerobusdotty)) {
                        std::cout<<"Failed to render text texture!"<<std::endl;
                        error_occ = true;
                    }
                }

                SDL_Rect titl_pos;
                titl_pos.w = (0.6*SCREEN_WIDTH)*SCALING_FACTOR_X;
                titl_pos.h = (0.4*SCREEN_HEIGHT)*SCALING_FACTOR_Y;
                titl_pos.x = (0.2*SCREEN_WIDTH)*SCALING_FACTOR_X;
                titl_pos.y = (0.3*SCREEN_HEIGHT)*SCALING_FACTOR_Y;
                // Text on screen
                SDL_RenderCopy( gRenderer, gTextTexture, NULL, &titl_pos );
            
            }



            // Put here for when the other person quits in between




            //Update screen
            SDL_RenderPresent( gRenderer );

		}






		void update(float dt, float other_player[]){


            // text[] = {state, clicked, isleft, isright, click_x, click_y, Current_view_x, Current_view_y, isquit}
            //["None", "Cannon", "EMP", "Fire Circle", "Acid Circle", "Road Block", "Fast Spawn", "Fast Move", "Freeze", "Shield"]

            clicked = 0;
            
            if ((!finished) and (other_player[0]==1)){
                LHC->update(dt, Research, Hospital);
                Library->update(dt, Research, Hospital);
                Jwala->update(dt, Research, Hospital);
                Kara->update(dt, Research, Hospital);
                Apartments_boys->update(dt, Research, Hospital);
                Apartments_girls->update(dt, Research, Hospital);
                Amaltas->update(dt, Research, Hospital);
                Playground->update(dt, Research, Hospital);
                Research->update(dt, Research, Hospital);
                Hospital->update(dt, Research, Hospital);
                Masala->update(dt, Research, Hospital);
                Main_building->update(dt, Research, Hospital);
                Market->update(dt, Research, Hospital);
                School->update(dt, Research, Hospital);
                OAT->update(dt, Research, Hospital);


                Blue_Home->update(dt, Main_building->loyalty, Research, Hospital);
                Red_Home->update(dt, Main_building->loyalty, Research, Hospital);


                if (!(Blue_Home->is_alive() and Red_Home->is_alive())){
                    finished = true;
                    // free / NULL all things
                    Mix_PlayChannel( -1, gVictory_sound, 0 );
                    return;
                }


                if (cannon1->alive){ cannon1->update();}
                if (cannon2->alive){ cannon2->update();}



                all_soldiers->update(dt, Playground, Apartments_boys, Apartments_girls, OAT, Hospital, LHC, Masala, Library, cannon1, cannon2);



                //Get mouse position for scrolling view screen
                int mouse_x, mouse_y;
                SDL_GetMouseState( &mouse_x, &mouse_y );
                if (mouse_x<(SCREEN_WIDTH/45)*SCALING_FACTOR_X){
                    Current_view_x = max(Current_view_x - Current_view_speed, float(0));
                }else if(mouse_x>((SCREEN_WIDTH/45)*44)*SCALING_FACTOR_X){
                    Current_view_x = min(Current_view_x + Current_view_speed, CAMPUS_WIDTH - SCREEN_WIDTH);
                }
                if (mouse_y<(SCREEN_HEIGHT/30)*SCALING_FACTOR_Y){
                    Current_view_y = max(Current_view_y - Current_view_speed,float(0));
                }else if(mouse_y>((SCREEN_HEIGHT/30)*29)*SCALING_FACTOR_Y){
                    Current_view_y = min(Current_view_y + Current_view_speed, CAMPUS_HEIGHT - SCREEN_HEIGHT);
                }






                if (my_loyalty == "Blue"){

        			SDL_Event e;
                	while(SDL_PollEvent( &e ) != 0 ){
                        if( e.type == SDL_QUIT ){
                            isquit = 1;
                            quit = true;
                        }else if( e.type == SDL_KEYDOWN ){
                            //Select surfaces based on key press
                            switch( e.key.keysym.sym ){

                                case SDLK_ESCAPE:
                                isquit = 1;
                                quit = true;
                                break;
                            }
                        }else if ((e.type == SDL_MOUSEBUTTONDOWN) and !((LHC->power_stay_time > 0) and (LHC->loyalty == "Red"))){

                            clicked = 1;
                            click_x = e.button.x;// absolute pixels from left side, do not get scaled automatically
                            click_y = e.button.y;

                            switch (e.button.button){
                                case SDL_BUTTON_LEFT:

                                    isleft = 1;
                                    isright = 0;


                                    // the six power buttons

                                    // relative to campus click position print
                                    //std::cout<<"x = "<<click_x + Current_view_x<<"          y = "<<click_y + Current_view_y<<std::endl;

                                    if ((click_x > ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*7.25/30))*SCALING_FACTOR_X) and (click_x < ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*5.25/30))*SCALING_FACTOR_X) and (click_y < (SCREEN_HEIGHT*29/30)*SCALING_FACTOR_Y) and (click_y > (SCREEN_HEIGHT*27/30)*SCALING_FACTOR_Y)) {
                                        // selected powerup 1 Fire Circle
                                        if (Apartments_boys->power_available and Apartments_boys->loyalty == "Blue"){
                                            selected_origin_blue = NULL;
                                            if (power_is_selected_blue){
                                                if (selected_power_blue == "Fire Circle"){
                                                    power_is_selected_blue = false;
                                                    selected_power_blue = "None";
                                                }else{
                                                    selected_power_blue = "Fire Circle";
                                                }
                                            }else{
                                                power_is_selected_blue = true;
                                                selected_power_blue = "Fire Circle";
                                            }
                                        }

                                    }else if ((click_x > ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*4.75/30))*SCALING_FACTOR_X) and (click_x < ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*2.75/30))*SCALING_FACTOR_X) and (click_y < (SCREEN_HEIGHT*29/30)*SCALING_FACTOR_Y) and (click_y > (SCREEN_HEIGHT*27/30)*SCALING_FACTOR_Y)) {
                                        //selected powerup 2 Shield
                                        if (Hospital->power_available and Hospital->loyalty == "Blue"){
                                            selected_origin_blue = NULL;
                                            if (power_is_selected_blue){
                                                if (selected_power_blue == "Shield"){
                                                    power_is_selected_blue = false;
                                                    selected_power_blue = "None";
                                                }else{
                                                    selected_power_blue = "Shield";
                                                }
                                            }else{
                                                power_is_selected_blue = true;
                                                selected_power_blue = "Shield";
                                            }
                                        }

                                    }else if ((click_x > ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*2.25/30))*SCALING_FACTOR_X) and (click_x < ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*0.25/30))*SCALING_FACTOR_X) and (click_y < (SCREEN_HEIGHT*29/30)*SCALING_FACTOR_Y) and (click_y > (SCREEN_HEIGHT*27/30)*SCALING_FACTOR_Y)) {
                                        //selected powerup 3 EMP
                                        if (Research->power_available and Research->loyalty == "Blue"){
                                            selected_origin_blue = NULL;
                                            if (power_is_selected_blue){
                                                if (selected_power_blue == "EMP"){
                                                    power_is_selected_blue = false;
                                                    selected_power_blue = "None";
                                                }else{
                                                    selected_power_blue = "EMP";
                                                }
                                            }else{
                                                power_is_selected_blue = true;
                                                selected_power_blue = "EMP";
                                            }
                                        }

                                    }else if ((click_x > ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*0.25/30))*SCALING_FACTOR_X) and (click_x < ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*2.25/30))*SCALING_FACTOR_X) and (click_y < (SCREEN_HEIGHT*29/30)*SCALING_FACTOR_Y) and (click_y > (SCREEN_HEIGHT*27/30)*SCALING_FACTOR_Y)) {
                                        //selected powerup 4 Road Block
                                        if (OAT->power_available and OAT->loyalty == "Blue"){
                                            selected_origin_blue = NULL;
                                            if (power_is_selected_blue){
                                                if (selected_power_blue == "Road Block"){
                                                    power_is_selected_blue = false;
                                                    selected_power_blue = "None";
                                                }else{
                                                    selected_power_blue = "Road Block";
                                                }
                                            }else{
                                                power_is_selected_blue = true;
                                                selected_power_blue = "Road Block";
                                            }
                                        }

                                    }else if ((click_x > ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*2.75/30))*SCALING_FACTOR_X) and (click_x < ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*4.75/30))*SCALING_FACTOR_X) and (click_y < (SCREEN_HEIGHT*29/30)*SCALING_FACTOR_Y) and (click_y > (SCREEN_HEIGHT*27/30)*SCALING_FACTOR_Y)) {
                                        //selected powerup 5 Freeze
                                        if (LHC->power_available and LHC->loyalty == "Blue"){
                                            selected_origin_blue = NULL;
                                            if (power_is_selected_blue){
                                                if (selected_power_blue == "Freeze"){
                                                    power_is_selected_blue = false;
                                                    selected_power_blue = "None";
                                                }else{
                                                    selected_power_blue = "Freeze";
                                                }
                                            }else{
                                                power_is_selected_blue = true;
                                                selected_power_blue = "Freeze";
                                            }
                                        }

                                    }else if ((click_x > ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*5.25/30))*SCALING_FACTOR_X) and (click_x < ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*7.25/30))*SCALING_FACTOR_X) and (click_y < (SCREEN_HEIGHT*29/30)*SCALING_FACTOR_Y) and (click_y > (SCREEN_HEIGHT*27/30)*SCALING_FACTOR_Y)) {
                                        //selected powerup 6 Acid Circle
                                        if (Apartments_girls->power_available and Apartments_girls->loyalty == "Blue"){
                                            selected_origin_blue = NULL;
                                            if (power_is_selected_blue){
                                                if (selected_power_blue == "Acid Circle"){
                                                    power_is_selected_blue = false;
                                                    selected_power_blue = "None";
                                                }else{
                                                    selected_power_blue = "Acid Circle";
                                                }
                                            }else{
                                                power_is_selected_blue = true;
                                                selected_power_blue = "Acid Circle";
                                            }
                                        }
                                    }


                                    // applying the selected power
                                    else if (power_is_selected_blue){
                                        power_is_selected_blue = false;


                                        if (selected_power_blue=="Fire Circle"){// works only on moving soldiers
                                            Apartments_boys->power_available = false;
                                            Apartments_boys->power_circle_centre_x = Current_view_x + (click_x)/(SCALING_FACTOR_X);
                                            Apartments_boys->power_circle_centre_y = Current_view_y + (click_y)/(SCALING_FACTOR_Y);
                                            Apartments_boys->power_stay_time = 2;
                                            Apartments_boys->radius = 180;
                                            Apartments_boys->power_restore_time = 15;
                                            Apartments_boys->power_strength = 10;

                                            Mix_PlayChannel( -1, gFire_sound, 0 );

                                        }

                                        else if(selected_power_blue=="Shield"){// works only on buildings


                                            bool correct_place_click = false;

                                            if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 366) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 454) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 169) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 286) and (Jwala->loyalty == Hospital->loyalty) ) {Hospital->power_circle_centre_x = Jwala->x; Hospital->power_circle_centre_y = Jwala->y ; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 735) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 881) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 201) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 298) and (Blue_Home->loyalty == Hospital->loyalty) ) {Hospital->power_circle_centre_x = Blue_Home->x; Hospital->power_circle_centre_y = Blue_Home->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 355) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 438) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 507) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 619) and (Kara->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Kara->x; Hospital->power_circle_centre_y = Kara->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 815) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 936) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 567) and (Masala->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Masala->x; Hospital->power_circle_centre_y = Masala->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1041) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1187) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 453) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 572) and (Hospital->loyalty == Hospital->loyalty) ) {Hospital->power_circle_centre_x = Hospital->x; Hospital->power_circle_centre_y = Hospital->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1487) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1855) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 231) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 385) and (Main_building->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Main_building->x; Hospital->power_circle_centre_y = Main_building->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 175) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 267) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 756) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 860) and (Apartments_boys->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Apartments_boys->x; Hospital->power_circle_centre_y = Apartments_boys->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 763) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 877) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 807) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 914) and (OAT->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = OAT->x; Hospital->power_circle_centre_y = OAT->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1197) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 665) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 836) and (Playground->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Playground->x; Hospital->power_circle_centre_y = Playground->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1409) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1650) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 927) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 1046) and (Research->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Research->x; Hospital->power_circle_centre_y = Research->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1627) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1803) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 448) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 564) and (Library->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Library->x; Hospital->power_circle_centre_y = Library->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2571) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2693) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 712) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 848) and (Apartments_girls->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Apartments_girls->x; Hospital->power_circle_centre_y = Apartments_girls->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2008) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2230) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 611) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 769) and (LHC->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = LHC->x; Hospital->power_circle_centre_y = LHC->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2229) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2385) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 176) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 278) and (Red_Home->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Red_Home->x; Hospital->power_circle_centre_y = Red_Home->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2613) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2708) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 444) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 536) and (Market->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Market->x; Hospital->power_circle_centre_y = Market->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2606) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2727) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 249) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 349) and (Amaltas->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Amaltas->x; Hospital->power_circle_centre_y = Amaltas->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2208) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2366) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 428) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 542) and (School->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = School->x; Hospital->power_circle_centre_y = School->y; correct_place_click = true;}


                                            if (correct_place_click){
                                                Hospital->power_available = false;
                                                Hospital->power_stay_time = 2;
                                                Hospital->radius = 200;
                                                Hospital->power_restore_time = 15;

                                                Mix_PlayChannel( -1, gShield_sound, 0 );
                                            }
                                        }




                                        else if(selected_power_blue=="EMP"){// works only on buildings

                                            bool correct_place_click = false;

                                            if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 366) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 454) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 169) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 286) and (Jwala->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Jwala->x; Research->power_circle_centre_y = Jwala->y ; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 735) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 881) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 201) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 298) and (Blue_Home->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Blue_Home->x; Research->power_circle_centre_y = Blue_Home->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 355) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 438) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 507) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 619) and (Kara->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Kara->x; Research->power_circle_centre_y = Kara->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 815) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 936) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 567) and (Masala->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Masala->x; Research->power_circle_centre_y = Masala->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1041) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1187) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 453) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 572) and (Hospital->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Hospital->x; Research->power_circle_centre_y = Hospital->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1487) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1855) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 231) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 385) and (Main_building->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Main_building->x; Research->power_circle_centre_y = Main_building->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 175) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 267) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 756) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 860) and (Apartments_boys->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Apartments_boys->x; Research->power_circle_centre_y = Apartments_boys->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 763) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 877) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 807) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 914) and (OAT->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = OAT->x; Research->power_circle_centre_y = OAT->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1197) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 665) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 836) and (Playground->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Playground->x; Research->power_circle_centre_y = Playground->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1409) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1650) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 927) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 1046) and (Research->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Research->x; Research->power_circle_centre_y = Research->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1627) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1803) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 448) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 564) and (Library->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Library->x; Research->power_circle_centre_y = Library->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2571) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2693) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 712) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 848) and (Apartments_girls->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Apartments_girls->x; Research->power_circle_centre_y = Apartments_girls->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2008) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2230) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 611) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 769) and (LHC->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = LHC->x; Research->power_circle_centre_y = LHC->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2229) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2385) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 176) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 278) and (Red_Home->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Red_Home->x; Research->power_circle_centre_y = Red_Home->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2613) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2708) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 444) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 536) and (Market->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Market->x; Research->power_circle_centre_y = Market->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2606) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2727) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 249) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 349) and (Amaltas->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Amaltas->x; Research->power_circle_centre_y = Amaltas->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2208) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2366) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 428) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 542) and (School->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = School->x; Research->power_circle_centre_y = School->y; correct_place_click = true;}
                                            
                                            if (correct_place_click){
                                                Research->power_stay_time = 1;
                                                Research->radius = 150;
                                                Research->power_restore_time = 15;
                                                Research->power_strength = 18;

                                                Mix_PlayChannel( -1, gEMP_sound, 0 );

                                            }else{
                                                // display error, click on an enemy building
                                            }



                                        }

                                        else if (selected_power_blue=="Road Block"){// works only on roads
                                            OAT->power_available = false;
                                            OAT->power_circle_centre_x = Current_view_x + (click_x)/(SCALING_FACTOR_X);
                                            OAT->power_circle_centre_y = Current_view_y + (click_y)/(SCALING_FACTOR_Y);
                                            OAT->power_stay_time = 4;
                                            OAT->radius = 40;
                                            OAT->power_restore_time = 15;

                                            Mix_PlayChannel( -1, gWall_sound, 0 );
                                        }

                                        else if (selected_power_blue=="Freeze"){// works on every action of the opponent 
                                            LHC->power_available = false;
                                            LHC->power_stay_time = 4;
                                            LHC->power_restore_time = 15;

                                            Mix_PlayChannel( -1, gFreeze_sound, 0 );
                                        }

                                        else if (selected_power_blue=="Acid Circle"){// works only on moving targets
                                            Apartments_girls->power_available = false;
                                            Apartments_girls->power_circle_centre_x = Current_view_x + (click_x)/(SCALING_FACTOR_X);
                                            Apartments_girls->power_circle_centre_y = Current_view_y + (click_y)/(SCALING_FACTOR_Y);
                                            Apartments_girls->power_stay_time = 2;
                                            Apartments_girls->radius = 180;
                                            Apartments_girls->power_restore_time = 15;
                                            Apartments_girls->power_strength = 10;

                                            Mix_PlayChannel( -1, gAcid_sound, 0 );
                                        }

                                        selected_power_blue = "None";
                                    }

                                    // using equation of ellipse: x^2/a^2 + y^2/b^2 < 1 for an inside point

                                    //selecting origin
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 366) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 454) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 169) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 286) and (Jwala->loyalty == "Blue") ) {selected_origin_blue = Jwala;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 735) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 881) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 201) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 298) and (Blue_Home->loyalty == "Blue") ) {selected_origin_blue = Blue_Home;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 355) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 438) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 507) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 619) and (Kara->loyalty == "Blue") ) {selected_origin_blue = Kara;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 815) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 936) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 567) and (Masala->loyalty == "Blue") ) {selected_origin_blue = Masala;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1041) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1187) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 453) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 572) and (Hospital->loyalty == "Blue") ) {selected_origin_blue = Hospital;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1487) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1855) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 231) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 385) and (Main_building->loyalty == "Blue") ) {selected_origin_blue = Main_building;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 175) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 267) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 756) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 860) and (Apartments_boys->loyalty == "Blue") ) {selected_origin_blue = Apartments_boys;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 763) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 877) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 807) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 914) and (OAT->loyalty == "Blue") ) {selected_origin_blue = OAT;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1197) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 665) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 836) and (Playground->loyalty == "Blue") ) {selected_origin_blue = Playground;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1409) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1650) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 927) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 1046) and (Research->loyalty == "Blue") ) {selected_origin_blue = Research;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1627) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1803) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 448) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 564) and (Library->loyalty == "Blue") ) {selected_origin_blue = Library;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2571) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2693) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 712) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 848) and (Apartments_girls->loyalty == "Blue") ) {selected_origin_blue = Apartments_girls;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2008) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2230) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 611) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 769) and (LHC->loyalty == "Blue") ) {selected_origin_blue = LHC;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2229) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2385) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 176) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 278) and (Red_Home->loyalty == "Blue") ) {selected_origin_blue = Red_Home;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2613) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2708) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 444) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 536) and (Market->loyalty == "Blue") ) {selected_origin_blue = Market;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2606) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2727) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 249) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 349) and (Amaltas->loyalty == "Blue") ) {selected_origin_blue = Amaltas;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2208) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2366) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 428) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 542) and (School->loyalty == "Blue") ) {selected_origin_blue = School;}

                                break;





                                case SDL_BUTTON_RIGHT:
                                    isright = 1;
                                    isleft = 0;
                                    if ((selected_origin_blue!=NULL) and (!power_is_selected_blue)){

                                        // Rectangle selection instead of ellipse here. Ellipse to be used for power circles. 

                                        // selecting destination
                                        if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 366) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 454) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 169) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 286) ) {selected_destination_blue = Jwala;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 735) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 881) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 201) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 298) ) {selected_destination_blue = Blue_Home;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 355) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 438) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 507) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 619) ) {selected_destination_blue = Kara;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 815) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 936) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 567) ) {selected_destination_blue = Masala;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1041) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1187) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 453) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 572) ) {selected_destination_blue = Hospital;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1487) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1855) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 231) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 385) ) {selected_destination_blue = Main_building;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 175) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 267) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 756) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 860) ) {selected_destination_blue = Apartments_boys;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 763) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 877) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 807) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 914) ) {selected_destination_blue = OAT;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1197) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 665) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 836) ) {selected_destination_blue = Playground;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1409) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1650) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 927) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 1046) ) {selected_destination_blue = Research;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1627) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1803) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 448) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 564) ) {selected_destination_blue = Library;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2571) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2693) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 712) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 848) ) {selected_destination_blue = Apartments_girls;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2008) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2230) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 611) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 769) ) {selected_destination_blue = LHC;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2229) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2385) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 176) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 278) ) {selected_destination_blue = Red_Home;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2613) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2708) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 444) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 536) ) {selected_destination_blue = Market;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2606) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2727) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 249) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 349) ) {selected_destination_blue = Amaltas;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2208) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2366) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 428) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 542) ) {selected_destination_blue = School;}

                                        else {selected_destination_blue = NULL;}

                                        if ((!(selected_origin_blue==selected_destination_blue)) and selected_destination_blue!=NULL){
                                            int outgoing = selected_origin_blue->send_half();
                                            if (outgoing!=0){
                                                create_packet(outgoing, selected_origin_blue, selected_destination_blue);
                                            }
                                        }

                                        selected_origin_blue = NULL;
                                        selected_destination_blue = NULL;

                                    }else{
                                        // ERROR: select an origin first!
                                    }
                                break; 
                            }
                        }
                    }




                    // settings for other player (Red here)

                    // text[] = {state, clicked, isleft, isright, click_x, click_y, Current_view_x, Current_view_y, isquit}

                    if (!(quit)){
                        if (other_player[10] == 1){
                            quit = true;
                            isquit = 1;
                        }
                        else if ((other_player[1]==1) and !((LHC->power_stay_time > 0) and (LHC->loyalty == "Blue"))){ // other_player has clicked on the screen and is not freezed
                                if (other_player[2]==1){ // other player did a left click

                                    // the six power buttons

                                    if ((other_player[4] > ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*7.25/30))*other_player[8]) and (other_player[4] < ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*5.25/30))*other_player[8]) and (other_player[5] < (SCREEN_HEIGHT*29/30)*other_player[9]) and (other_player[5] > (SCREEN_HEIGHT*27/30)*other_player[9])) {
                                        // selected powerup 1 Fire Circle
                                        if (Apartments_boys->power_available and Apartments_boys->loyalty == "Red"){
                                            selected_origin_red = NULL;
                                            if (power_is_selected_red){
                                                if (selected_power_red == "Fire Circle"){
                                                    power_is_selected_red = false;
                                                    selected_power_red = "None";
                                                }else{
                                                    selected_power_red = "Fire Circle";
                                                }
                                            }else{
                                                power_is_selected_red = true;
                                                selected_power_red = "Fire Circle";
                                            }
                                        }

                                    }else if ((other_player[4] > ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*4.75/30))*other_player[8]) and (other_player[4] < ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*2.75/30))*other_player[8]) and (other_player[5] < (SCREEN_HEIGHT*29/30)*other_player[9]) and (other_player[5] > (SCREEN_HEIGHT*27/30)*other_player[9])) {
                                        //selected powerup 2 Shield
                                        if (Hospital->power_available and Hospital->loyalty == "Red"){
                                            selected_origin_red = NULL;
                                            if (power_is_selected_red){
                                                if (selected_power_red == "Shield"){
                                                    power_is_selected_red = false;
                                                    selected_power_red = "None";
                                                }else{
                                                    selected_power_red = "Shield";
                                                }
                                            }else{
                                                power_is_selected_red = true;
                                                selected_power_red = "Shield";
                                            }
                                        }

                                    }else if ((other_player[4] > ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*2.25/30))*other_player[8]) and (other_player[4] < ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*0.25/30))*other_player[8]) and (other_player[5] < (SCREEN_HEIGHT*29/30)*other_player[9]) and (other_player[5] > (SCREEN_HEIGHT*27/30)*other_player[9])) {
                                        //selected powerup 3 EMP
                                        if (Research->power_available and Research->loyalty == "Red"){
                                            selected_origin_red = NULL;
                                            if (power_is_selected_red){
                                                if (selected_power_red == "EMP"){
                                                    power_is_selected_red = false;
                                                    selected_power_red = "None";
                                                }else{
                                                    selected_power_red = "EMP";
                                                }
                                            }else{
                                                power_is_selected_red = true;
                                                selected_power_red = "EMP";
                                            }
                                        }

                                    }else if ((other_player[4] > ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*0.25/30))*other_player[8]) and (other_player[4] < ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*2.25/30))*other_player[8]) and (other_player[5] < (SCREEN_HEIGHT*29/30)*other_player[9]) and (other_player[5] > (SCREEN_HEIGHT*27/30)*other_player[9])) {
                                        //selected powerup 4 Road Block
                                        if (OAT->power_available and OAT->loyalty == "Red"){
                                            selected_origin_red = NULL;
                                            if (power_is_selected_red){
                                                if (selected_power_red == "Road Block"){
                                                    power_is_selected_red = false;
                                                    selected_power_red = "None";
                                                }else{
                                                    selected_power_red = "Road Block";
                                                }
                                            }else{
                                                power_is_selected_red = true;
                                                selected_power_red = "Road Block";
                                            }
                                        }

                                    }else if ((other_player[4] > ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*2.75/30))*other_player[8]) and (other_player[4] < ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*4.75/30))*other_player[8]) and (other_player[5] < (SCREEN_HEIGHT*29/30)*other_player[9]) and (other_player[5] > (SCREEN_HEIGHT*27/30)*other_player[9])) {
                                        //selected powerup 5 Freeze
                                        if (LHC->power_available and LHC->loyalty == "Red"){
                                            selected_origin_red = NULL;
                                            if (power_is_selected_red){
                                                if (selected_power_red == "Freeze"){
                                                    power_is_selected_red = false;
                                                    selected_power_red = "None";
                                                }else{
                                                    selected_power_red = "Freeze";
                                                }
                                            }else{
                                                power_is_selected_red = true;
                                                selected_power_red = "Freeze";
                                            }
                                        }

                                    }else if ((other_player[4] > ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*5.25/30))*other_player[8]) and (other_player[4] < ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*7.25/30))*other_player[8]) and (other_player[5] < (SCREEN_HEIGHT*29/30)*other_player[9]) and (other_player[5] > (SCREEN_HEIGHT*27/30)*other_player[9])) {
                                        //selected powerup 6 Acid Circle
                                        if (Apartments_girls->power_available and Apartments_girls->loyalty == "Red"){
                                            selected_origin_red = NULL;
                                            if (power_is_selected_red){
                                                if (selected_power_red == "Acid Circle"){
                                                    power_is_selected_red = false;
                                                    selected_power_red = "None";
                                                }else{
                                                    selected_power_red = "Acid Circle";
                                                }
                                            }else{
                                                power_is_selected_red = true;
                                                selected_power_red = "Acid Circle";
                                            }
                                        }
                                    }


                                    // applying the selected power
                                    else if (power_is_selected_red){
                                        power_is_selected_red = false;


                                        if (selected_power_red=="Fire Circle"){// works only on moving soldiers
                                            Apartments_boys->power_available = false;
                                            Apartments_boys->power_circle_centre_x = other_player[6] + (other_player[4])/(other_player[8]);
                                            Apartments_boys->power_circle_centre_y = other_player[7] + (other_player[5])/(other_player[9]);
                                            Apartments_boys->power_stay_time = 2;
                                            Apartments_boys->radius = 180;
                                            Apartments_boys->power_restore_time = 15;
                                            Apartments_boys->power_strength = 10;

                                            Mix_PlayChannel( -1, gFire_sound, 0 );

                                        }

                                        else if(selected_power_red=="Shield"){// works only on buildings


                                            bool correct_place_click = false;

                                            if ((other_player[6] + (other_player[4])/(other_player[8]) > 366) and (other_player[6] + (other_player[4])/(other_player[8]) < 454) and (other_player[7] + (other_player[5])/(other_player[9]) > 169) and (other_player[7] + (other_player[5])/(other_player[9]) < 286) and (Jwala->loyalty == Hospital->loyalty) ) {Hospital->power_circle_centre_x = Jwala->x; Hospital->power_circle_centre_y = Jwala->y ; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 735) and (other_player[6] + (other_player[4])/(other_player[8]) < 881) and (other_player[7] + (other_player[5])/(other_player[9]) > 201) and (other_player[7] + (other_player[5])/(other_player[9]) < 298) and (Blue_Home->loyalty == Hospital->loyalty) ) {Hospital->power_circle_centre_x = Blue_Home->x; Hospital->power_circle_centre_y = Blue_Home->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 355) and (other_player[6] + (other_player[4])/(other_player[8]) < 438) and (other_player[7] + (other_player[5])/(other_player[9]) > 507) and (other_player[7] + (other_player[5])/(other_player[9]) < 619) and (Kara->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Kara->x; Hospital->power_circle_centre_y = Kara->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 815) and (other_player[6] + (other_player[4])/(other_player[8]) < 936) and (other_player[7] + (other_player[5])/(other_player[9]) > 471) and (other_player[7] + (other_player[5])/(other_player[9]) < 567) and (Masala->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Masala->x; Hospital->power_circle_centre_y = Masala->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1041) and (other_player[6] + (other_player[4])/(other_player[8]) < 1187) and (other_player[7] + (other_player[5])/(other_player[9]) > 453) and (other_player[7] + (other_player[5])/(other_player[9]) < 572) and (Hospital->loyalty == Hospital->loyalty) ) {Hospital->power_circle_centre_x = Hospital->x; Hospital->power_circle_centre_y = Hospital->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1487) and (other_player[6] + (other_player[4])/(other_player[8]) < 1855) and (other_player[7] + (other_player[5])/(other_player[9]) > 231) and (other_player[7] + (other_player[5])/(other_player[9]) < 385) and (Main_building->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Main_building->x; Hospital->power_circle_centre_y = Main_building->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 175) and (other_player[6] + (other_player[4])/(other_player[8]) < 267) and (other_player[7] + (other_player[5])/(other_player[9]) > 756) and (other_player[7] + (other_player[5])/(other_player[9]) < 860) and (Apartments_boys->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Apartments_boys->x; Hospital->power_circle_centre_y = Apartments_boys->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 763) and (other_player[6] + (other_player[4])/(other_player[8]) < 877) and (other_player[7] + (other_player[5])/(other_player[9]) > 807) and (other_player[7] + (other_player[5])/(other_player[9]) < 914) and (OAT->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = OAT->x; Hospital->power_circle_centre_y = OAT->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1197) and (other_player[6] + (other_player[4])/(other_player[8]) < 1471) and (other_player[7] + (other_player[5])/(other_player[9]) > 665) and (other_player[7] + (other_player[5])/(other_player[9]) < 836) and (Playground->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Playground->x; Hospital->power_circle_centre_y = Playground->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1409) and (other_player[6] + (other_player[4])/(other_player[8]) < 1650) and (other_player[7] + (other_player[5])/(other_player[9]) > 927) and (other_player[7] + (other_player[5])/(other_player[9]) < 1046) and (Research->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Research->x; Hospital->power_circle_centre_y = Research->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1627) and (other_player[6] + (other_player[4])/(other_player[8]) < 1803) and (other_player[7] + (other_player[5])/(other_player[9]) > 448) and (other_player[7] + (other_player[5])/(other_player[9]) < 564) and (Library->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Library->x; Hospital->power_circle_centre_y = Library->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2571) and (other_player[6] + (other_player[4])/(other_player[8]) < 2693) and (other_player[7] + (other_player[5])/(other_player[9]) > 712) and (other_player[7] + (other_player[5])/(other_player[9]) < 848) and (Apartments_girls->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Apartments_girls->x; Hospital->power_circle_centre_y = Apartments_girls->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2008) and (other_player[6] + (other_player[4])/(other_player[8]) < 2230) and (other_player[7] + (other_player[5])/(other_player[9]) > 611) and (other_player[7] + (other_player[5])/(other_player[9]) < 769) and (LHC->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = LHC->x; Hospital->power_circle_centre_y = LHC->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2229) and (other_player[6] + (other_player[4])/(other_player[8]) < 2385) and (other_player[7] + (other_player[5])/(other_player[9]) > 176) and (other_player[7] + (other_player[5])/(other_player[9]) < 278) and (Red_Home->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Red_Home->x; Hospital->power_circle_centre_y = Red_Home->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2613) and (other_player[6] + (other_player[4])/(other_player[8]) < 2708) and (other_player[7] + (other_player[5])/(other_player[9]) > 444) and (other_player[7] + (other_player[5])/(other_player[9]) < 536) and (Market->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Market->x; Hospital->power_circle_centre_y = Market->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2606) and (other_player[6] + (other_player[4])/(other_player[8]) < 2727) and (other_player[7] + (other_player[5])/(other_player[9]) > 249) and (other_player[7] + (other_player[5])/(other_player[9]) < 349) and (Amaltas->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Amaltas->x; Hospital->power_circle_centre_y = Amaltas->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2208) and (other_player[6] + (other_player[4])/(other_player[8]) < 2366) and (other_player[7] + (other_player[5])/(other_player[9]) > 428) and (other_player[7] + (other_player[5])/(other_player[9]) < 542) and (School->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = School->x; Hospital->power_circle_centre_y = School->y; correct_place_click = true;}


                                            if (correct_place_click){
                                                Hospital->power_available = false;
                                                Hospital->power_stay_time = 2;
                                                Hospital->radius = 200;
                                                Hospital->power_restore_time = 15;

                                                Mix_PlayChannel( -1, gShield_sound, 0 );
                                            }
                                        }




                                        else if(selected_power_red=="EMP"){// works only on buildings

                                            bool correct_place_click = false;

                                            if ((other_player[6] + (other_player[4])/(other_player[8]) > 366) and (other_player[6] + (other_player[4])/(other_player[8]) < 454) and (other_player[7] + (other_player[5])/(other_player[9]) > 169) and (other_player[7] + (other_player[5])/(other_player[9]) < 286) and (Jwala->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Jwala->x; Research->power_circle_centre_y = Jwala->y ; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 735) and (other_player[6] + (other_player[4])/(other_player[8]) < 881) and (other_player[7] + (other_player[5])/(other_player[9]) > 201) and (other_player[7] + (other_player[5])/(other_player[9]) < 298) and (Blue_Home->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Blue_Home->x; Research->power_circle_centre_y = Blue_Home->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 355) and (other_player[6] + (other_player[4])/(other_player[8]) < 438) and (other_player[7] + (other_player[5])/(other_player[9]) > 507) and (other_player[7] + (other_player[5])/(other_player[9]) < 619) and (Kara->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Kara->x; Research->power_circle_centre_y = Kara->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 815) and (other_player[6] + (other_player[4])/(other_player[8]) < 936) and (other_player[7] + (other_player[5])/(other_player[9]) > 471) and (other_player[7] + (other_player[5])/(other_player[9]) < 567) and (Masala->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Masala->x; Research->power_circle_centre_y = Masala->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1041) and (other_player[6] + (other_player[4])/(other_player[8]) < 1187) and (other_player[7] + (other_player[5])/(other_player[9]) > 453) and (other_player[7] + (other_player[5])/(other_player[9]) < 572) and (Hospital->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Hospital->x; Research->power_circle_centre_y = Hospital->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1487) and (other_player[6] + (other_player[4])/(other_player[8]) < 1855) and (other_player[7] + (other_player[5])/(other_player[9]) > 231) and (other_player[7] + (other_player[5])/(other_player[9]) < 385) and (Main_building->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Main_building->x; Research->power_circle_centre_y = Main_building->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 175) and (other_player[6] + (other_player[4])/(other_player[8]) < 267) and (other_player[7] + (other_player[5])/(other_player[9]) > 756) and (other_player[7] + (other_player[5])/(other_player[9]) < 860) and (Apartments_boys->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Apartments_boys->x; Research->power_circle_centre_y = Apartments_boys->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 763) and (other_player[6] + (other_player[4])/(other_player[8]) < 877) and (other_player[7] + (other_player[5])/(other_player[9]) > 807) and (other_player[7] + (other_player[5])/(other_player[9]) < 914) and (OAT->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = OAT->x; Research->power_circle_centre_y = OAT->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1197) and (other_player[6] + (other_player[4])/(other_player[8]) < 1471) and (other_player[7] + (other_player[5])/(other_player[9]) > 665) and (other_player[7] + (other_player[5])/(other_player[9]) < 836) and (Playground->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Playground->x; Research->power_circle_centre_y = Playground->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1409) and (other_player[6] + (other_player[4])/(other_player[8]) < 1650) and (other_player[7] + (other_player[5])/(other_player[9]) > 927) and (other_player[7] + (other_player[5])/(other_player[9]) < 1046) and (Research->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Research->x; Research->power_circle_centre_y = Research->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1627) and (other_player[6] + (other_player[4])/(other_player[8]) < 1803) and (other_player[7] + (other_player[5])/(other_player[9]) > 448) and (other_player[7] + (other_player[5])/(other_player[9]) < 564) and (Library->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Library->x; Research->power_circle_centre_y = Library->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2571) and (other_player[6] + (other_player[4])/(other_player[8]) < 2693) and (other_player[7] + (other_player[5])/(other_player[9]) > 712) and (other_player[7] + (other_player[5])/(other_player[9]) < 848) and (Apartments_girls->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Apartments_girls->x; Research->power_circle_centre_y = Apartments_girls->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2008) and (other_player[6] + (other_player[4])/(other_player[8]) < 2230) and (other_player[7] + (other_player[5])/(other_player[9]) > 611) and (other_player[7] + (other_player[5])/(other_player[9]) < 769) and (LHC->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = LHC->x; Research->power_circle_centre_y = LHC->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2229) and (other_player[6] + (other_player[4])/(other_player[8]) < 2385) and (other_player[7] + (other_player[5])/(other_player[9]) > 176) and (other_player[7] + (other_player[5])/(other_player[9]) < 278) and (Red_Home->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Red_Home->x; Research->power_circle_centre_y = Red_Home->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2613) and (other_player[6] + (other_player[4])/(other_player[8]) < 2708) and (other_player[7] + (other_player[5])/(other_player[9]) > 444) and (other_player[7] + (other_player[5])/(other_player[9]) < 536) and (Market->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Market->x; Research->power_circle_centre_y = Market->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2606) and (other_player[6] + (other_player[4])/(other_player[8]) < 2727) and (other_player[7] + (other_player[5])/(other_player[9]) > 249) and (other_player[7] + (other_player[5])/(other_player[9]) < 349) and (Amaltas->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Amaltas->x; Research->power_circle_centre_y = Amaltas->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2208) and (other_player[6] + (other_player[4])/(other_player[8]) < 2366) and (other_player[7] + (other_player[5])/(other_player[9]) > 428) and (other_player[7] + (other_player[5])/(other_player[9]) < 542) and (School->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = School->x; Research->power_circle_centre_y = School->y; correct_place_click = true;}
                                            
                                            if (correct_place_click){
                                                Research->power_stay_time = 1;
                                                Research->radius = 150;
                                                Research->power_restore_time = 15;
                                                Research->power_strength = 15;

                                                Mix_PlayChannel( -1, gEMP_sound, 0 );

                                            }else{
                                                // display error, click on an enemy building
                                            }



                                        }

                                        else if (selected_power_red=="Road Block"){// works only on roads
                                            OAT->power_available = false;
                                            OAT->power_circle_centre_x = other_player[6] + (other_player[4])/(other_player[8]);
                                            OAT->power_circle_centre_y = other_player[7] + (other_player[5])/(other_player[9]);
                                            OAT->power_stay_time = 4;
                                            OAT->radius = 40;
                                            OAT->power_restore_time = 15;

                                            Mix_PlayChannel( -1, gWall_sound, 0 );
                                        }

                                        else if (selected_power_red=="Freeze"){// works on every action of the opponent 
                                            LHC->power_available = false;
                                            LHC->power_stay_time = 4;
                                            LHC->power_restore_time = 15;

                                            Mix_PlayChannel( -1, gFreeze_sound, 0 );
                                        }

                                        else if (selected_power_red=="Acid Circle"){// works only on moving targets
                                            Apartments_girls->power_available = false;
                                            Apartments_girls->power_circle_centre_x = other_player[6] + (other_player[4])/(other_player[8]);
                                            Apartments_girls->power_circle_centre_y = other_player[7] + (other_player[5])/(other_player[9]);
                                            Apartments_girls->power_stay_time = 2;
                                            Apartments_girls->radius = 180;
                                            Apartments_girls->power_restore_time = 15;
                                            Apartments_girls->power_strength = 10;

                                            Mix_PlayChannel( -1, gAcid_sound, 0 );
                                        }

                                        selected_power_red = "None";
                                    }

                                    // using equation of ellipse: x^2/a^2 + y^2/b^2 < 1 for an inside point

                                    //selecting origin
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 366) and (other_player[6] + (other_player[4])/(other_player[8]) < 454) and (other_player[7] + (other_player[5])/(other_player[9]) > 169) and (other_player[7] + (other_player[5])/(other_player[9]) < 286) and (Jwala->loyalty == "Red") ) {selected_origin_red = Jwala;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 735) and (other_player[6] + (other_player[4])/(other_player[8]) < 881) and (other_player[7] + (other_player[5])/(other_player[9]) > 201) and (other_player[7] + (other_player[5])/(other_player[9]) < 298) and (Blue_Home->loyalty == "Red") ) {selected_origin_red = Blue_Home;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 355) and (other_player[6] + (other_player[4])/(other_player[8]) < 438) and (other_player[7] + (other_player[5])/(other_player[9]) > 507) and (other_player[7] + (other_player[5])/(other_player[9]) < 619) and (Kara->loyalty == "Red") ) {selected_origin_red = Kara;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 815) and (other_player[6] + (other_player[4])/(other_player[8]) < 936) and (other_player[7] + (other_player[5])/(other_player[9]) > 471) and (other_player[7] + (other_player[5])/(other_player[9]) < 567) and (Masala->loyalty == "Red") ) {selected_origin_red = Masala;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1041) and (other_player[6] + (other_player[4])/(other_player[8]) < 1187) and (other_player[7] + (other_player[5])/(other_player[9]) > 453) and (other_player[7] + (other_player[5])/(other_player[9]) < 572) and (Hospital->loyalty == "Red") ) {selected_origin_red = Hospital;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1487) and (other_player[6] + (other_player[4])/(other_player[8]) < 1855) and (other_player[7] + (other_player[5])/(other_player[9]) > 231) and (other_player[7] + (other_player[5])/(other_player[9]) < 385) and (Main_building->loyalty == "Red") ) {selected_origin_red = Main_building;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 175) and (other_player[6] + (other_player[4])/(other_player[8]) < 267) and (other_player[7] + (other_player[5])/(other_player[9]) > 756) and (other_player[7] + (other_player[5])/(other_player[9]) < 860) and (Apartments_boys->loyalty == "Red") ) {selected_origin_red = Apartments_boys;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 763) and (other_player[6] + (other_player[4])/(other_player[8]) < 877) and (other_player[7] + (other_player[5])/(other_player[9]) > 807) and (other_player[7] + (other_player[5])/(other_player[9]) < 914) and (OAT->loyalty == "Red") ) {selected_origin_red = OAT;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1197) and (other_player[6] + (other_player[4])/(other_player[8]) < 1471) and (other_player[7] + (other_player[5])/(other_player[9]) > 665) and (other_player[7] + (other_player[5])/(other_player[9]) < 836) and (Playground->loyalty == "Red") ) {selected_origin_red = Playground;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1409) and (other_player[6] + (other_player[4])/(other_player[8]) < 1650) and (other_player[7] + (other_player[5])/(other_player[9]) > 927) and (other_player[7] + (other_player[5])/(other_player[9]) < 1046) and (Research->loyalty == "Red") ) {selected_origin_red = Research;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1627) and (other_player[6] + (other_player[4])/(other_player[8]) < 1803) and (other_player[7] + (other_player[5])/(other_player[9]) > 448) and (other_player[7] + (other_player[5])/(other_player[9]) < 564) and (Library->loyalty == "Red") ) {selected_origin_red = Library;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2571) and (other_player[6] + (other_player[4])/(other_player[8]) < 2693) and (other_player[7] + (other_player[5])/(other_player[9]) > 712) and (other_player[7] + (other_player[5])/(other_player[9]) < 848) and (Apartments_girls->loyalty == "Red") ) {selected_origin_red = Apartments_girls;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2008) and (other_player[6] + (other_player[4])/(other_player[8]) < 2230) and (other_player[7] + (other_player[5])/(other_player[9]) > 611) and (other_player[7] + (other_player[5])/(other_player[9]) < 769) and (LHC->loyalty == "Red") ) {selected_origin_red = LHC;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2229) and (other_player[6] + (other_player[4])/(other_player[8]) < 2385) and (other_player[7] + (other_player[5])/(other_player[9]) > 176) and (other_player[7] + (other_player[5])/(other_player[9]) < 278) and (Red_Home->loyalty == "Red") ) {selected_origin_red = Red_Home;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2613) and (other_player[6] + (other_player[4])/(other_player[8]) < 2708) and (other_player[7] + (other_player[5])/(other_player[9]) > 444) and (other_player[7] + (other_player[5])/(other_player[9]) < 536) and (Market->loyalty == "Red") ) {selected_origin_red = Market;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2606) and (other_player[6] + (other_player[4])/(other_player[8]) < 2727) and (other_player[7] + (other_player[5])/(other_player[9]) > 249) and (other_player[7] + (other_player[5])/(other_player[9]) < 349) and (Amaltas->loyalty == "Red") ) {selected_origin_red = Amaltas;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2208) and (other_player[6] + (other_player[4])/(other_player[8]) < 2366) and (other_player[7] + (other_player[5])/(other_player[9]) > 428) and (other_player[7] + (other_player[5])/(other_player[9]) < 542) and (School->loyalty == "Red") ) {selected_origin_red = School;}








                                }else if (other_player[3]==1) { // other player did a right click
                                    if ((selected_origin_red!=NULL) and (!power_is_selected_red)){

                                        // Rectangle selection instead of ellipse here. Ellipse to be used for power circles. 

                                        // selecting destination
                                        if ((other_player[6] + (other_player[4])/(other_player[8]) > 366) and (other_player[6] + (other_player[4])/(other_player[8]) < 454) and (other_player[7]+ (other_player[5])/(other_player[9]) > 169) and (other_player[7]+ (other_player[5])/(other_player[9]) < 286) ) {selected_destination_red = Jwala;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 735) and (other_player[6] + (other_player[4])/(other_player[8]) < 881) and (other_player[7]+ (other_player[5])/(other_player[9]) > 201) and (other_player[7]+ (other_player[5])/(other_player[9]) < 298) ) {selected_destination_red = Blue_Home;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 355) and (other_player[6] + (other_player[4])/(other_player[8]) < 438) and (other_player[7]+ (other_player[5])/(other_player[9]) > 507) and (other_player[7]+ (other_player[5])/(other_player[9]) < 619) ) {selected_destination_red = Kara;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 815) and (other_player[6] + (other_player[4])/(other_player[8]) < 936) and (other_player[7]+ (other_player[5])/(other_player[9]) > 471) and (other_player[7]+ (other_player[5])/(other_player[9]) < 567) ) {selected_destination_red = Masala;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1041) and (other_player[6] + (other_player[4])/(other_player[8]) < 1187) and (other_player[7]+ (other_player[5])/(other_player[9]) > 453) and (other_player[7]+ (other_player[5])/(other_player[9]) < 572) ) {selected_destination_red = Hospital;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1487) and (other_player[6] + (other_player[4])/(other_player[8]) < 1855) and (other_player[7]+ (other_player[5])/(other_player[9]) > 231) and (other_player[7]+ (other_player[5])/(other_player[9]) < 385) ) {selected_destination_red = Main_building;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 175) and (other_player[6] + (other_player[4])/(other_player[8]) < 267) and (other_player[7]+ (other_player[5])/(other_player[9]) > 756) and (other_player[7]+ (other_player[5])/(other_player[9]) < 860) ) {selected_destination_red = Apartments_boys;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 763) and (other_player[6] + (other_player[4])/(other_player[8]) < 877) and (other_player[7]+ (other_player[5])/(other_player[9]) > 807) and (other_player[7]+ (other_player[5])/(other_player[9]) < 914) ) {selected_destination_red = OAT;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1197) and (other_player[6] + (other_player[4])/(other_player[8]) < 1471) and (other_player[7]+ (other_player[5])/(other_player[9]) > 665) and (other_player[7]+ (other_player[5])/(other_player[9]) < 836) ) {selected_destination_red = Playground;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1409) and (other_player[6] + (other_player[4])/(other_player[8]) < 1650) and (other_player[7]+ (other_player[5])/(other_player[9]) > 927) and (other_player[7]+ (other_player[5])/(other_player[9]) < 1046) ) {selected_destination_red = Research;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1627) and (other_player[6] + (other_player[4])/(other_player[8]) < 1803) and (other_player[7]+ (other_player[5])/(other_player[9]) > 448) and (other_player[7]+ (other_player[5])/(other_player[9]) < 564) ) {selected_destination_red = Library;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2571) and (other_player[6] + (other_player[4])/(other_player[8]) < 2693) and (other_player[7]+ (other_player[5])/(other_player[9]) > 712) and (other_player[7]+ (other_player[5])/(other_player[9]) < 848) ) {selected_destination_red = Apartments_girls;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2008) and (other_player[6] + (other_player[4])/(other_player[8]) < 2230) and (other_player[7]+ (other_player[5])/(other_player[9]) > 611) and (other_player[7]+ (other_player[5])/(other_player[9]) < 769) ) {selected_destination_red = LHC;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2229) and (other_player[6] + (other_player[4])/(other_player[8]) < 2385) and (other_player[7]+ (other_player[5])/(other_player[9]) > 176) and (other_player[7]+ (other_player[5])/(other_player[9]) < 278) ) {selected_destination_red = Red_Home;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2613) and (other_player[6] + (other_player[4])/(other_player[8]) < 2708) and (other_player[7]+ (other_player[5])/(other_player[9]) > 444) and (other_player[7]+ (other_player[5])/(other_player[9]) < 536) ) {selected_destination_red = Market;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2606) and (other_player[6] + (other_player[4])/(other_player[8]) < 2727) and (other_player[7]+ (other_player[5])/(other_player[9]) > 249) and (other_player[7]+ (other_player[5])/(other_player[9]) < 349) ) {selected_destination_red = Amaltas;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2208) and (other_player[6] + (other_player[4])/(other_player[8]) < 2366) and (other_player[7]+ (other_player[5])/(other_player[9]) > 428) and (other_player[7]+ (other_player[5])/(other_player[9]) < 542) ) {selected_destination_red = School;}

                                        else {selected_destination_red = NULL;}

                                        if ((!(selected_origin_red==selected_destination_red)) and selected_destination_red!=NULL){
                                            int outgoing = selected_origin_red->send_half();
                                            if (outgoing!=0){
                                                create_packet(outgoing, selected_origin_red, selected_destination_red);
                                            }
                                        }

                                        selected_origin_red = NULL;
                                        selected_destination_red = NULL;

                                    }else{
                                        // ERROR: select an origin first!
                                    }
                                }
                            
                        }
                    }
















                }else{      // my_loyalty = "Red"

                    SDL_Event e;
                    while(SDL_PollEvent( &e ) != 0 ){
                        if( e.type == SDL_QUIT ){
                            isquit = 1;
                            quit = true;
                        }else if( e.type == SDL_KEYDOWN ){
                            //Select surfaces based on key press
                            switch( e.key.keysym.sym ){

                                case SDLK_ESCAPE:
                                isquit = 1;
                                quit = true;
                                break;
                            }
                        }else if ((e.type == SDL_MOUSEBUTTONDOWN) and !((LHC->power_stay_time > 0) and (LHC->loyalty == "Blue"))){

                            clicked = 1;
                            click_x = e.button.x;// absolute pixels from left side, do not get scaled automatically
                            click_y = e.button.y;

                            switch (e.button.button){
                                case SDL_BUTTON_LEFT:

                                    isleft = 1;
                                    isright = 0;
                                    // the six power buttons

                                    // relative to campus click position print
                                    //std::cout<<"x = "<<click_x + Current_view_x<<"          y = "<<click_y + Current_view_y<<std::endl;

                                    if ((click_x > ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*7.25/30))*SCALING_FACTOR_X) and (click_x < ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*5.25/30))*SCALING_FACTOR_X) and (click_y < (SCREEN_HEIGHT*29/30)*SCALING_FACTOR_Y) and (click_y > (SCREEN_HEIGHT*27/30)*SCALING_FACTOR_Y)) {
                                        // selected powerup 1 Fire Circle
                                        if (Apartments_boys->power_available and Apartments_boys->loyalty == "Red"){
                                            selected_origin_red = NULL;
                                            if (power_is_selected_red){
                                                if (selected_power_red == "Fire Circle"){
                                                    power_is_selected_red = false;
                                                    selected_power_red = "None";
                                                }else{
                                                    selected_power_red = "Fire Circle";
                                                }
                                            }else{
                                                power_is_selected_red = true;
                                                selected_power_red = "Fire Circle";
                                            }
                                        }

                                    }else if ((click_x > ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*4.75/30))*SCALING_FACTOR_X) and (click_x < ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*2.75/30))*SCALING_FACTOR_X) and (click_y < (SCREEN_HEIGHT*29/30)*SCALING_FACTOR_Y) and (click_y > (SCREEN_HEIGHT*27/30)*SCALING_FACTOR_Y)) {
                                        //selected powerup 2 Shield
                                        if (Hospital->power_available and Hospital->loyalty == "Red"){
                                            selected_origin_red = NULL;
                                            if (power_is_selected_red){
                                                if (selected_power_red == "Shield"){
                                                    power_is_selected_red = false;
                                                    selected_power_red = "None";
                                                }else{
                                                    selected_power_red = "Shield";
                                                }
                                            }else{
                                                power_is_selected_red = true;
                                                selected_power_red = "Shield";
                                            }
                                        }

                                    }else if ((click_x > ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*2.25/30))*SCALING_FACTOR_X) and (click_x < ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*0.25/30))*SCALING_FACTOR_X) and (click_y < (SCREEN_HEIGHT*29/30)*SCALING_FACTOR_Y) and (click_y > (SCREEN_HEIGHT*27/30)*SCALING_FACTOR_Y)) {
                                        //selected powerup 3 EMP
                                        if (Research->power_available and Research->loyalty == "Red"){
                                            selected_origin_red = NULL;
                                            if (power_is_selected_red){
                                                if (selected_power_red == "EMP"){
                                                    power_is_selected_red = false;
                                                    selected_power_red = "None";
                                                }else{
                                                    selected_power_red = "EMP";
                                                }
                                            }else{
                                                power_is_selected_red = true;
                                                selected_power_red = "EMP";
                                            }
                                        }

                                    }else if ((click_x > ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*0.25/30))*SCALING_FACTOR_X) and (click_x < ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*2.25/30))*SCALING_FACTOR_X) and (click_y < (SCREEN_HEIGHT*29/30)*SCALING_FACTOR_Y) and (click_y > (SCREEN_HEIGHT*27/30)*SCALING_FACTOR_Y)) {
                                        //selected powerup 4 Road Block
                                        if (OAT->power_available and OAT->loyalty == "Red"){
                                            selected_origin_red = NULL;
                                            if (power_is_selected_red){
                                                if (selected_power_red == "Road Block"){
                                                    power_is_selected_red = false;
                                                    selected_power_red = "None";
                                                }else{
                                                    selected_power_red = "Road Block";
                                                }
                                            }else{
                                                power_is_selected_red = true;
                                                selected_power_red = "Road Block";
                                            }
                                        }

                                    }else if ((click_x > ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*2.75/30))*SCALING_FACTOR_X) and (click_x < ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*4.75/30))*SCALING_FACTOR_X) and (click_y < (SCREEN_HEIGHT*29/30)*SCALING_FACTOR_Y) and (click_y > (SCREEN_HEIGHT*27/30)*SCALING_FACTOR_Y)) {
                                        //selected powerup 5 Freeze
                                        if (LHC->power_available and LHC->loyalty == "Red"){
                                            selected_origin_red = NULL;
                                            if (power_is_selected_red){
                                                if (selected_power_red == "Freeze"){
                                                    power_is_selected_red = false;
                                                    selected_power_red = "None";
                                                }else{
                                                    selected_power_red = "Freeze";
                                                }
                                            }else{
                                                power_is_selected_red = true;
                                                selected_power_red = "Freeze";
                                            }
                                        }

                                    }else if ((click_x > ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*5.25/30))*SCALING_FACTOR_X) and (click_x < ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*7.25/30))*SCALING_FACTOR_X) and (click_y < (SCREEN_HEIGHT*29/30)*SCALING_FACTOR_Y) and (click_y > (SCREEN_HEIGHT*27/30)*SCALING_FACTOR_Y)) {
                                        //selected powerup 6 Acid Circle
                                        if (Apartments_girls->power_available and Apartments_girls->loyalty == "Red"){
                                            selected_origin_red = NULL;
                                            if (power_is_selected_red){
                                                if (selected_power_red == "Acid Circle"){
                                                    power_is_selected_red = false;
                                                    selected_power_red = "None";
                                                }else{
                                                    selected_power_red = "Acid Circle";
                                                }
                                            }else{
                                                power_is_selected_red = true;
                                                selected_power_red = "Acid Circle";
                                            }
                                        }
                                    }


                                    // applying the selected power
                                    else if (power_is_selected_red){
                                        power_is_selected_red = false;


                                        if (selected_power_red=="Fire Circle"){// works only on moving soldiers
                                            Apartments_boys->power_available = false;
                                            Apartments_boys->power_circle_centre_x = Current_view_x + (click_x)/(SCALING_FACTOR_X);
                                            Apartments_boys->power_circle_centre_y = Current_view_y + (click_y)/(SCALING_FACTOR_Y);
                                            Apartments_boys->power_stay_time = 2;
                                            Apartments_boys->radius = 180;
                                            Apartments_boys->power_restore_time = 15;
                                            Apartments_boys->power_strength = 10;

                                            Mix_PlayChannel( -1, gFire_sound, 0 );

                                        }

                                        else if(selected_power_red=="Shield"){// works only on buildings


                                            bool correct_place_click = false;

                                            if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 366) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 454) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 169) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 286) and (Jwala->loyalty == Hospital->loyalty) ) {Hospital->power_circle_centre_x = Jwala->x; Hospital->power_circle_centre_y = Jwala->y ; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 735) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 881) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 201) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 298) and (Blue_Home->loyalty == Hospital->loyalty) ) {Hospital->power_circle_centre_x = Blue_Home->x; Hospital->power_circle_centre_y = Blue_Home->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 355) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 438) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 507) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 619) and (Kara->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Kara->x; Hospital->power_circle_centre_y = Kara->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 815) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 936) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 567) and (Masala->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Masala->x; Hospital->power_circle_centre_y = Masala->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1041) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1187) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 453) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 572) and (Hospital->loyalty == Hospital->loyalty) ) {Hospital->power_circle_centre_x = Hospital->x; Hospital->power_circle_centre_y = Hospital->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1487) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1855) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 231) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 385) and (Main_building->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Main_building->x; Hospital->power_circle_centre_y = Main_building->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 175) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 267) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 756) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 860) and (Apartments_boys->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Apartments_boys->x; Hospital->power_circle_centre_y = Apartments_boys->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 763) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 877) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 807) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 914) and (OAT->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = OAT->x; Hospital->power_circle_centre_y = OAT->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1197) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 665) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 836) and (Playground->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Playground->x; Hospital->power_circle_centre_y = Playground->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1409) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1650) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 927) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 1046) and (Research->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Research->x; Hospital->power_circle_centre_y = Research->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1627) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1803) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 448) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 564) and (Library->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Library->x; Hospital->power_circle_centre_y = Library->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2571) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2693) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 712) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 848) and (Apartments_girls->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Apartments_girls->x; Hospital->power_circle_centre_y = Apartments_girls->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2008) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2230) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 611) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 769) and (LHC->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = LHC->x; Hospital->power_circle_centre_y = LHC->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2229) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2385) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 176) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 278) and (Red_Home->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Red_Home->x; Hospital->power_circle_centre_y = Red_Home->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2613) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2708) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 444) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 536) and (Market->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Market->x; Hospital->power_circle_centre_y = Market->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2606) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2727) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 249) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 349) and (Amaltas->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Amaltas->x; Hospital->power_circle_centre_y = Amaltas->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2208) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2366) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 428) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 542) and (School->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = School->x; Hospital->power_circle_centre_y = School->y; correct_place_click = true;}


                                            if (correct_place_click){
                                                Hospital->power_available = false;
                                                Hospital->power_stay_time = 2;
                                                Hospital->radius = 200;
                                                Hospital->power_restore_time = 15;

                                                Mix_PlayChannel( -1, gShield_sound, 0 );
                                            }
                                        }




                                        else if(selected_power_red=="EMP"){// works only on buildings

                                            bool correct_place_click = false;

                                            if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 366) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 454) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 169) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 286) and (Jwala->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Jwala->x; Research->power_circle_centre_y = Jwala->y ; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 735) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 881) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 201) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 298) and (Blue_Home->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Blue_Home->x; Research->power_circle_centre_y = Blue_Home->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 355) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 438) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 507) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 619) and (Kara->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Kara->x; Research->power_circle_centre_y = Kara->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 815) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 936) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 567) and (Masala->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Masala->x; Research->power_circle_centre_y = Masala->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1041) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1187) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 453) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 572) and (Hospital->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Hospital->x; Research->power_circle_centre_y = Hospital->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1487) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1855) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 231) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 385) and (Main_building->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Main_building->x; Research->power_circle_centre_y = Main_building->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 175) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 267) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 756) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 860) and (Apartments_boys->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Apartments_boys->x; Research->power_circle_centre_y = Apartments_boys->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 763) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 877) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 807) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 914) and (OAT->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = OAT->x; Research->power_circle_centre_y = OAT->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1197) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 665) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 836) and (Playground->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Playground->x; Research->power_circle_centre_y = Playground->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1409) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1650) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 927) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 1046) and (Research->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Research->x; Research->power_circle_centre_y = Research->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1627) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1803) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 448) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 564) and (Library->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Library->x; Research->power_circle_centre_y = Library->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2571) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2693) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 712) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 848) and (Apartments_girls->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Apartments_girls->x; Research->power_circle_centre_y = Apartments_girls->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2008) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2230) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 611) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 769) and (LHC->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = LHC->x; Research->power_circle_centre_y = LHC->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2229) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2385) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 176) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 278) and (Red_Home->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Red_Home->x; Research->power_circle_centre_y = Red_Home->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2613) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2708) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 444) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 536) and (Market->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Market->x; Research->power_circle_centre_y = Market->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2606) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2727) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 249) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 349) and (Amaltas->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Amaltas->x; Research->power_circle_centre_y = Amaltas->y; correct_place_click = true;}
                                            else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2208) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2366) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 428) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 542) and (School->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = School->x; Research->power_circle_centre_y = School->y; correct_place_click = true;}
                                            
                                            if (correct_place_click){
                                                Research->power_stay_time = 1;
                                                Research->radius = 150;
                                                Research->power_restore_time = 15;
                                                Research->power_strength = 18;

                                                Mix_PlayChannel( -1, gEMP_sound, 0 );

                                            }else{
                                                // display error, click on an enemy building
                                            }



                                        }

                                        else if (selected_power_red=="Road Block"){// works only on roads
                                            OAT->power_available = false;
                                            OAT->power_circle_centre_x = Current_view_x + (click_x)/(SCALING_FACTOR_X);
                                            OAT->power_circle_centre_y = Current_view_y + (click_y)/(SCALING_FACTOR_Y);
                                            OAT->power_stay_time = 4;
                                            OAT->radius = 40;
                                            OAT->power_restore_time = 15;

                                            Mix_PlayChannel( -1, gWall_sound, 0 );
                                        }
                                        else if (selected_power_red=="Freeze"){// works on every action of the opponent 
                                            LHC->power_available = false;
                                            LHC->power_stay_time = 4;
                                            LHC->power_restore_time = 15;

                                            Mix_PlayChannel( -1, gFreeze_sound, 0 );
                                        }

                                        else if (selected_power_red=="Acid Circle"){// works only on moving targets
                                            Apartments_girls->power_available = false;
                                            Apartments_girls->power_circle_centre_x = Current_view_x + (click_x)/(SCALING_FACTOR_X);
                                            Apartments_girls->power_circle_centre_y = Current_view_y + (click_y)/(SCALING_FACTOR_Y);
                                            Apartments_girls->power_stay_time = 2;
                                            Apartments_girls->radius = 180;
                                            Apartments_girls->power_restore_time = 15;
                                            Apartments_girls->power_strength = 10;

                                            Mix_PlayChannel( -1, gAcid_sound, 0 );
                                        }

                                        selected_power_red = "None";
                                    }

                                    // using equation of ellipse: x^2/a^2 + y^2/b^2 < 1 for an inside point

                                    //selecting origin
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 366) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 454) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 169) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 286) and (Jwala->loyalty == "Red") ) {selected_origin_red = Jwala;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 735) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 881) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 201) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 298) and (Blue_Home->loyalty == "Red") ) {selected_origin_red = Blue_Home;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 355) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 438) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 507) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 619) and (Kara->loyalty == "Red") ) {selected_origin_red = Kara;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 815) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 936) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 567) and (Masala->loyalty == "Red") ) {selected_origin_red = Masala;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1041) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1187) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 453) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 572) and (Hospital->loyalty == "Red") ) {selected_origin_red = Hospital;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1487) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1855) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 231) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 385) and (Main_building->loyalty == "Red") ) {selected_origin_red = Main_building;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 175) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 267) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 756) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 860) and (Apartments_boys->loyalty == "Red") ) {selected_origin_red = Apartments_boys;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 763) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 877) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 807) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 914) and (OAT->loyalty == "Red") ) {selected_origin_red = OAT;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1197) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 665) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 836) and (Playground->loyalty == "Red") ) {selected_origin_red = Playground;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1409) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1650) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 927) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 1046) and (Research->loyalty == "Red") ) {selected_origin_red = Research;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1627) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1803) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 448) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 564) and (Library->loyalty == "Red") ) {selected_origin_red = Library;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2571) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2693) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 712) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 848) and (Apartments_girls->loyalty == "Red") ) {selected_origin_red = Apartments_girls;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2008) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2230) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 611) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 769) and (LHC->loyalty == "Red") ) {selected_origin_red = LHC;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2229) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2385) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 176) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 278) and (Red_Home->loyalty == "Red") ) {selected_origin_red = Red_Home;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2613) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2708) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 444) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 536) and (Market->loyalty == "Red") ) {selected_origin_red = Market;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2606) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2727) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 249) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 349) and (Amaltas->loyalty == "Red") ) {selected_origin_red = Amaltas;}
                                    else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2208) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2366) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 428) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 542) and (School->loyalty == "Red") ) {selected_origin_red = School;}

                                break;





                                case SDL_BUTTON_RIGHT:
                                    isright = 1;
                                    isleft = 0;
                                    if ((selected_origin_red!=NULL) and (!power_is_selected_red)){

                                        // Rectangle selection instead of ellipse here. Ellipse to be used for power circles. 

                                        // selecting destination
                                        if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 366) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 454) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 169) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 286) ) {selected_destination_red = Jwala;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 735) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 881) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 201) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 298) ) {selected_destination_red = Blue_Home;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 355) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 438) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 507) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 619) ) {selected_destination_red = Kara;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 815) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 936) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 567) ) {selected_destination_red = Masala;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1041) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1187) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 453) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 572) ) {selected_destination_red = Hospital;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1487) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1855) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 231) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 385) ) {selected_destination_red = Main_building;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 175) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 267) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 756) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 860) ) {selected_destination_red = Apartments_boys;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 763) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 877) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 807) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 914) ) {selected_destination_red = OAT;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1197) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1471) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 665) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 836) ) {selected_destination_red = Playground;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1409) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1650) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 927) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 1046) ) {selected_destination_red = Research;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 1627) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 1803) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 448) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 564) ) {selected_destination_red = Library;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2571) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2693) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 712) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 848) ) {selected_destination_red = Apartments_girls;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2008) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2230) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 611) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 769) ) {selected_destination_red = LHC;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2229) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2385) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 176) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 278) ) {selected_destination_red = Red_Home;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2613) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2708) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 444) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 536) ) {selected_destination_red = Market;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2606) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2727) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 249) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 349) ) {selected_destination_red = Amaltas;}
                                        else if ((Current_view_x + (click_x)/(SCALING_FACTOR_X) > 2208) and (Current_view_x + (click_x)/(SCALING_FACTOR_X) < 2366) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) > 428) and (Current_view_y + (click_y)/(SCALING_FACTOR_Y) < 542) ) {selected_destination_red = School;}

                                        else {selected_destination_red = NULL;}

                                        if ((!(selected_origin_red==selected_destination_red)) and selected_destination_red!=NULL){
                                            int outgoing = selected_origin_red->send_half();
                                            if (outgoing!=0){
                                                create_packet(outgoing, selected_origin_red, selected_destination_red);
                                            }
                                        }

                                        selected_origin_red = NULL;
                                        selected_destination_red = NULL;

                                    }else{
                                        // ERROR: select an origin first!
                                    }
                                break; 
                            }
                        }
                    }





                    // settings for other player (Blue here)

                    // text[] = {state, clicked, isleft, isright, click_x, click_y, Current_view_x, Current_view_y, isquit}

                    if (!(quit)){
                        if (other_player[10] == 1){
                            quit = true;
                            isquit = 1;
                        }
                        else if ((other_player[1]==1) and !((LHC->power_stay_time > 0) and (LHC->loyalty == "Red"))){ // other_player has clicked on the screen and is not freezed
                                if (other_player[2]==1){ // other player did a left click

                                    // the six power buttons

                                    if ((other_player[4] > ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*7.25/30))*other_player[8]) and (other_player[4] < ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*5.25/30))*other_player[8]) and (other_player[5] < (SCREEN_HEIGHT*29/30)*other_player[9]) and (other_player[5] > (SCREEN_HEIGHT*27/30)*other_player[9])) {
                                        // selected powerup 1 Fire Circle
                                        if (Apartments_boys->power_available and Apartments_boys->loyalty == "Blue"){
                                            selected_origin_blue = NULL;
                                            if (power_is_selected_blue){
                                                if (selected_power_blue == "Fire Circle"){
                                                    power_is_selected_blue = false;
                                                    selected_power_blue = "None";
                                                }else{
                                                    selected_power_blue = "Fire Circle";
                                                }
                                            }else{
                                                power_is_selected_blue = true;
                                                selected_power_blue = "Fire Circle";
                                            }
                                        }

                                    }else if ((other_player[4] > ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*4.75/30))*other_player[8]) and (other_player[4] < ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*2.75/30))*other_player[8]) and (other_player[5] < (SCREEN_HEIGHT*29/30)*other_player[9]) and (other_player[5] > (SCREEN_HEIGHT*27/30)*other_player[9])) {
                                        //selected powerup 2 Shield
                                        if (Hospital->power_available and Hospital->loyalty == "Blue"){
                                            selected_origin_blue = NULL;
                                            if (power_is_selected_blue){
                                                if (selected_power_blue == "Shield"){
                                                    power_is_selected_blue = false;
                                                    selected_power_blue = "None";
                                                }else{
                                                    selected_power_blue = "Shield";
                                                }
                                            }else{
                                                power_is_selected_blue = true;
                                                selected_power_blue = "Shield";
                                            }
                                        }

                                    }else if ((other_player[4] > ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*2.25/30))*other_player[8]) and (other_player[4] < ((SCREEN_WIDTH/2)-(SCREEN_WIDTH*0.25/30))*other_player[8]) and (other_player[5] < (SCREEN_HEIGHT*29/30)*other_player[9]) and (other_player[5] > (SCREEN_HEIGHT*27/30)*other_player[9])) {
                                        //selected powerup 3 EMP
                                        if (Research->power_available and Research->loyalty == "Blue"){
                                            selected_origin_blue = NULL;
                                            if (power_is_selected_blue){
                                                if (selected_power_blue == "EMP"){
                                                    power_is_selected_blue = false;
                                                    selected_power_blue = "None";
                                                }else{
                                                    selected_power_blue = "EMP";
                                                }
                                            }else{
                                                power_is_selected_blue = true;
                                                selected_power_blue = "EMP";
                                            }
                                        }

                                    }else if ((other_player[4] > ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*0.25/30))*other_player[8]) and (other_player[4] < ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*2.25/30))*other_player[8]) and (other_player[5] < (SCREEN_HEIGHT*29/30)*other_player[9]) and (other_player[5] > (SCREEN_HEIGHT*27/30)*other_player[9])) {
                                        //selected powerup 4 Road Block
                                        if (OAT->power_available and OAT->loyalty == "Blue"){
                                            selected_origin_blue = NULL;
                                            if (power_is_selected_blue){
                                                if (selected_power_blue == "Road Block"){
                                                    power_is_selected_blue = false;
                                                    selected_power_blue = "None";
                                                }else{
                                                    selected_power_blue = "Road Block";
                                                }
                                            }else{
                                                power_is_selected_blue = true;
                                                selected_power_blue = "Road Block";
                                            }
                                        }

                                    }else if ((other_player[4] > ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*2.75/30))*other_player[8]) and (other_player[4] < ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*4.75/30))*other_player[8]) and (other_player[5] < (SCREEN_HEIGHT*29/30)*other_player[9]) and (other_player[5] > (SCREEN_HEIGHT*27/30)*other_player[9])) {
                                        //selected powerup 5 Freeze
                                        if (LHC->power_available and LHC->loyalty == "Blue"){
                                            selected_origin_blue = NULL;
                                            if (power_is_selected_blue){
                                                if (selected_power_blue == "Freeze"){
                                                    power_is_selected_blue = false;
                                                    selected_power_blue = "None";
                                                }else{
                                                    selected_power_blue = "Freeze";
                                                }
                                            }else{
                                                power_is_selected_blue = true;
                                                selected_power_blue = "Freeze";
                                            }
                                        }

                                    }else if ((other_player[4] > ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*5.25/30))*other_player[8]) and (other_player[4] < ((SCREEN_WIDTH/2)+(SCREEN_WIDTH*7.25/30))*other_player[8]) and (other_player[5] < (SCREEN_HEIGHT*29/30)*other_player[9]) and (other_player[5] > (SCREEN_HEIGHT*27/30)*other_player[9])) {
                                        //selected powerup 6 Acid Circle
                                        if (Apartments_girls->power_available and Apartments_girls->loyalty == "Blue"){
                                            selected_origin_blue = NULL;
                                            if (power_is_selected_blue){
                                                if (selected_power_blue == "Acid Circle"){
                                                    power_is_selected_blue = false;
                                                    selected_power_blue = "None";
                                                }else{
                                                    selected_power_blue = "Acid Circle";
                                                }
                                            }else{
                                                power_is_selected_blue = true;
                                                selected_power_blue = "Acid Circle";
                                            }
                                        }
                                    }


                                    // applying the selected power
                                    else if (power_is_selected_blue){
                                        power_is_selected_blue = false;


                                        if (selected_power_blue=="Fire Circle"){// works only on moving soldiers
                                            Apartments_boys->power_available = false;
                                            Apartments_boys->power_circle_centre_x = other_player[6] + (other_player[4])/(other_player[8]);
                                            Apartments_boys->power_circle_centre_y = other_player[7] + (other_player[5])/(other_player[9]);
                                            Apartments_boys->power_stay_time = 2;
                                            Apartments_boys->radius = 180;
                                            Apartments_boys->power_restore_time = 15;
                                            Apartments_boys->power_strength = 10;

                                            Mix_PlayChannel( -1, gFire_sound, 0 );
                                        }

                                        else if(selected_power_blue=="Shield"){// works only on buildings


                                            bool correct_place_click = false;

                                            if ((other_player[6] + (other_player[4])/(other_player[8]) > 366) and (other_player[6] + (other_player[4])/(other_player[8]) < 454) and (other_player[7] + (other_player[5])/(other_player[9]) > 169) and (other_player[7] + (other_player[5])/(other_player[9]) < 286) and (Jwala->loyalty == Hospital->loyalty) ) {Hospital->power_circle_centre_x = Jwala->x; Hospital->power_circle_centre_y = Jwala->y ; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 735) and (other_player[6] + (other_player[4])/(other_player[8]) < 881) and (other_player[7] + (other_player[5])/(other_player[9]) > 201) and (other_player[7] + (other_player[5])/(other_player[9]) < 298) and (Blue_Home->loyalty == Hospital->loyalty) ) {Hospital->power_circle_centre_x = Blue_Home->x; Hospital->power_circle_centre_y = Blue_Home->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 355) and (other_player[6] + (other_player[4])/(other_player[8]) < 438) and (other_player[7] + (other_player[5])/(other_player[9]) > 507) and (other_player[7] + (other_player[5])/(other_player[9]) < 619) and (Kara->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Kara->x; Hospital->power_circle_centre_y = Kara->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 815) and (other_player[6] + (other_player[4])/(other_player[8]) < 936) and (other_player[7] + (other_player[5])/(other_player[9]) > 471) and (other_player[7] + (other_player[5])/(other_player[9]) < 567) and (Masala->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Masala->x; Hospital->power_circle_centre_y = Masala->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1041) and (other_player[6] + (other_player[4])/(other_player[8]) < 1187) and (other_player[7] + (other_player[5])/(other_player[9]) > 453) and (other_player[7] + (other_player[5])/(other_player[9]) < 572) and (Hospital->loyalty == Hospital->loyalty) ) {Hospital->power_circle_centre_x = Hospital->x; Hospital->power_circle_centre_y = Hospital->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1487) and (other_player[6] + (other_player[4])/(other_player[8]) < 1855) and (other_player[7] + (other_player[5])/(other_player[9]) > 231) and (other_player[7] + (other_player[5])/(other_player[9]) < 385) and (Main_building->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Main_building->x; Hospital->power_circle_centre_y = Main_building->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 175) and (other_player[6] + (other_player[4])/(other_player[8]) < 267) and (other_player[7] + (other_player[5])/(other_player[9]) > 756) and (other_player[7] + (other_player[5])/(other_player[9]) < 860) and (Apartments_boys->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Apartments_boys->x; Hospital->power_circle_centre_y = Apartments_boys->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 763) and (other_player[6] + (other_player[4])/(other_player[8]) < 877) and (other_player[7] + (other_player[5])/(other_player[9]) > 807) and (other_player[7] + (other_player[5])/(other_player[9]) < 914) and (OAT->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = OAT->x; Hospital->power_circle_centre_y = OAT->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1197) and (other_player[6] + (other_player[4])/(other_player[8]) < 1471) and (other_player[7] + (other_player[5])/(other_player[9]) > 665) and (other_player[7] + (other_player[5])/(other_player[9]) < 836) and (Playground->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Playground->x; Hospital->power_circle_centre_y = Playground->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1409) and (other_player[6] + (other_player[4])/(other_player[8]) < 1650) and (other_player[7] + (other_player[5])/(other_player[9]) > 927) and (other_player[7] + (other_player[5])/(other_player[9]) < 1046) and (Research->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Research->x; Hospital->power_circle_centre_y = Research->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1627) and (other_player[6] + (other_player[4])/(other_player[8]) < 1803) and (other_player[7] + (other_player[5])/(other_player[9]) > 448) and (other_player[7] + (other_player[5])/(other_player[9]) < 564) and (Library->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Library->x; Hospital->power_circle_centre_y = Library->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2571) and (other_player[6] + (other_player[4])/(other_player[8]) < 2693) and (other_player[7] + (other_player[5])/(other_player[9]) > 712) and (other_player[7] + (other_player[5])/(other_player[9]) < 848) and (Apartments_girls->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Apartments_girls->x; Hospital->power_circle_centre_y = Apartments_girls->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2008) and (other_player[6] + (other_player[4])/(other_player[8]) < 2230) and (other_player[7] + (other_player[5])/(other_player[9]) > 611) and (other_player[7] + (other_player[5])/(other_player[9]) < 769) and (LHC->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = LHC->x; Hospital->power_circle_centre_y = LHC->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2229) and (other_player[6] + (other_player[4])/(other_player[8]) < 2385) and (other_player[7] + (other_player[5])/(other_player[9]) > 176) and (other_player[7] + (other_player[5])/(other_player[9]) < 278) and (Red_Home->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Red_Home->x; Hospital->power_circle_centre_y = Red_Home->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2613) and (other_player[6] + (other_player[4])/(other_player[8]) < 2708) and (other_player[7] + (other_player[5])/(other_player[9]) > 444) and (other_player[7] + (other_player[5])/(other_player[9]) < 536) and (Market->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Market->x; Hospital->power_circle_centre_y = Market->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2606) and (other_player[6] + (other_player[4])/(other_player[8]) < 2727) and (other_player[7] + (other_player[5])/(other_player[9]) > 249) and (other_player[7] + (other_player[5])/(other_player[9]) < 349) and (Amaltas->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = Amaltas->x; Hospital->power_circle_centre_y = Amaltas->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2208) and (other_player[6] + (other_player[4])/(other_player[8]) < 2366) and (other_player[7] + (other_player[5])/(other_player[9]) > 428) and (other_player[7] + (other_player[5])/(other_player[9]) < 542) and (School->loyalty ==  Hospital->loyalty) ) {Hospital->power_circle_centre_x = School->x; Hospital->power_circle_centre_y = School->y; correct_place_click = true;}


                                            if (correct_place_click){
                                                Hospital->power_available = false;
                                                Hospital->power_stay_time = 2;
                                                Hospital->radius = 200;
                                                Hospital->power_restore_time = 15;

                                                Mix_PlayChannel( -1, gShield_sound, 0 );
                                            }
                                        }




                                        else if(selected_power_blue=="EMP"){// works only on buildings

                                            bool correct_place_click = false;

                                            if ((other_player[6] + (other_player[4])/(other_player[8]) > 366) and (other_player[6] + (other_player[4])/(other_player[8]) < 454) and (other_player[7] + (other_player[5])/(other_player[9]) > 169) and (other_player[7] + (other_player[5])/(other_player[9]) < 286) and (Jwala->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Jwala->x; Research->power_circle_centre_y = Jwala->y ; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 735) and (other_player[6] + (other_player[4])/(other_player[8]) < 881) and (other_player[7] + (other_player[5])/(other_player[9]) > 201) and (other_player[7] + (other_player[5])/(other_player[9]) < 298) and (Blue_Home->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Blue_Home->x; Research->power_circle_centre_y = Blue_Home->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 355) and (other_player[6] + (other_player[4])/(other_player[8]) < 438) and (other_player[7] + (other_player[5])/(other_player[9]) > 507) and (other_player[7] + (other_player[5])/(other_player[9]) < 619) and (Kara->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Kara->x; Research->power_circle_centre_y = Kara->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 815) and (other_player[6] + (other_player[4])/(other_player[8]) < 936) and (other_player[7] + (other_player[5])/(other_player[9]) > 471) and (other_player[7] + (other_player[5])/(other_player[9]) < 567) and (Masala->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Masala->x; Research->power_circle_centre_y = Masala->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1041) and (other_player[6] + (other_player[4])/(other_player[8]) < 1187) and (other_player[7] + (other_player[5])/(other_player[9]) > 453) and (other_player[7] + (other_player[5])/(other_player[9]) < 572) and (Hospital->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Hospital->x; Research->power_circle_centre_y = Hospital->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1487) and (other_player[6] + (other_player[4])/(other_player[8]) < 1855) and (other_player[7] + (other_player[5])/(other_player[9]) > 231) and (other_player[7] + (other_player[5])/(other_player[9]) < 385) and (Main_building->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Main_building->x; Research->power_circle_centre_y = Main_building->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 175) and (other_player[6] + (other_player[4])/(other_player[8]) < 267) and (other_player[7] + (other_player[5])/(other_player[9]) > 756) and (other_player[7] + (other_player[5])/(other_player[9]) < 860) and (Apartments_boys->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Apartments_boys->x; Research->power_circle_centre_y = Apartments_boys->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 763) and (other_player[6] + (other_player[4])/(other_player[8]) < 877) and (other_player[7] + (other_player[5])/(other_player[9]) > 807) and (other_player[7] + (other_player[5])/(other_player[9]) < 914) and (OAT->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = OAT->x; Research->power_circle_centre_y = OAT->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1197) and (other_player[6] + (other_player[4])/(other_player[8]) < 1471) and (other_player[7] + (other_player[5])/(other_player[9]) > 665) and (other_player[7] + (other_player[5])/(other_player[9]) < 836) and (Playground->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Playground->x; Research->power_circle_centre_y = Playground->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1409) and (other_player[6] + (other_player[4])/(other_player[8]) < 1650) and (other_player[7] + (other_player[5])/(other_player[9]) > 927) and (other_player[7] + (other_player[5])/(other_player[9]) < 1046) and (Research->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Research->x; Research->power_circle_centre_y = Research->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1627) and (other_player[6] + (other_player[4])/(other_player[8]) < 1803) and (other_player[7] + (other_player[5])/(other_player[9]) > 448) and (other_player[7] + (other_player[5])/(other_player[9]) < 564) and (Library->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Library->x; Research->power_circle_centre_y = Library->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2571) and (other_player[6] + (other_player[4])/(other_player[8]) < 2693) and (other_player[7] + (other_player[5])/(other_player[9]) > 712) and (other_player[7] + (other_player[5])/(other_player[9]) < 848) and (Apartments_girls->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Apartments_girls->x; Research->power_circle_centre_y = Apartments_girls->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2008) and (other_player[6] + (other_player[4])/(other_player[8]) < 2230) and (other_player[7] + (other_player[5])/(other_player[9]) > 611) and (other_player[7] + (other_player[5])/(other_player[9]) < 769) and (LHC->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = LHC->x; Research->power_circle_centre_y = LHC->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2229) and (other_player[6] + (other_player[4])/(other_player[8]) < 2385) and (other_player[7] + (other_player[5])/(other_player[9]) > 176) and (other_player[7] + (other_player[5])/(other_player[9]) < 278) and (Red_Home->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Red_Home->x; Research->power_circle_centre_y = Red_Home->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2613) and (other_player[6] + (other_player[4])/(other_player[8]) < 2708) and (other_player[7] + (other_player[5])/(other_player[9]) > 444) and (other_player[7] + (other_player[5])/(other_player[9]) < 536) and (Market->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Market->x; Research->power_circle_centre_y = Market->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2606) and (other_player[6] + (other_player[4])/(other_player[8]) < 2727) and (other_player[7] + (other_player[5])/(other_player[9]) > 249) and (other_player[7] + (other_player[5])/(other_player[9]) < 349) and (Amaltas->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = Amaltas->x; Research->power_circle_centre_y = Amaltas->y; correct_place_click = true;}
                                            else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2208) and (other_player[6] + (other_player[4])/(other_player[8]) < 2366) and (other_player[7] + (other_player[5])/(other_player[9]) > 428) and (other_player[7] + (other_player[5])/(other_player[9]) < 542) and (School->loyalty != Research->loyalty) ) {Research->power_circle_centre_x = School->x; Research->power_circle_centre_y = School->y; correct_place_click = true;}
                                            
                                            if (correct_place_click){
                                                Research->power_stay_time = 1;
                                                Research->radius = 150;
                                                Research->power_restore_time = 15;
                                                Research->power_strength = 18;

                                                Mix_PlayChannel( -1, gEMP_sound, 0 );

                                            }else{
                                                // display error, click on an enemy building
                                            }



                                        }
                                        else if (selected_power_blue=="Road Block"){// works only on roads
                                            OAT->power_available = false;
                                            OAT->power_circle_centre_x = other_player[6] + (other_player[4])/(other_player[8]);
                                            OAT->power_circle_centre_y = other_player[7] + (other_player[5])/(other_player[9]);
                                            OAT->power_stay_time = 4;
                                            OAT->radius = 40;
                                            OAT->power_restore_time = 15;

                                            Mix_PlayChannel( -1, gWall_sound, 0 );
                                        }

                                        else if (selected_power_blue=="Freeze"){// works on every action of the opponent 
                                            LHC->power_available = false;
                                            LHC->power_stay_time = 4;
                                            LHC->power_restore_time = 15;

                                            Mix_PlayChannel( -1, gFreeze_sound, 0 );
                                        }

                                        else if (selected_power_blue=="Acid Circle"){// works only on moving targets
                                            Apartments_girls->power_available = false;
                                            Apartments_girls->power_circle_centre_x = other_player[6] + (other_player[4])/(other_player[8]);
                                            Apartments_girls->power_circle_centre_y = other_player[7] + (other_player[5])/(other_player[9]);
                                            Apartments_girls->power_stay_time = 2;
                                            Apartments_girls->radius = 180;
                                            Apartments_girls->power_restore_time = 15;
                                            Apartments_girls->power_strength = 10;

                                            Mix_PlayChannel( -1, gAcid_sound, 0 );
                                        }

                                        selected_power_blue = "None";
                                    }

                                    // using equation of ellipse: x^2/a^2 + y^2/b^2 < 1 for an inside point

                                    //selecting origin
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 366) and (other_player[6] + (other_player[4])/(other_player[8]) < 454) and (other_player[7] + (other_player[5])/(other_player[9]) > 169) and (other_player[7] + (other_player[5])/(other_player[9]) < 286) and (Jwala->loyalty == "Blue") ) {selected_origin_blue = Jwala;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 735) and (other_player[6] + (other_player[4])/(other_player[8]) < 881) and (other_player[7] + (other_player[5])/(other_player[9]) > 201) and (other_player[7] + (other_player[5])/(other_player[9]) < 298) and (Blue_Home->loyalty == "Blue") ) {selected_origin_blue = Blue_Home;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 355) and (other_player[6] + (other_player[4])/(other_player[8]) < 438) and (other_player[7] + (other_player[5])/(other_player[9]) > 507) and (other_player[7] + (other_player[5])/(other_player[9]) < 619) and (Kara->loyalty == "Blue") ) {selected_origin_blue = Kara;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 815) and (other_player[6] + (other_player[4])/(other_player[8]) < 936) and (other_player[7] + (other_player[5])/(other_player[9]) > 471) and (other_player[7] + (other_player[5])/(other_player[9]) < 567) and (Masala->loyalty == "Blue") ) {selected_origin_blue = Masala;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1041) and (other_player[6] + (other_player[4])/(other_player[8]) < 1187) and (other_player[7] + (other_player[5])/(other_player[9]) > 453) and (other_player[7] + (other_player[5])/(other_player[9]) < 572) and (Hospital->loyalty == "Blue") ) {selected_origin_blue = Hospital;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1487) and (other_player[6] + (other_player[4])/(other_player[8]) < 1855) and (other_player[7] + (other_player[5])/(other_player[9]) > 231) and (other_player[7] + (other_player[5])/(other_player[9]) < 385) and (Main_building->loyalty == "Blue") ) {selected_origin_blue = Main_building;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 175) and (other_player[6] + (other_player[4])/(other_player[8]) < 267) and (other_player[7] + (other_player[5])/(other_player[9]) > 756) and (other_player[7] + (other_player[5])/(other_player[9]) < 860) and (Apartments_boys->loyalty == "Blue") ) {selected_origin_blue = Apartments_boys;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 763) and (other_player[6] + (other_player[4])/(other_player[8]) < 877) and (other_player[7] + (other_player[5])/(other_player[9]) > 807) and (other_player[7] + (other_player[5])/(other_player[9]) < 914) and (OAT->loyalty == "Blue") ) {selected_origin_blue = OAT;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1197) and (other_player[6] + (other_player[4])/(other_player[8]) < 1471) and (other_player[7] + (other_player[5])/(other_player[9]) > 665) and (other_player[7] + (other_player[5])/(other_player[9]) < 836) and (Playground->loyalty == "Blue") ) {selected_origin_blue = Playground;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1409) and (other_player[6] + (other_player[4])/(other_player[8]) < 1650) and (other_player[7] + (other_player[5])/(other_player[9]) > 927) and (other_player[7] + (other_player[5])/(other_player[9]) < 1046) and (Research->loyalty == "Blue") ) {selected_origin_blue = Research;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1627) and (other_player[6] + (other_player[4])/(other_player[8]) < 1803) and (other_player[7] + (other_player[5])/(other_player[9]) > 448) and (other_player[7] + (other_player[5])/(other_player[9]) < 564) and (Library->loyalty == "Blue") ) {selected_origin_blue = Library;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2571) and (other_player[6] + (other_player[4])/(other_player[8]) < 2693) and (other_player[7] + (other_player[5])/(other_player[9]) > 712) and (other_player[7] + (other_player[5])/(other_player[9]) < 848) and (Apartments_girls->loyalty == "Blue") ) {selected_origin_blue = Apartments_girls;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2008) and (other_player[6] + (other_player[4])/(other_player[8]) < 2230) and (other_player[7] + (other_player[5])/(other_player[9]) > 611) and (other_player[7] + (other_player[5])/(other_player[9]) < 769) and (LHC->loyalty == "Blue") ) {selected_origin_blue = LHC;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2229) and (other_player[6] + (other_player[4])/(other_player[8]) < 2385) and (other_player[7] + (other_player[5])/(other_player[9]) > 176) and (other_player[7] + (other_player[5])/(other_player[9]) < 278) and (Red_Home->loyalty == "Blue") ) {selected_origin_blue = Red_Home;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2613) and (other_player[6] + (other_player[4])/(other_player[8]) < 2708) and (other_player[7] + (other_player[5])/(other_player[9]) > 444) and (other_player[7] + (other_player[5])/(other_player[9]) < 536) and (Market->loyalty == "Blue") ) {selected_origin_blue = Market;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2606) and (other_player[6] + (other_player[4])/(other_player[8]) < 2727) and (other_player[7] + (other_player[5])/(other_player[9]) > 249) and (other_player[7] + (other_player[5])/(other_player[9]) < 349) and (Amaltas->loyalty == "Blue") ) {selected_origin_blue = Amaltas;}
                                    else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2208) and (other_player[6] + (other_player[4])/(other_player[8]) < 2366) and (other_player[7] + (other_player[5])/(other_player[9]) > 428) and (other_player[7] + (other_player[5])/(other_player[9]) < 542) and (School->loyalty == "Blue") ) {selected_origin_blue = School;}








                                }else if (other_player[3]==1) { // other player did a right click
                                    if ((selected_origin_blue!=NULL) and (!power_is_selected_blue)){

                                        // Rectangle selection instead of ellipse here. Ellipse to be used for power circles. 

                                        // selecting destination
                                        if ((other_player[6] + (other_player[4])/(other_player[8]) > 366) and (other_player[6] + (other_player[4])/(other_player[8]) < 454) and (other_player[7]+ (other_player[5])/(other_player[9]) > 169) and (other_player[7]+ (other_player[5])/(other_player[9]) < 286) ) {selected_destination_blue = Jwala;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 735) and (other_player[6] + (other_player[4])/(other_player[8]) < 881) and (other_player[7]+ (other_player[5])/(other_player[9]) > 201) and (other_player[7]+ (other_player[5])/(other_player[9]) < 298) ) {selected_destination_blue = Blue_Home;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 355) and (other_player[6] + (other_player[4])/(other_player[8]) < 438) and (other_player[7]+ (other_player[5])/(other_player[9]) > 507) and (other_player[7]+ (other_player[5])/(other_player[9]) < 619) ) {selected_destination_blue = Kara;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 815) and (other_player[6] + (other_player[4])/(other_player[8]) < 936) and (other_player[7]+ (other_player[5])/(other_player[9]) > 471) and (other_player[7]+ (other_player[5])/(other_player[9]) < 567) ) {selected_destination_blue = Masala;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1041) and (other_player[6] + (other_player[4])/(other_player[8]) < 1187) and (other_player[7]+ (other_player[5])/(other_player[9]) > 453) and (other_player[7]+ (other_player[5])/(other_player[9]) < 572) ) {selected_destination_blue = Hospital;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1487) and (other_player[6] + (other_player[4])/(other_player[8]) < 1855) and (other_player[7]+ (other_player[5])/(other_player[9]) > 231) and (other_player[7]+ (other_player[5])/(other_player[9]) < 385) ) {selected_destination_blue = Main_building;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 175) and (other_player[6] + (other_player[4])/(other_player[8]) < 267) and (other_player[7]+ (other_player[5])/(other_player[9]) > 756) and (other_player[7]+ (other_player[5])/(other_player[9]) < 860) ) {selected_destination_blue = Apartments_boys;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 763) and (other_player[6] + (other_player[4])/(other_player[8]) < 877) and (other_player[7]+ (other_player[5])/(other_player[9]) > 807) and (other_player[7]+ (other_player[5])/(other_player[9]) < 914) ) {selected_destination_blue = OAT;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1197) and (other_player[6] + (other_player[4])/(other_player[8]) < 1471) and (other_player[7]+ (other_player[5])/(other_player[9]) > 665) and (other_player[7]+ (other_player[5])/(other_player[9]) < 836) ) {selected_destination_blue = Playground;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1409) and (other_player[6] + (other_player[4])/(other_player[8]) < 1650) and (other_player[7]+ (other_player[5])/(other_player[9]) > 927) and (other_player[7]+ (other_player[5])/(other_player[9]) < 1046) ) {selected_destination_blue = Research;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 1627) and (other_player[6] + (other_player[4])/(other_player[8]) < 1803) and (other_player[7]+ (other_player[5])/(other_player[9]) > 448) and (other_player[7]+ (other_player[5])/(other_player[9]) < 564) ) {selected_destination_blue = Library;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2571) and (other_player[6] + (other_player[4])/(other_player[8]) < 2693) and (other_player[7]+ (other_player[5])/(other_player[9]) > 712) and (other_player[7]+ (other_player[5])/(other_player[9]) < 848) ) {selected_destination_blue = Apartments_girls;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2008) and (other_player[6] + (other_player[4])/(other_player[8]) < 2230) and (other_player[7]+ (other_player[5])/(other_player[9]) > 611) and (other_player[7]+ (other_player[5])/(other_player[9]) < 769) ) {selected_destination_blue = LHC;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2229) and (other_player[6] + (other_player[4])/(other_player[8]) < 2385) and (other_player[7]+ (other_player[5])/(other_player[9]) > 176) and (other_player[7]+ (other_player[5])/(other_player[9]) < 278) ) {selected_destination_blue = Red_Home;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2613) and (other_player[6] + (other_player[4])/(other_player[8]) < 2708) and (other_player[7]+ (other_player[5])/(other_player[9]) > 444) and (other_player[7]+ (other_player[5])/(other_player[9]) < 536) ) {selected_destination_blue = Market;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2606) and (other_player[6] + (other_player[4])/(other_player[8]) < 2727) and (other_player[7]+ (other_player[5])/(other_player[9]) > 249) and (other_player[7]+ (other_player[5])/(other_player[9]) < 349) ) {selected_destination_blue = Amaltas;}
                                        else if ((other_player[6] + (other_player[4])/(other_player[8]) > 2208) and (other_player[6] + (other_player[4])/(other_player[8]) < 2366) and (other_player[7]+ (other_player[5])/(other_player[9]) > 428) and (other_player[7]+ (other_player[5])/(other_player[9]) < 542) ) {selected_destination_blue = School;}

                                        else {selected_destination_blue = NULL;}

                                        if ((!(selected_origin_blue==selected_destination_blue)) and selected_destination_blue!=NULL){
                                            int outgoing = selected_origin_blue->send_half();
                                            if (outgoing!=0){
                                                create_packet(outgoing, selected_origin_blue, selected_destination_blue);
                                            }
                                        }

                                        selected_origin_blue = NULL;
                                        selected_destination_blue = NULL;

                                    }else{
                                        // ERROR: select an origin first!
                                    }
                                }
                            
                        }
                    }





                }









            // if finished
            }else if (finished){
                if (finished_time > 0){ finished_time-=dt;}
                else{
                    gState = "GameOver";

                    Mix_HaltMusic();
                    Mix_PlayMusic( gMusic, -1 );

                    reset();
                }

            }else if (other_player[10]==1){
                // other player has quit
                quit = true;
                isquit = 1;
            }
		}






        void reset(){
            power_is_selected_blue = false;
            selected_power_blue = "None";

            power_is_selected_red = false;
            selected_power_red = "None";

            finished = false;
            finished_time = 3;

            Current_view_x = (my_loyalty == "Red")?1700:0;
            Current_view_y = 0;

            selected_origin_blue = NULL;
            selected_destination_blue = NULL;

            selected_origin_red = NULL;
            selected_destination_red = NULL;


            LHC->reset();
            Library->reset();
            Blue_Home->reset();
            Red_Home->reset();
            OAT->reset();
            Jwala->reset();
            Kara->reset();
            Apartments_boys->reset();
            Masala->reset();
            Hospital->reset();
            Apartments_girls->reset();
            School->reset();
            Market->reset();
            Amaltas->reset();
            Research->reset();
            Playground->reset();
            Main_building->reset();

            cannon1->reset();
            cannon2->reset();

            all_soldiers->reset();

        }
};
