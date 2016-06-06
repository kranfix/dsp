#ifndef __control_H
#define __control_H

#define MODO_MANUAL 0
#define MODO_PID    1
#define MODO_fffbi  2

// Variables
static float _error_ant = 0;
static float _u_ant = 0;
static float _Ki, _Kd, _Kp;
static float _umin = 0, _umax = 100;
static float _Ts;

// Feedback + feedforward + integrador
typedef struct SS_HANDLE_t{
	// Orden del sistema
	int n;
	// Modelo del Observador
	float * A;
	float * B;
  float * X;
	float * K_fb;
	float * L;
	float u_fb;
	// Modelo de referencia
	float * Am;
	float * Bm;
	float * Xm;
	float * K_ff;
	float u_ff;
	// Integrador
	float KI;
	float umin;
	float umax;
	float Xint;
	float u; // Control variable
	// Buffer temporal
	float * Z;
} SS_HANDLE_t;

void control_ss_fb(SS_HANDLE_t * ss);
void control_ss_ff(SS_HANDLE_t * ss, float r);
void control_ss_int(SS_HANDLE_t * ss, float r, float y);
void control_ss_obs(SS_HANDLE_t * ss, float y);

// PID
float runPID(float sp, float y, float u);
void setupPID(float Ki, float Kd, float Kp, float Ts);

// Adaptativo


#endif // ___control_H