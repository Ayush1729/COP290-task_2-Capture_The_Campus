class SoldierPacket{
	//

float speed = 5; // private

public:
	int soldiers;
	string loyalty;
	bool alive = true;
	int x,y;

	Path my_path = A_Z1;

	// for iteration and adding to DLL
	SoldierPacket* next = NULL;
	SoldierPacket* prev = NULL;

	int destination_x;
	int destination_y;
	Planet* dest;


	int curr_dest_x;
	int curr_dest_y;
	int curr_dest_num = 1;
	int total_dest_num;

	SoldierPacket(){
		//
	}

	SoldierPacket(int sol_num, Planet* destination, Planet* origin){
		soldiers = sol_num;
		dest = destination;
		//std::cout<<"in"<<endl;
		destination_x = destination->x;
		destination_y = destination->y;
		//std::cout<<"mid"<<endl;

		//std::cout<<"end"<<endl;
		//speed_x = (speed/(abs(destination_x - x)+abs(destination_y - y)))*(destination_x - x);
		//speed_y = (speed/(abs(destination_x - x)+abs(destination_y - y)))*(destination_y - y);

		loyalty = origin->loyalty;



		if (origin->identity == "Jwala"){

			if (destination->identity == "Vindhyachal"){
				my_path = A_Z1 + Z1_C;
			}else if (destination->identity == "Kara"){
				my_path = A_Z1 + Z1_B;
			}else if (destination->identity == "OAT"){
				my_path = A_Z1 + Z1_B + B_D + D_Z8 + Z8_E;
			}else if (destination->identity == "Apartments boys"){
				my_path = A_Z1 + Z1_B + B_Z4 + Z4_F + F_G;
			}else if (destination->identity == "Masala Mix"){
				my_path = A_Z1 + Z1_C + C_Z2 + Z2_Z3 + Z3_J;
			}else if (destination->identity == "Hospital"){
				my_path = A_Z1 + Z1_C + C_Z2 + Z2_D + D_I + I_K;
			}else if (destination->identity == "Playground"){
				my_path = A_Z1 + Z1_C + C_Z2 + Z2_D + D_I + I_K + K_L;
			}else if (destination->identity == "Research Park"){
				my_path = A_Z1 + Z1_B + B_Z4 + Z4_F + F_Z5 + Z5_Z6 + Z6_H + H_X;
			}else if (destination->identity == "Main Building"){
				my_path = A_Z1 + Z1_C + C_Z2 + Z2_D + D_I + I_K + K_L + L_M + M_N + N_Z9 + Z9_O;
			}else if (destination->identity == "Library"){
				my_path = A_Z1 + Z1_C + C_Z2 + Z2_D + D_I + I_K + K_L + L_M + M_N;
			}else if (destination->identity == "LHC"){
				my_path = A_Z1 + Z1_C + C_Z2 + Z2_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_Q;
			}else if (destination->identity == "Himadri"){
				my_path = A_Z1 + Z1_C + C_Z2 + Z2_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_S;
			}else if (destination->identity == "Kendriya Vidyalaya"){
				my_path = A_Z1 + Z1_C + C_Z2 + Z2_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R;
			}else if (destination->identity == "Amaltas"){
				my_path = A_Z1 + Z1_C + C_Z2 + Z2_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_T;
			}else if (destination->identity == "IITD Market"){
				my_path = A_Z1 + Z1_C + C_Z2 + Z2_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_Z15 + Z15_V;
			}else if (destination->identity == "Apartments girls"){
				my_path = A_Z1 + Z1_B + B_Z4 + Z4_F + F_Z5 + Z5_Z6 + Z6_H + H_X + X_W;
			}
		}






		else if (origin->identity == "Vindhyachal"){

			if (destination->identity == "Kara"){
				my_path = C_Z1 + Z1_B;
			}else if (destination->identity == "OAT"){
				my_path = C_Z2 + Z2_D + D_Z8 + Z8_E;
			}else if (destination->identity == "Apartments boys"){
				my_path = C_Z1 + Z1_B + B_Z4 + Z4_F + F_G;
			}else if (destination->identity == "Masala Mix"){
				my_path = C_Z2 + Z2_Z3 + Z3_J;
			}else if (destination->identity == "Jwala"){
				my_path = C_Z1 + Z1_A;
			}else if (destination->identity == "Hospital"){
				my_path = C_Z2 + Z2_D + D_I + I_K;
			}else if (destination->identity == "Playground"){
				my_path = C_Z2 + Z2_D + D_I + I_K + K_L;
			}else if (destination->identity == "Research Park"){
				my_path = C_Z2 + Z2_D + D_I + I_Z17 + Z17_H + H_X;
			}else if (destination->identity == "Main Building"){
				my_path = C_Z2 + Z2_D + D_I + I_K + K_L + L_M + M_N + N_Z9 + Z9_O;
			}else if (destination->identity == "Library"){
				my_path = C_Z2 + Z2_D + D_I + I_K + K_L + L_M + M_N;
			}else if (destination->identity == "LHC"){
				my_path = C_Z2 + Z2_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_Q;
			}else if (destination->identity == "Himadri"){
				my_path = C_Z2 + Z2_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_S;
			}else if (destination->identity == "Kendriya Vidyalaya"){
				my_path = C_Z2 + Z2_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R;
			}else if (destination->identity == "Amaltas"){
				my_path = C_Z2 + Z2_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_T;
			}else if (destination->identity == "IITD Market"){
				my_path = C_Z2 + Z2_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_Z15 + Z15_V;
			}else if (destination->identity == "Apartments girls"){
				my_path = C_Z2 + Z2_D + D_I + I_Z17 + Z17_H + H_X + X_W;
			}
		}









		else if (origin->identity == "Kara"){

			if (destination->identity == "Vindhyachal"){
				my_path = B_Z1 + Z1_C;
			}else if (destination->identity == "OAT"){
				my_path = B_D + D_Z8 + Z8_E;
			}else if (destination->identity == "Apartments boys"){
				my_path = B_Z4 + Z4_F + F_G;
			}else if (destination->identity == "Masala Mix"){
				my_path = B_D + D_I + I_J;
			}else if (destination->identity == "Jwala"){
				my_path = B_Z1 + Z1_A;
			}else if (destination->identity == "Hospital"){
				my_path = B_D + D_I + I_K;
			}else if (destination->identity == "Playground"){
				my_path = B_D + D_I + I_K + K_L;
			}else if (destination->identity == "Research Park"){
				my_path = B_D + D_I + I_Z17 + Z17_H + H_X;
			}else if (destination->identity == "Main Building"){
				my_path = B_D + D_I + I_K + K_L + L_M + M_N + N_Z9 + Z9_O;;
			}else if (destination->identity == "Library"){
				my_path = B_D + D_I + I_K + K_L + L_M + M_N;
			}else if (destination->identity == "LHC"){
				my_path = B_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_Q;
			}else if (destination->identity == "Himadri"){
				my_path = B_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_S;
			}else if (destination->identity == "Kendriya Vidyalaya"){
				my_path = B_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R;
			}else if (destination->identity == "Amaltas"){
				my_path = B_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_T;
			}else if (destination->identity == "IITD Market"){
				my_path = B_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_Z15 + Z15_V;
			}else if (destination->identity == "Apartments girls"){
				my_path = B_D + D_I + I_Z17 + Z17_H + H_X + X_W;
			}
		}










		else if (origin->identity == "OAT"){

			if (destination->identity == "Vindhyachal"){
				my_path = E_Z8 + Z8_D + D_Z2 + Z2_C; 
			}else if (destination->identity == "Kara"){
				my_path = E_Z8 + Z8_D + D_B;
			}else if (destination->identity == "Apartments boys"){
				my_path = E_Z8 + Z8_Z7 + Z7_Z4 + Z4_F + F_G;
			}else if (destination->identity == "Masala Mix"){
				my_path = E_Z8 + Z8_D + D_I + I_J;
			}else if (destination->identity == "Jwala"){
				my_path = E_Z8 + Z8_D + D_B + B_Z1 + Z1_A;
			}else if (destination->identity == "Hospital"){
				my_path = E_Z8 + Z8_D + D_I + I_K;
			}else if (destination->identity == "Playground"){
				my_path = E_Z8 + Z8_D + D_I + I_K + K_L;
			}else if (destination->identity == "Research Park"){
				my_path = E_Z8 + Z8_D + D_I + I_Z17 + Z17_H  + H_X;
			}else if (destination->identity == "Main Building"){
				my_path = E_Z8 + Z8_D + D_I + I_K + K_L + L_M + M_N + N_Z9 + Z9_O;;
			}else if (destination->identity == "Library"){
				my_path = E_Z8 + Z8_D + D_I + I_K + K_L + L_M + M_N;
			}else if (destination->identity == "LHC"){
				my_path = E_Z8 + Z8_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_Q;
			}else if (destination->identity == "Himadri"){
				my_path = E_Z8 + Z8_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_S;
			}else if (destination->identity == "Kendriya Vidyalaya"){
				my_path = E_Z8 + Z8_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R;
			}else if (destination->identity == "Amaltas"){
				my_path = E_Z8 + Z8_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_T;
			}else if (destination->identity == "IITD Market"){
				my_path = E_Z8 + Z8_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_Z15 + Z15_V;
			}else if (destination->identity == "Apartments girls"){
				my_path = E_Z8 + Z8_D + D_I + I_Z17 + Z17_H + H_X + X_W;
			}
		}












		else if (origin->identity == "Apartments boys"){

			if (destination->identity == "Vindhyachal"){
				my_path = G_F + F_Z4 + Z4_B + B_Z1 + Z1_C;
			}else if (destination->identity == "Kara"){
				my_path = G_F + F_Z4 + Z4_B;
			}else if (destination->identity == "OAT"){
				my_path = G_F + F_Z4 + Z4_Z7 + Z7_Z8 + Z8_E;
			}else if (destination->identity == "Masala Mix"){
				my_path = G_F + F_Z4 + Z4_B + B_D + D_I + I_J;
			}else if (destination->identity == "Jwala"){
				my_path = G_F + F_Z4 + Z4_B + B_Z1 + Z1_A;
			}else if (destination->identity == "Hospital"){
				my_path = G_F + F_Z4 + Z4_B + B_D + D_I + I_K;
			}else if (destination->identity == "Playground"){
				my_path = G_F + F_Z4 + Z4_B + B_D + D_I + I_K + K_L;
			}else if (destination->identity == "Research Park"){
				my_path = G_F + F_Z5 + Z5_Z6 + Z6_H + H_X;
			}else if (destination->identity == "Main Building"){
				my_path = G_F + F_Z4 + Z4_B + B_D + D_I + I_K + K_L + L_M + M_N + N_Z9 + Z9_O;;
			}else if (destination->identity == "Library"){
				my_path = G_F + F_Z4 + Z4_B + B_D + D_I + I_K + K_L + L_M + M_N;
			}else if (destination->identity == "LHC"){
				my_path = G_F + F_Z4 + Z4_B + B_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_Q;
			}else if (destination->identity == "Himadri"){
				my_path = G_F + F_Z4 + Z4_B + B_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_S;
			}else if (destination->identity == "Kendriya Vidyalaya"){
				my_path = G_F + F_Z4 + Z4_B + B_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R;
			}else if (destination->identity == "Amaltas"){
				my_path = G_F + F_Z4 + Z4_B + B_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_T;
			}else if (destination->identity == "IITD Market"){
				my_path = G_F + F_Z4 + Z4_B + B_D + D_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_Z15 + Z15_V;
			}else if (destination->identity == "Apartments girls"){
				my_path = G_F + F_Z5 + Z5_Z6 + Z6_H + H_X + X_W;
			}
		}









		else if (origin->identity == "Masala Mix"){ 

			if (destination->identity == "Vindhyachal"){
				my_path = J_Z3 + Z3_Z2 + Z2_C;
			}else if (destination->identity == "Kara"){
				my_path = J_I + I_D + D_B;
			}else if (destination->identity == "OAT"){
				my_path = J_I + I_D + D_Z8 + Z8_E;
			}else if (destination->identity == "Apartments boys"){
				my_path = J_I + I_D + D_B + B_Z4 + Z4_F + F_G;
			}else if (destination->identity == "Jwala"){
				my_path = J_Z3 + Z3_Z2 + Z2_C + C_Z1 + Z1_A;
			}else if (destination->identity == "Hospital"){
				my_path = J_I + I_K;
			}else if (destination->identity == "Playground"){
				my_path = J_I + I_K + K_L;
			}else if (destination->identity == "Research Park"){
				my_path = J_I + I_Z17 + Z17_H + H_X;
			}else if (destination->identity == "Main Building"){
				my_path = J_I + I_K + K_L + L_M + M_N + N_Z9 + Z9_O;
			}else if (destination->identity == "Library"){
				my_path = J_I + I_K + K_L + L_M + M_N;
			}else if (destination->identity == "LHC"){
				my_path = J_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_Q;
			}else if (destination->identity == "Himadri"){
				my_path = J_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_S;
			}else if (destination->identity == "Kendriya Vidyalaya"){
				my_path = J_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R;
			}else if (destination->identity == "Amaltas"){
				my_path = J_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_T;
			}else if (destination->identity == "IITD Market"){
				my_path = J_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_Z15 + Z15_V;
			}else if (destination->identity == "Apartments girls"){
				my_path = J_I + I_Z17 + Z17_H + H_X + X_W;
			}
		}










		else if (origin->identity == "Hospital"){ 

			if (destination->identity == "Vindhyachal"){
				my_path = K_I + I_D + D_Z2 + Z2_C;
			}else if (destination->identity == "Kara"){
				my_path = K_I + I_D + D_B;
			}else if (destination->identity == "OAT"){
				my_path = K_I + I_D + D_Z8 + Z8_E;
			}else if (destination->identity == "Apartments boys"){
				my_path = K_I + I_D + D_B + B_Z4 + Z4_F + F_G;
			}else if (destination->identity == "Masala Mix"){
				my_path = K_I + I_J;
			}else if (destination->identity == "Jwala"){
				my_path = K_I + I_D + D_B + B_Z1 + Z1_A;
			}else if (destination->identity == "Playground"){
				my_path = K_L;
			}else if (destination->identity == "Research Park"){
				my_path = K_I + I_Z17 + Z17_H + H_X;
			}else if (destination->identity == "Main Building"){
				my_path = K_L + L_M + M_N + N_Z9 + Z9_O;
			}else if (destination->identity == "Library"){
				my_path = K_L + L_M + M_N;
			}else if (destination->identity == "LHC"){
				my_path = K_L + L_M + M_Z10 + Z10_Z11 + Z11_Q;
			}else if (destination->identity == "Himadri"){
				my_path = K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_S;
			}else if (destination->identity == "Kendriya Vidyalaya"){
				my_path = K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R;
			}else if (destination->identity == "Amaltas"){
				my_path = K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_T;
			}else if (destination->identity == "IITD Market"){
				my_path = K_L + L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_Z15 + Z15_V;
			}else if (destination->identity == "Apartments girls"){
				my_path = K_I + I_Z17 + Z17_H + H_X + X_W;
			}
		}











		else if (origin->identity == "Playground"){ 

			if (destination->identity == "Vindhyachal"){
				my_path = L_K + K_I + I_D + D_Z2 + Z2_C;
			}else if (destination->identity == "Kara"){
				my_path = L_K + K_I + I_D + D_B;
			}else if (destination->identity == "OAT"){
				my_path = L_K + K_I + I_D + D_Z8 + Z8_E;
			}else if (destination->identity == "Apartments boys"){
				my_path = L_K + K_I + I_D + D_B + B_Z4 + Z4_F + F_G;
			}else if (destination->identity == "Masala Mix"){
				my_path = L_K + K_I + I_J;
			}else if (destination->identity == "Jwala"){
				my_path = L_K + K_I + I_D + D_B + B_Z1 + Z1_A;
			}else if (destination->identity == "Hospital"){
				my_path = L_K;
			}else if (destination->identity == "Research Park"){
				my_path = L_K + K_I + I_Z17 + Z17_H + H_X;
			}else if (destination->identity == "Main Building"){
				my_path = L_M + M_N + N_Z9 + Z9_O;
			}else if (destination->identity == "Library"){
				my_path = L_M + M_N;
			}else if (destination->identity == "LHC"){
				my_path = L_M + M_Z10 + Z10_Z11 + Z11_Q;
			}else if (destination->identity == "Himadri"){
				my_path = L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_S;
			}else if (destination->identity == "Kendriya Vidyalaya"){
				my_path = L_M + M_Z10 + Z10_Z11 + Z11_P + P_R;
			}else if (destination->identity == "Amaltas"){
				my_path = L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_T;
			}else if (destination->identity == "IITD Market"){
				my_path = L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_Z15 + Z15_V;
			}else if (destination->identity == "Apartments girls"){
				my_path = L_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_Z15 + Z15_V + V_Z16 + Z16_W;
			}
		}










		else if (origin->identity == "Research Park"){ 

			if (destination->identity == "Vindhyachal"){
				my_path = X_H + H_Z17 + Z17_I + I_D + D_Z2 + Z2_C;
			}else if (destination->identity == "Kara"){
				my_path = X_H + H_Z17 + Z17_I + I_D + D_B;
			}else if (destination->identity == "OAT"){
				my_path = X_H + H_Z17 + Z17_I + I_D + D_Z8 + Z8_E;
			}else if (destination->identity == "Apartments boys"){
				my_path = X_H + H_Z6 + Z6_Z5 + Z5_F + F_G;
			}else if (destination->identity == "Masala Mix"){
				my_path = X_H + H_Z17 + Z17_I + I_J;
			}else if (destination->identity == "Jwala"){
				my_path = X_H + H_Z17 + Z17_I + I_D + D_B + B_Z1 + Z1_A;
			}else if (destination->identity == "Hospital"){
				my_path = X_H + H_Z17 + Z17_I + I_K;
			}else if (destination->identity == "Playground"){
				my_path = X_H + H_Z17 + Z17_I + I_K + K_L;
			}else if (destination->identity == "Main Building"){
				my_path = X_H + H_Z17 + Z17_I + I_K + K_L + L_M + M_N + N_Z9 + Z9_O;
			}else if (destination->identity == "Library"){
				my_path = X_H + H_Z17 + Z17_I + I_K + K_L + L_M + M_N;
			}else if (destination->identity == "LHC"){
				my_path = X_H + H_Z17 + Z17_I + I_K + K_L + L_M + M_Z10 + Z10_Z11 + Z11_Q;
			}else if (destination->identity == "Himadri"){
				my_path = X_W + W_Z16 + Z16_V + V_Z15 + Z15_Z14 + Z14_U + U_S;
			}else if (destination->identity == "Kendriya Vidyalaya"){
				my_path = X_W + W_Z16 + Z16_V + V_Z15 + Z15_Z14 + Z14_U + U_R;
			}else if (destination->identity == "Amaltas"){
				my_path = X_W + W_Z16 + Z16_V + V_Z15 + Z15_Z14 + Z14_T;
			}else if (destination->identity == "IITD Market"){
				my_path = X_W + W_Z16 + Z16_V;
			}else if (destination->identity == "Apartments girls"){
				my_path = X_W;
			}
		}









		else if (origin->identity == "Main Building"){ 

			if (destination->identity == "Vindhyachal"){
				my_path = O_Z9 + Z9_N + N_M + M_L + L_K + K_I + I_D + D_Z2 + Z2_C;
			}else if (destination->identity == "Kara"){
				my_path = O_Z9 + Z9_N + N_M + M_L + L_K + K_I + I_D + D_B;
			}else if (destination->identity == "OAT"){
				my_path = O_Z9 + Z9_N + N_M + M_L + L_K + K_I + I_D + D_Z8 + Z8_E;
			}else if (destination->identity == "Apartments boys"){
				my_path = O_Z9 + Z9_N + N_M + M_L + L_K + K_I + I_D + D_B + B_Z4 + Z4_F + F_G;
			}else if (destination->identity == "Masala Mix"){
				my_path = O_Z9 + Z9_N + N_M + M_L + L_K + K_I + I_J;
			}else if (destination->identity == "Jwala"){
				my_path = O_Z9 + Z9_N + N_M + M_L + L_K + K_I + I_D + D_B + B_Z1 + Z1_A;
			}else if (destination->identity == "Hospital"){
				my_path = O_Z9 + Z9_N + N_M + M_L + L_K;
			}else if (destination->identity == "Playground"){
				my_path = O_Z9 + Z9_N + N_M + M_L;
			}else if (destination->identity == "Research Park"){
				my_path = O_Z9 + Z9_N + N_M + M_L + L_K + K_I + I_Z17 + Z17_H + H_X;
			}else if (destination->identity == "Library"){
				my_path = O_Z9 + Z9_N;
			}else if (destination->identity == "LHC"){
				my_path = O_Z9 + Z9_N + N_M + M_Z10 + Z10_Z11 + Z11_Q;
			}else if (destination->identity == "Himadri"){
				my_path = O_Z13 + Z13_Z12 + Z12_P + P_R + R_U + U_S;
			}else if (destination->identity == "Kendriya Vidyalaya"){
				my_path = O_Z13 + Z13_Z12 + Z12_P + P_R;
			}else if (destination->identity == "Amaltas"){
				my_path = O_Z13 + Z13_Z12 + Z12_P + P_R + R_U + U_Z14 + Z14_T;
			}else if (destination->identity == "IITD Market"){
				my_path = O_Z13 + Z13_Z12 + Z12_P + P_R + R_U + U_Z14 + Z14_Z15 + Z15_V;
			}else if (destination->identity == "Apartments girls"){
				my_path = O_Z13 + Z13_Z12 + Z12_P + P_R + R_U + U_Z14 + Z14_Z15 + Z15_V + V_Z16 + Z16_W;
			}
		}










		else if (origin->identity == "Library"){ 

			if (destination->identity == "Vindhyachal"){
				my_path = N_M + M_L + L_K + K_I + I_D + D_Z2 + Z2_C;
			}else if (destination->identity == "Kara"){
				my_path = N_M + M_L + L_K + K_I + I_D + D_B;
			}else if (destination->identity == "OAT"){
				my_path = N_M + M_L + L_K + K_I + I_D + D_Z8 + Z8_E;
			}else if (destination->identity == "Apartments boys"){
				my_path = N_M + M_L + L_K + K_I + I_D + D_B + B_Z4 + Z4_F + F_G;
			}else if (destination->identity == "Masala Mix"){
				my_path = N_M + M_L + L_K + K_I + I_J;
			}else if (destination->identity == "Jwala"){
				my_path = N_M + M_L + L_K + K_I + I_D + D_B + B_Z1 + Z1_A;
			}else if (destination->identity == "Hospital"){
				my_path = N_M + M_L + L_K;
			}else if (destination->identity == "Playground"){
				my_path = N_M + M_L;
			}else if (destination->identity == "Research Park"){
				my_path = N_M + M_L + L_K + K_I + I_Z17 + Z17_H + H_X;
			}else if (destination->identity == "Main Building"){
				my_path = N_Z9 + Z9_O;
			}else if (destination->identity == "LHC"){
				my_path = N_M + M_Z10 + Z10_Z11 + Z11_Q;
			}else if (destination->identity == "Himadri"){
				my_path = N_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_S;
			}else if (destination->identity == "Kendriya Vidyalaya"){
				my_path = N_M + M_Z10 + Z10_Z11 + Z11_P + P_R;
			}else if (destination->identity == "Amaltas"){
				my_path = N_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_T;
			}else if (destination->identity == "IITD Market"){
				my_path = N_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_Z15 + Z15_V;
			}else if (destination->identity == "Apartments girls"){
				my_path = N_M + M_Z10 + Z10_Z11 + Z11_P + P_R + R_U + U_Z14 + Z14_Z15 + Z15_V + V_Z16 + Z16_W;
			}
		}









		else if (origin->identity == "LHC"){ 

			if (destination->identity == "Vindhyachal"){
				//
			}else if (destination->identity == "Kara"){
				//
			}else if (destination->identity == "OAT"){
				//
			}else if (destination->identity == "Apartments boys"){
				//
			}else if (destination->identity == "Masala Mix"){
				//
			}else if (destination->identity == "Jwala"){
				//
			}else if (destination->identity == "Hospital"){
				//
			}else if (destination->identity == "Playground"){
				//
			}else if (destination->identity == "Research Park"){
				//
			}else if (destination->identity == "Main Building"){
				//
			}else if (destination->identity == "Library"){
				//
			}else if (destination->identity == "Himadri"){
				//
			}else if (destination->identity == "Kendriya Vidyalaya"){
				//
			}else if (destination->identity == "Amaltas"){
				//
			}else if (destination->identity == "IITD Market"){
				//
			}else if (destination->identity == "Apartments girls"){
				//
			}
		}








		else if (origin->identity == "Himadri"){ 

			if (destination->identity == "Vindhyachal"){
				//
			}else if (destination->identity == "Kara"){
				//
			}else if (destination->identity == "OAT"){
				//
			}else if (destination->identity == "Apartments boys"){
				//
			}else if (destination->identity == "Masala Mix"){
				//
			}else if (destination->identity == "Jwala"){
				//
			}else if (destination->identity == "Hospital"){
				//
			}else if (destination->identity == "Playground"){
				//
			}else if (destination->identity == "Research Park"){
				//
			}else if (destination->identity == "Main Building"){
				//
			}else if (destination->identity == "Library"){
				//
			}else if (destination->identity == "LHC"){
				//
			}else if (destination->identity == "Kendriya Vidyalaya"){
				//
			}else if (destination->identity == "Amaltas"){
				//
			}else if (destination->identity == "IITD Market"){
				//
			}else if (destination->identity == "Apartments girls"){
				//
			}
		}








		else if (origin->identity == "Kendriya Vidyalaya"){ 

			if (destination->identity == "Vindhyachal"){
				//
			}else if (destination->identity == "Kara"){
				//
			}else if (destination->identity == "OAT"){
				//
			}else if (destination->identity == "Apartments boys"){
				//
			}else if (destination->identity == "Masala Mix"){
				//
			}else if (destination->identity == "Jwala"){
				//
			}else if (destination->identity == "Hospital"){
				//
			}else if (destination->identity == "Playground"){
				//
			}else if (destination->identity == "Research Park"){
				//
			}else if (destination->identity == "Main Building"){
				//
			}else if (destination->identity == "Library"){
				//
			}else if (destination->identity == "LHC"){
				//
			}else if (destination->identity == "Himadri"){
				//
			}else if (destination->identity == "Amaltas"){
				//
			}else if (destination->identity == "IITD Market"){
				//
			}else if (destination->identity == "Apartments girls"){
				//
			}
		}










		else if (origin->identity == "Amaltas"){ 

			if (destination->identity == "Vindhyachal"){
				//
			}else if (destination->identity == "Kara"){
				//
			}else if (destination->identity == "OAT"){
				//
			}else if (destination->identity == "Apartments boys"){
				//
			}else if (destination->identity == "Masala Mix"){
				//
			}else if (destination->identity == "Jwala"){
				//
			}else if (destination->identity == "Hospital"){
				//
			}else if (destination->identity == "Playground"){
				//
			}else if (destination->identity == "Research Park"){
				//
			}else if (destination->identity == "Main Building"){
				//
			}else if (destination->identity == "Library"){
				//
			}else if (destination->identity == "LHC"){
				//
			}else if (destination->identity == "Himadri"){
				//
			}else if (destination->identity == "Kendriya Vidyalaya"){
				//
			}else if (destination->identity == "IITD Market"){
				//
			}else if (destination->identity == "Apartments girls"){
				//
			}
		}










		else if (origin->identity == "IITD Market"){ 

			if (destination->identity == "Vindhyachal"){
				//
			}else if (destination->identity == "Kara"){
				//
			}else if (destination->identity == "OAT"){
				//
			}else if (destination->identity == "Apartments boys"){
				//
			}else if (destination->identity == "Masala Mix"){
				//
			}else if (destination->identity == "Jwala"){
				//
			}else if (destination->identity == "Hospital"){
				//
			}else if (destination->identity == "Playground"){
				//
			}else if (destination->identity == "Research Park"){
				//
			}else if (destination->identity == "Main Building"){
				//
			}else if (destination->identity == "Library"){
				//
			}else if (destination->identity == "LHC"){
				//
			}else if (destination->identity == "Himadri"){
				//
			}else if (destination->identity == "Kendriya Vidyalaya"){
				//
			}else if (destination->identity == "Amaltas"){
				//
			}else if (destination->identity == "Apartments girls"){
				//
			}
		}







		else if (origin->identity == "Apartments girls"){ 

			if (destination->identity == "Vindhyachal"){
				//
			}else if (destination->identity == "Kara"){
				//
			}else if (destination->identity == "OAT"){
				//
			}else if (destination->identity == "Apartments boys"){
				//
			}else if (destination->identity == "Masala Mix"){
				//
			}else if (destination->identity == "Jwala"){
				//
			}else if (destination->identity == "Hospital"){
				//
			}else if (destination->identity == "Playground"){
				//
			}else if (destination->identity == "Research Park"){
				//
			}else if (destination->identity == "Main Building"){
				//
			}else if (destination->identity == "Library"){
				//
			}else if (destination->identity == "LHC"){
				//
			}else if (destination->identity == "Himadri"){
				//
			}else if (destination->identity == "Kendriya Vidyalaya"){
				//
			}else if (destination->identity == "Amaltas"){
				//
			}else if (destination->identity == "IITD Market"){
				//
			}
		}






		this->x = this->my_path.arr[0]->x;
		this->y = this->my_path.arr[0]->y;


		this->total_dest_num = this->my_path.arr.size();
	}









	void collision(Planet* shield_building){
		// if collision with planet, alive = false, else if collision with another opposite packet, bigger one survives.
		this->alive = false; // setting directly to false for now, ignoring mid-path collisions
		dest->collided(loyalty, soldiers, shield_building);
	}

	void update(float dt, Planet* fast_building, Planet* Fire_building, Planet* Acid_building, Planet* Road_block_building, Planet* Freeze_building, Planet* shield_building){

		if ((this->loyalty != Freeze_building->loyalty) and (Freeze_building->power_stay_time > 0)){
			this->speed = 0;
		}else if (this->loyalty == fast_building->loyalty){
			this->speed = 10;
		}else {this->speed = 5;}



		if ((this->loyalty != Fire_building->loyalty) and (Fire_building->power_stay_time > 0)){
			if ((pow(this->x - Fire_building->power_circle_centre_x,2) + pow(this->y - Fire_building->power_circle_centre_y,2)) < pow(Fire_building->radius,2)) {
				this->soldiers -= 3;
			}
		}

		if ((this->loyalty != Acid_building->loyalty) and (Acid_building->power_stay_time > 0)){
			if ((pow(this->x - Acid_building->power_circle_centre_x,2) + pow(this->y - Acid_building->power_circle_centre_y,2)) < pow(Acid_building->radius,2)) {
				this->soldiers -= 3;
			}
		}


		if ((this->loyalty != Road_block_building->loyalty) and (Road_block_building->power_stay_time > 0)){
			if ((pow(this->x - Road_block_building->power_circle_centre_x,2) + pow(this->y - Road_block_building->power_circle_centre_y,2)) < pow(Road_block_building->radius,2)) {
				this->speed = 0;
			}
		}



		this->curr_dest_x = this->my_path.arr[curr_dest_num]->x;
		this->curr_dest_y = this->my_path.arr[curr_dest_num]->y;




		x += (speed/(abs(curr_dest_x - x)+abs(curr_dest_y - y)))*(curr_dest_x - x);
		y += (speed/(abs(curr_dest_x - x)+abs(curr_dest_y - y)))*(curr_dest_y - y);

		if (this->soldiers < 1) {this->alive = false;}

		if (this->alive and ((abs(curr_dest_x - x)+abs(curr_dest_y - y))<=10)){
			if (this->curr_dest_num == this->total_dest_num-1){
				this->collision(shield_building);
			}else{
				this->x = this->curr_dest_x;
				this->y = this->curr_dest_y;
				this->curr_dest_num+=1;
			}
		}



		if (!alive){
			// remove from list of soldier packets
			this->prev->next = this->next;

			if (this->next!=NULL){
			this->next->prev = this->prev;}

			// set things like pointers, object names to null, basically free memory
			this->next = NULL;
			this->prev = NULL;
			this->dest = NULL;
			delete this;
		}
	}

	void render(float curr_screen_x, float curr_screen_y){
		// rendering to screen
		SDL_Rect fillRect = { this->x-5-curr_screen_x, this->y-5-curr_screen_y, 10, 10 };
        if (loyalty=="Red"){
        	SDL_SetRenderDrawColor( gRenderer, 255, 0, 0, 255 );
        }else if (loyalty == "Blue"){
        	SDL_SetRenderDrawColor( gRenderer, 0, 0, 255, 255 );
        }else{
        	SDL_SetRenderDrawColor( gRenderer, 0, 255, 0, 255 );
        }
        SDL_RenderFillRect( gRenderer, &fillRect );


        //Render text
        SDL_Color textColor = { 255, 255, 255 };
        if( !loadFromRenderedText(to_string(soldiers), textColor, gflappy)) {
            std::cout<<"Failed to render text texture in planet!"<<std::endl;
            error_occ = true;
        }
    
        SDL_Rect titl_pos = { x-5-curr_screen_x, y-5-curr_screen_y, 10*SCALING_FACTOR_X, 10*SCALING_FACTOR_Y  };
        // Text on screen
        SDL_RenderCopy( gRenderer, gTextTexture, NULL, &titl_pos );
	}


	void reset(){

		this->alive = false;
		this->prev->next = this->next;

		if (this->next!=NULL){
		this->next->prev = this->prev;}

		// set things like pointers, object names to null, basically free memory
		this->next = NULL;
		this->prev = NULL;
		this->dest = NULL;
		delete this;
	}

};
