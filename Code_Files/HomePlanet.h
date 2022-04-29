class HomePlanet: public Planet{
	//	
public:

	HomePlanet(string home_loyalty, int x_cor, int y_cor, string name): Planet{x_cor,y_cor, name, "None"}{
		loyalty = home_loyalty;
		soldiers = 50;
	}

	bool is_alive(){
		if (captured){
			return false;
		}else{
			return true;
		}
	}

	void update(float dt, string main_loyalty, Planet* emp_building, Planet* shield_building){

		spawn_time-=dt;
		if (spawn_time<0){
			soldiers+=1;

			if (this->loyalty==main_loyalty){
				spawn_time = 0.5;
			}else{
				spawn_time = 1;
			}
			
		}

		if ((this->loyalty != emp_building->loyalty) and (emp_building->power_stay_time>0) and ((pow(this->x - emp_building->power_circle_centre_x,2) + pow(this->y - emp_building->power_circle_centre_y,2)) < pow(emp_building->radius,2))) {
			this->collided(emp_building->loyalty, emp_building->power_strength, shield_building);
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
};