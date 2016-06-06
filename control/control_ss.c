#include "control.h"

void control_ss_fb(SS_HANDLE_t * ss){
	ss->u_fb = 0;
	for(int i = 0; i < ss->n; i++){
		ss->u_fb += ss->K_fb[i] * ss->X[i];
	}
}

void control_ss_ff(SS_HANDLE_t * ss, float r){
	int N = 0;
	for(int i = 0; i < ss->n; i++){
		ss->Z[i] = ss->Bm[i] * r;
		for(int j = 0; j < ss->n; j++){
			ss->Z[i] += ss->Am[N+j] * ss->Xm[j];
		}
		N += ss->n;
	}
	float * temp = ss->Z;
	ss->Z = ss->Xm;
	ss->Xm = temp;
	
	// Calculo de u_ff
	ss->u_ff = 0;
	for(int i = 0; i < ss->n; i++){
		ss->u_ff += ss->K_ff[i] * ss->Xm[i];
	}
}

void control_ss_int(SS_HANDLE_t * ss, float r, float y){
	ss->Xint += ss->KI*(r-y);
	float u = ss->u_ff - ss->u_fb;
	ss->u =  u + ss->Xint ;
	
	if(ss->u > ss->umax){
		ss->u = ss->umax;
		ss->Xint = ss->umax - u;
	}
	if(ss->u < ss->umin){
		ss->u = ss->umin;
		ss->Xint = ss->umin - u;
	}
}

void control_ss_obs(SS_HANDLE_t * ss, float y){
	int N = 0;
	for(int i = 0; i < ss->n; i++){
		ss->Z[i] = ss->L[i] * (y - ss->X[0]);
		ss->Z[i] += ss->B[i] * ss->u;
		for(int j = 0; j < ss->n; j++){
			ss->Z[i] += ss->Am[N+j] * ss->X[j];
		}
		N += ss->n;
	}
	float * temp = ss->Z;
	ss->Z = ss->X;
	ss->X = temp;
}