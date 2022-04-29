class CannonBall {
	//
	public:
		//
		float x,y;
		float target_x, target_y;
		float speed;
		SoldierPacket* my_target_packet;
		bool alive;
		Planet* my_Cannon_building;



		CannonBall(Planet* Cannon_building){

			/*
			x = Cannon_building->x;
			y = Cannon_building->y;
			*/

			my_Cannon_building = Cannon_building;
			/*my_target_packet = target_packet;

			target_x = my_target_packet->x;
			target_y = my_target_packet->y;*/

			alive = false;
			speed = 15;
		}

		void set_new(SoldierPacket* target_packet){
			x = my_Cannon_building->x;
			y = my_Cannon_building->y;
			alive = true;

			my_target_packet = target_packet;

			target_x = my_target_packet->x;
			target_y = my_target_packet->y;

		}

		void update(){
			std::cout<<"in update"<<endl;
			if (this->alive) {
				std::cout<<"in update alive"<<endl;
				if (my_target_packet->alive){
					target_x = my_target_packet->x;
					target_y = my_target_packet->y;
				}

				if ((abs(target_x - x)+abs(target_y - y)) < 20){
					this->alive = false;
					my_Cannon_building->power_restore_time = 1;
					my_Cannon_building->power_available = false;

					if (my_target_packet->alive){my_target_packet->soldiers -= 5;}
				}

				x += (speed/(abs(target_x - x)+abs(target_y - y)))*(target_x - x);
				y += (speed/(abs(target_x - x)+abs(target_y - y)))*(target_y - y);
			}		
		}


		void render(float curr_screen_x, float curr_screen_y){
			if (this->alive) {
				std::cout<<"in render"<<endl;
				SDL_Rect fillRect = { x-10-curr_screen_x, y-10-curr_screen_y, 20*SCALING_FACTOR_X, 20*SCALING_FACTOR_Y  };
	        	SDL_SetRenderDrawColor( gRenderer, 100, 100, 100, 150 );
	        	SDL_RenderFillRect( gRenderer, &fillRect );
        	}
	    }


};