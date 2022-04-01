#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

 

struct Vector

{

	float x;

	float y;

	float z;

};

 

Vector outervc(Vector a, Vector b) {

	Vector vt;

	vt.x = a.y * b.z - a.z * b.y;

	vt.y = a.z * b.x - a.x * b.z;

	vt.z = a.x * b.y - a.y * b.x;

 

	return vt;

}

 

float innervc(Vector a, Vector b) {

	return a.x * b.x + a.y + b.y + a.z * b.z;

}

 

float magnutude(Vector a, Vector b) {

	return sqrtl(a.x * b.x + a.y * b.y + a.z * b.z);

}

 

int main() {

	Vector v1, v2, v3  ;

	v1.x = 6, v1.y = 1, v1.z = 3;

	v2.x = 1, v2.y = 1, v2.z = 8;

 

	v3 = outervc(v1, v2);

 

	cout <<  "x = " << v3.x << endl << "y = " << v3.y << endl <<  "z = " << v3.z << endl;

	cout << "inner = " << innervc(v1, v2) <<endl;

	cout << "magnutude = " << magnutude(v1, v2) << endl;

 

 

	return 0;

}

 

 
