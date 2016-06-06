#include "control.h"

float runPID(float sp, float y, float u){
	float error;
	
	error = sp - y;
	u = _u_ant + _Kp*(error-_error_ant) + _Ki*error*_Ts;
	if (u > _umax)
		u = _umax;
	if (u < _umin)
		u = _umin;
	_u_ant = u;
	_error_ant = error;
	return u;
}

void setupPID(float Kpr, float Kir, float Kdr, float Tsr){
	_Kp = Kpr;
	_Ki = Kir;
	_Kd = Kdr;
	_Ts = Tsr;
}
