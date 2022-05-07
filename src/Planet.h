class Planet{
public:
	float x;
	float y;
	string identity;
	


	// variables for power usage
	string power;
	bool power_available = true;
	float power_restore_time;
	float power_stay_time = -1;
	float power_circle_centre_x;
	float power_circle_centre_y;
	int power_strength;
	float radius;




	Planet(int x_cor, int y_cor, string name, string planet_power){
		x = x_cor;
		y = y_cor;
		identity = name;
		this->power = planet_power; // ["None", "Cannon", "EMP", "Fire Circle", "Acid Circle", "Road Block", "Fast Spawn", "Fast Move", "Freeze", "Shield"]

		if (this->power == "Cannon"){
			this->radius = 200;
			this->power_strength = 5;
			this->power_available = false;
			this->power_stay_time = 2;
			this->power_restore_time = 5;
		}

	}

	string loyalty = "None";
	bool captured = false;
	int soldiers = 20;
	float spawn_time = 1;
	int outgoing_soldiers = 0;




	
	void collided(string incoming_loyalty, int incoming_soldiers, Planet* shield_building){
		if (loyalty == incoming_loyalty){
			soldiers = incoming_soldiers + soldiers;
		}else{
			if (!((this->loyalty == shield_building->loyalty) and (shield_building->power_stay_time>0) and ((pow(this->x - shield_building->power_circle_centre_x,2) + pow(this->y - shield_building->power_circle_centre_y,2)) < pow(shield_building->radius,2)))){
				if (incoming_soldiers>soldiers){
					soldiers = incoming_soldiers - soldiers;
					loyalty = incoming_loyalty;

					power_stay_time = -1;
					power_restore_time = 15;
					power_available = true;

					/// change later giving time gap in between fight and declaring capture
					captured = true;
					// there will be multiple captures later for simple planets

				}else{
					soldiers = soldiers - incoming_soldiers;
				}
			}
		}
	}

	void update(float dt, Planet* emp_building, Planet* shield_building){

		spawn_time-=dt;
		if ((spawn_time<0) and (!(loyalty=="None" and soldiers>=20))){
			soldiers+=1;
			spawn_time = 1;
		}


		if ((this->loyalty != emp_building->loyalty) and (emp_building->power_available) and (emp_building->power_stay_time>0) and ((pow(this->x - emp_building->power_circle_centre_x,2) + pow(this->y - emp_building->power_circle_centre_y,2)) < pow(emp_building->radius,2))) {
			this->collided(emp_building->loyalty, emp_building->power_strength, shield_building);
			emp_building->power_available = false;
		}

		

		if (power_available == false){
			power_restore_time-=(dt);
			if (power_restore_time<0){
				power_restore_time = 15;
				power_available = true;
			}
			
		}

		if (power_stay_time>0){
			power_stay_time-=dt;
		}
	}

	void render(float curr_screen_x, float curr_screen_y){
        SDL_Rect fillRect = { (x-20-curr_screen_x)*SCALING_FACTOR_X, (y-20-curr_screen_y)*SCALING_FACTOR_Y, 40*SCALING_FACTOR_X, 40*SCALING_FACTOR_Y  };
        if (loyalty=="Red"){
        	SDL_SetRenderDrawColor( gRenderer, 255, 0, 0, 150 );
        	SDL_RenderFillRect( gRenderer, &fillRect );
        	for (int i = 0;i<soldiers; i++){
        		SDL_Rect particleRect = { (x-curr_screen_x-((rand()%80)-40))*SCALING_FACTOR_X, (y-curr_screen_y-((rand()%80)-40))*SCALING_FACTOR_Y, 3*SCALING_FACTOR_X, 3*SCALING_FACTOR_Y };
        		SDL_SetRenderDrawColor( gRenderer, 255, 0, 0, 255 );
        		SDL_RenderFillRect( gRenderer, &particleRect );
        	}
        }else if (loyalty == "Blue"){
        	SDL_SetRenderDrawColor( gRenderer, 0, 0, 255, 150 );
        	SDL_RenderFillRect( gRenderer, &fillRect );
        	for (int i = 0;i<soldiers; i++){
        		SDL_Rect particleRect = { (x-curr_screen_x-((rand()%80)-40))*SCALING_FACTOR_X, (y-curr_screen_y-((rand()%80)-40))*SCALING_FACTOR_Y, 3*SCALING_FACTOR_X, 3*SCALING_FACTOR_Y };
        		SDL_SetRenderDrawColor( gRenderer, 0, 0, 255, 255 );
        		SDL_RenderFillRect( gRenderer, &particleRect );
        	}
        }else{
        	SDL_SetRenderDrawColor( gRenderer, 50, 175, 50, 150 );
        	SDL_RenderFillRect( gRenderer, &fillRect );
        	for (int i = 0;i<soldiers; i++){
        		SDL_Rect particleRect = { (x-curr_screen_x-((rand()%80)-40))*SCALING_FACTOR_X, (y-curr_screen_y-((rand()%80)-40))*SCALING_FACTOR_Y, 3*SCALING_FACTOR_X, 3*SCALING_FACTOR_Y };
        		SDL_SetRenderDrawColor( gRenderer, 50, 175, 50, 150 );
        		SDL_RenderFillRect( gRenderer, &particleRect );
        	}
        }



        //Render text
        SDL_Color textColor = { 255, 255, 255 };
        if( !loadFromRenderedText(to_string(soldiers), textColor, gPacifico)) {
            std::cout<<"Failed to render text texture in planet!"<<std::endl;
            error_occ = true;
        }

        SDL_Rect titl_pos = { (x-15-curr_screen_x)*SCALING_FACTOR_X, (y-15-curr_screen_y)*SCALING_FACTOR_Y, 30*SCALING_FACTOR_X, 30*SCALING_FACTOR_Y  };
        // Text on screen
        SDL_RenderCopy( gRenderer, gTextTexture, NULL, &titl_pos );



	}


	int send_half(){
		if (soldiers>=10){
			outgoing_soldiers = soldiers/2;
			soldiers =  soldiers - outgoing_soldiers;
		}else{
			outgoing_soldiers = 0;
		}
		return outgoing_soldiers;
	}


	int send_all(){
		if (soldiers>=10){
			outgoing_soldiers = soldiers;
			soldiers = 0;
		}else{
			outgoing_soldiers = 0;
		}
		return outgoing_soldiers;
	}



	void reset(){
		soldiers = 20;
		power_available = true;
		power_restore_time = 15;
		power_stay_time = -1;

		loyalty = "None";
		captured = false;
		spawn_time = 1;
		outgoing_soldiers = 0;
	}



};
