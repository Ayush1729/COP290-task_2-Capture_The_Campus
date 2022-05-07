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

			my_Cannon_building = Cannon_building;
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
			if (this->alive) {
				if (my_target_packet->alive){
					target_x = my_target_packet->x;
					target_y = my_target_packet->y;
				}

				if ((abs(target_x - x)+abs(target_y - y)) < 20){
					this->alive = false;
					my_Cannon_building->power_restore_time = 1;
					my_Cannon_building->power_available = false;

					if (my_target_packet->alive){my_target_packet->soldiers -= 5;}
					my_target_packet = NULL;
				}

				x += (speed/(abs(target_x - x)+abs(target_y - y)))*(target_x - x);
				y += (speed/(abs(target_x - x)+abs(target_y - y)))*(target_y - y);
			}		
		}


		void render(float curr_screen_x, float curr_screen_y){
			if (this->alive) {
				SDL_Rect fillRect = { (x-10-curr_screen_x)*SCALING_FACTOR_X, (y-10-curr_screen_y)*SCALING_FACTOR_Y, 20*SCALING_FACTOR_X, 20*SCALING_FACTOR_Y  };
	        	SDL_RenderCopy( gRenderer, gTexture_cannon, NULL, &fillRect );
        	}
	    }


	    void reset(){
	    	alive = false;
	    	my_target_packet = NULL;
	    }


};
