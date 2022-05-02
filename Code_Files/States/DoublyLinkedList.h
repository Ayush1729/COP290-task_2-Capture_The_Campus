class DoublyLinkedList{
	public:

		SoldierPacket* start_sentinel;
		SoldierPacket* end_sentinel;

		DoublyLinkedList(){
			/*SoldierPacket start_sentinel_obj;
			SoldierPacket end_sentinel_obj;
			SoldierPacket* start_sentinel = &(start_sentinel_obj);
			SoldierPacket* end_sentinel = &(end_sentinel_obj);

			This is correct, this is the way to create pointers.
			But there is a more direct way for class objects and all*/

			start_sentinel = new SoldierPacket;
			end_sentinel = new SoldierPacket;
			start_sentinel->next = end_sentinel;
			end_sentinel->prev = start_sentinel;
		}

		void insert(SoldierPacket* newPacket){
			newPacket->next = end_sentinel;
			newPacket->prev = end_sentinel->prev;
			end_sentinel->prev->next = newPacket;
			end_sentinel->prev = newPacket;
		}

		/*void remove(SoldierPacket* newPacket){
			newPacket->prev->next = newPacket->next;
			newPacket->next->prev = newPacket->prev;
			newPacket->next = NULL;
			newPacket->prev = NULL;
		}*/

		void update(float dt, Planet* fast_building, Planet* Fire_building, Planet* Acid_building, Planet* Road_block_building, Planet* Freeze_building, Planet* shield_building, Planet* Cannon_building1, Planet* Cannon_building2, CannonBall* cannon_ball_1, CannonBall* cannon_ball_2){
			SoldierPacket* temp;
			SoldierPacket* temp_next;
			temp = start_sentinel->next;
			while (temp->next != NULL){
				temp_next = temp->next;

				if ((temp->loyalty != Cannon_building1->loyalty) and (Cannon_building1->power_available) and (cannon_ball_1->alive == false)){
					if ((pow(temp->x - Cannon_building1->x,2) + pow(temp->y - Cannon_building1->y,2)) < pow(Cannon_building1->radius,2)){
						//std::cout<<Cannon_building1->power_available<<endl;
						Cannon_building1->power_available == false;
						Cannon_building1->power_restore_time = 20;

						std::cout<<"In range: shoot"<<endl;

						cannon_ball_1->set_new(temp);
					}
				}

				if ((temp->loyalty != Cannon_building2->loyalty) and (Cannon_building2->power_available) and (cannon_ball_2->alive == false)){
					if ((pow(temp->x - Cannon_building2->x,2) + pow(temp->y - Cannon_building2->y,2)) < pow(Cannon_building2->radius,2)){
						Cannon_building2->power_available == false;
						Cannon_building2->power_restore_time = 20;

						cannon_ball_2->set_new(temp);
					}
				}


				temp->update(dt, fast_building, Fire_building, Acid_building, Road_block_building, Freeze_building, shield_building);
				temp = temp_next;
			}
			temp = NULL;
			temp_next = NULL;
		}

		void render(float x, float y){
			SoldierPacket* temp;
			temp = start_sentinel->next;
			while (temp->next != NULL){
				temp->render(x,y);
				temp = temp->next;
			}
			temp = NULL;
		}


		void reset(){
			SoldierPacket* temp;
			SoldierPacket* temp_next;
			temp = start_sentinel->next;
			while (temp->next != NULL){
				temp_next = temp->next;
				temp->reset();
				temp = temp_next;
			}
			temp = NULL;
			temp_next = NULL;
		}
};
