#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define len  200

float acceleration(float v1, float x1) {
	float c = 10.0;
	float k = 1000.0;
	float m = 1.0;
	float a = -(c * v1 + k * x1) / m;

	return a;
}

void runge_kutta() {
	float dt = 0.01;
	float t[len] = {0.0};
	float v[len] = {0.0};
	float x[len] = {0.0};
	
	x[0] = 0.1; //스프링이 늘어난 길이
	
	for (int i = 0; i < len-1 ; i++) {

		float v1 = acceleration(v[i], x[i]) * dt;
		float x1 = v[i] * dt;
		
		float v2 = acceleration(v[i]+v1/2, x[i] + x1/ 2)* dt;
		float x2 = (v[i]+v1/2) * dt;
		
		float v3 = acceleration(v[i] + v2/ 2, x[i] + x2 / 2) * dt;
		float x3 = (v[i] + v2 / 2) * dt; 
		
		float v4 = acceleration(v[i]+v3, x[i]+x3) * dt;
		float x4 = (v[i]+v3) * dt;

		t[i+1] = t[i] + dt;
		v[i+1] = v[i] + (v1 + 2*v2 + 2*v3 + v4)/6;
		x[i+1] = x[i] + (x1 + 2*x2 + 2*x3 + x4)/6;

		//printf("t = %f \n", t[i+1]);
		printf("v along the time %0.2f = %f \n", t[i + 1],v[i+1]);
		printf("x along the time %0.2f = %f \n", t[i + 1],x[i+1]);
		

	}

}


int main(void) {

	//cceleration(num_v, num_x);
	runge_kutta();

}