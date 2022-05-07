class PathPoint{

	public:

		int x;
		int y;
		string identity;

		PathPoint(int a, int b, string name){
			x = a;
			y = b;
			identity = name;
		}
};

class Path{

	public:
		vector<PathPoint*> arr;

		Path(PathPoint* a, PathPoint* b){
			this->arr.push_back(a);
			this->arr.push_back(b);
		}

		Path(vector<PathPoint*> arr2){
			this->arr = arr2;
		}

		// For concatenating two paths if arr1[n-1]==arr2[0]
		Path operator + (Path p1){
			Path temp(this->arr);
			for(int i=1;i<p1.arr.size();i++){
				temp.arr.push_back(p1.arr[i]);
			}
			return temp;
		}

};



PathPoint* A = new PathPoint(498,245,"A");
PathPoint* B = new PathPoint(496,600,"B");
PathPoint* C = new PathPoint(684,309,"C");
PathPoint* D = new PathPoint(735,608,"D");
PathPoint* E = new PathPoint(792,780,"E");
PathPoint* F = new PathPoint(486,891,"F");
PathPoint* G = new PathPoint(298,866,"G");
PathPoint* H = new PathPoint(958,880,"H");
PathPoint* I = new PathPoint(980,615,"I");
PathPoint* J = new PathPoint(973,504,"J");
PathPoint* K = new PathPoint(1133,620,"K");
PathPoint* L = new PathPoint(1383,629,"L");
PathPoint* M = new PathPoint(1669,636,"M");
PathPoint* N = new PathPoint(1594,546,"N");
PathPoint* O = new PathPoint(1514,200,"O");
PathPoint* P = new PathPoint(1995,387,"P");
PathPoint* Q = new PathPoint(1971,644,"Q");
PathPoint* R = new PathPoint(2321,390,"R");
PathPoint* S = new PathPoint(2455,234,"S");
PathPoint* T = new PathPoint(2573,307,"T");
PathPoint* U = new PathPoint(2464,391,"U");
PathPoint* V = new PathPoint(2759,475,"V");
PathPoint* W = new PathPoint(2604,900,"W");
PathPoint* X = new PathPoint(1528,897,"X");

PathPoint* Z1 = new PathPoint(497,302,"1");
PathPoint* Z2 = new PathPoint(700,393,"2");
PathPoint* Z3 = new PathPoint(883,317,"3");
PathPoint* Z4 = new PathPoint(490,767,"4");
PathPoint* Z5 = new PathPoint(487,954,"5");
PathPoint* Z6 = new PathPoint(931,961,"6");
PathPoint* Z7 = new PathPoint(649,772,"7");
PathPoint* Z8 = new PathPoint(751,679,"8");
PathPoint* Z9 = new PathPoint(1383,308,"9");
PathPoint* Z10 = new PathPoint(1739,639,"10");
PathPoint* Z11 = new PathPoint(1857,525,"11");
PathPoint* Z12 = new PathPoint(2106,278,"12");
PathPoint* Z13 = new PathPoint(1975,175,"13");
PathPoint* Z14 = new PathPoint(2575,392,"14");
PathPoint* Z15 = new PathPoint(2757,394,"15");
PathPoint* Z16 = new PathPoint(2761,902,"16");
PathPoint* Z17 = new PathPoint(939,808,"17");




Path A_Z1 = Path(A,Z1);
Path Z1_A = Path(Z1,A);
Path Z1_B = Path(Z1,B);
Path Z1_C = Path(Z1,C);
Path B_Z1 = Path(B,Z1);
Path B_D = Path(B,D);
Path B_Z4 = Path(B,Z4);
Path Z4_B = Path(Z4,B);
Path Z4_Z7 = Path(Z4,Z7);
Path Z4_F = Path(Z4,F);
Path F_Z4 = Path(F,Z4);
Path F_Z5 = Path(F,Z5);
Path F_G = Path(F,G);
Path G_F = Path(G,F);
Path Z5_F = Path(Z5,F);
Path Z5_Z6 = Path(Z5,Z6);
Path C_Z1 = Path(C,Z1);
Path C_Z2 = Path(C,Z2);
Path Z2_C = Path(Z2,C);
Path Z2_Z3 = Path(Z2,Z3);
Path Z2_D = Path(Z2,D);
Path D_Z2 = Path(D,Z2);
Path D_B = Path(D,B);
Path D_Z8 = Path(D,Z8);
Path D_I = Path(D,I);
Path Z8_D = Path(Z8,D);
Path Z8_E = Path(Z8,E);
Path Z8_Z7 = Path(Z8,Z7);
Path E_Z8 = Path(E,Z8);
Path Z7_Z4 = Path(Z7,Z4);
Path Z7_Z8 = Path(Z7,Z8);
Path Z3_Z2 = Path(Z3,Z2);
Path Z3_J = Path(Z3,J);
Path J_Z3 = Path(J,Z3);
Path J_I = Path(J,I);
Path I_J = Path(I,J);
Path I_D = Path(I,D);
Path I_Z17 = Path(I,Z17);
Path I_K = Path(I,K);
Path Z17_I = Path(Z17,I);
Path Z17_H = Path(Z17, H);
Path H_Z17 = Path(H,Z17);
Path H_X = Path(H,X);
Path H_Z6 = Path(H,Z6);
Path Z6_H = Path(Z6,H);
Path Z6_Z5 = Path(Z6,Z5);
Path K_I = Path(K,I);
Path K_L = Path(K,L);
Path L_M = Path(L,M);
Path L_K = Path(L,K);
Path M_N = Path(M,N);
Path M_Z10 = Path(M,Z10);
Path M_L = Path(M,L);
Path N_M = Path(N,M);
Path N_Z9 = Path(N,Z9);
Path Z9_N = Path(Z9,N);
Path Z9_O = Path(Z9,O);
Path X_H = Path(X,H);
Path X_W = Path(X,W);
Path O_Z13 = Path(O,Z13);
Path O_Z9 = Path(O,Z9);
Path Z13_O = Path(Z13,O);
Path Z13_Z12 = Path(Z13,Z12);
Path Z12_Z13 = Path(Z12,Z13);
Path Z12_P = Path(Z12,P);
Path P_Z12 = Path(P,Z12);
Path P_R = Path(P,R);
Path P_Z11 = Path(P,Z11);
Path Z11_P = Path(Z11,P);
Path Z11_Z10 = Path(Z11,Z10);
Path Z11_Q = Path(Z11,Q);
Path Q_Z11 = Path(Q,Z11);
Path Z10_Z11 = Path(Z10,Z11);
Path Z10_M = Path(Z10,M);
Path R_P = Path(R,P);
Path R_U = Path(R,U);
Path U_R = Path(U,R);
Path U_S = Path(U,S);
Path U_Z14 = Path(U,Z14);
Path S_U = Path(S,U);
Path T_Z14 = Path(T,Z14);
Path Z14_T = Path(Z14,T);
Path Z14_U = Path(Z14,U);
Path Z14_Z15 = Path(Z14,Z15);
Path Z15_Z14 = Path(Z15,Z14);
Path Z15_V = Path(Z15,V);
Path V_Z15 = Path(V,Z15);
Path V_Z16 = Path(V,Z16);
Path Z16_V = Path(Z16,V);
Path Z16_W = Path(Z16,W);
Path W_Z16 = Path(W,Z16);
Path W_X = Path(W,X);
