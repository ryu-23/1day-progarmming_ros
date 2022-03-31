#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#define DATA 4

 

double x[DATA], y[DATA];

double x_avg, y_avg, x_sum, y_sum;

double denominator, numerator, a, b;

int i;

 

 

void calculate(void);

 

int main(void)

{

	int size, i;
	
	printf("insert x_num : ");
	scanf("%d", &size);

	double* x = (double*)malloc(sizeof(double) * size);

 

	for (i = 0; i < size; i++)

		scanf("%lf", &x[i]);

	size = 0;
	
	printf("insert y_num : ");
	scanf("%d", &size);

	double* y = (double*)malloc(sizeof(double) * size);

 

	for (i = 0; i < size; i++)

		scanf("%lf", &y[i]);

 


	for (i = 0; i < size; i++)

	{

		x_sum += x[i];

		y_sum += y[i];

	}

 

	printf("x_sum = %0.2lf \n", x_sum);

	printf("y_sum = %0.2lf \n", y_sum);

 

	x_avg = x_sum / size;

	y_avg = y_sum / size;

 

	printf("x_avg = %0.2lf \n", x_avg);

	printf("y_avg = %0.2lf \n", y_avg);

 

 

	for (i = 0; i < size; i++)

	{

		numerator += (x[i] - x_avg) * (y[i] - y_avg); 

		denominator += pow((x[i] - x_avg), 2);    

	}

 

	printf("numerator = %0.2lf \n", numerator);

	printf("denominator = %0.2lf \n", denominator);

 

 

	a = numerator / denominator;

	b = y_avg - (x_avg * a);

 

	printf("y = %0.2lf x + %0.2lf \n\n", a, b);

 

	free(x);

	free(y);

	return 0;

 

}
