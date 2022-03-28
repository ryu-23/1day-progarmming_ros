#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <string>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	float num1 = atoi(argv[1]);
	float num2 = atoi(argv[2]);
	printf("%f + %f = %0.2f\n", num1,num2,num1+num2); // atof = s -> f 
	printf("%f - %f = %0.2f\n", num1,num2,num1-num2);
	printf("%f * %f = %0.2f\n", num1,num2,num1*num2);
	printf("%f / %f = %0.2f\n", num1,num2,num1/num2);
	
	printf("argv [0] = %s \n" ,argv[0]);
	printf("argv [1] = %s \n" ,argv[1]);
	printf("argv [2] = %s \n" ,argv[2]);
	printf("argc = %d \n" ,argc);
	
	return 0;
}

