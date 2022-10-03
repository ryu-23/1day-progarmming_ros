#include <stdio.h>
#include<math.h>

float twobytwo_invers(float a2[][2]);
float twobytwo_input_print(float a[][2], int size);
float threebythree_invers(float a3[][3]);
float threebythree_input_print(float a[][3], int size);
float fourbyfour_invers(float a4[][4]);
float fourbyfour_input_print(float a[][4], int size);


float data = 0.0f;

float invers_A2[2][2] = { 0, };
float mat2x2[2][2] = { 0, };
float invers_A3[3][3] = { 0, };
float A3[3][3] = { 0, };
float invers_A4[4][4] = { 0, };
float A4[4][4] = { 0, };

int main(void)
{
	int size;

	printf("행렬 크기를 입력해주세요: ");
	scanf("%d", &size);

	if (size == 2)
	{
		twobytwo_input_print(mat2x2, size);
		twobytwo_invers(mat2x2);
	}
	else if (size == 3)
	{
		threebythree_input_print(A3, size);
		threebythree_invers(A3);
	}
	else if (size == 4)
	{
		fourbyfour_input_print(A4, size);
		fourbyfour_invers(A4);
	}

	return 0;
}
float twobytwo_input_print(float a[][2], int size)
{
	printf("2X2 행렬 입력\n");

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			printf("[%d][%d] 입력 \n", i, j);
			scanf("%f", &data);
			mat2x2[i][j] = data;
		}

	printf("2x2 행렬 출력\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%5f", mat2x2[i][j]);
		}
		printf("\n");
	}

	return 0;
}

float twobytwo_invers(float a2[][2])
{
	float det;
	int x = 0, y = 0;

	det = mat2x2[0][0] * mat2x2[1][1] - mat2x2[0][1] * mat2x2[1][0];
	if (det == 0.0)
	{
		printf("역행렬이 존재하지 않습니다.\n");
		return 1;
	}

	invers_A2[0][0] = mat2x2[1][1] / det;
	invers_A2[0][1] = -mat2x2[0][1] / det;
	invers_A2[1][0] = -mat2x2[1][0] / det;
	invers_A2[1][1] = mat2x2[0][0] / det;


	printf("\n 2x2 역행렬 출력 : \n\n");
	for (int i = 0; i < 2; i++)
	{
		printf("| ");
		for (int j = 0; j < 2; j++)
		{
			printf("%.2f ", invers_A2[i][j]);
		}
		printf(" |\n");
	}

	return 0;
}



float threebythree_input_print(float a[][3], int size)
{
	printf("3X3 행렬 입력\n");

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			printf("[%d][%d] 입력 \n", i, j);
			scanf("%f", &data);
			A3[i][j] = data;
		}

	printf("A행렬 출력\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%0.5f", A3[i][j]);
		}
		printf("\n");
	}

	return 0;
}

float threebythree_invers(float a3[][3])
{

	float detera4inant = 0;

	detera4inant = a3[0][0] * a3[1][1] * a3[2][2] - a3[0][0] * a3[1][2] * a3[2][1]

		+ a3[0][1] * a3[1][2] * a3[2][0] - a3[0][1] * a3[1][0] * a3[2][2]

		+ a3[0][2] * a3[1][0] * a3[2][1] - a3[0][2] * a3[1][1] * a3[2][0];

	//printf("\n\ndetera4inant=%g\n", detera4inant);

	if (detera4inant == 0.0) {

		printf("\n역행렬이 존재하지 않습니다.\n");

		return 0;

	}

	for (int i = 0; i < 3; i += 1) {
		for (int j = 0; j < 3; j += 1) {
			invers_A3[i][j] = 1.0 / detera4inant *
				(a3[(i + 1) % 3][(j + 1) % 3] * a3[(i + 2) % 3][(j + 2) % 3] -
					a3[(i + 1) % 3][(j + 2) % 3] * a3[(i + 2) % 3][(j + 1) % 3]);
		}

	}

	printf("\n 3x3 역행렬 출력 : \n\n");
	for (int i = 0; i < 3; i += 1) {
		for (int j = 0; j < 3; j += 1) {
			printf("%10.4f\t", invers_A3[i][j]);
		}
		printf("\n");
	}

	return 0;
}

float fourbyfour_input_print(float a[][4], int size)
{
	printf("4X4 행렬 입력\n");

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			printf("[%d][%d] 입력 \n", i, j);
			scanf("%f", &data);
			A4[i][j] = data;
		}

	printf("A행렬 출력\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%5f", A4[i][j]);
		}
		printf("\n");
	}

	return 0;
}

float fourbyfour_invers(float a4[][4])
{
	float det = 0;

	invers_A4[0][0] =
		a4[1][1] * a4[2][2] * a4[3][3]
		- a4[1][1] * a4[2][3] * a4[3][2]
		- a4[2][1] * a4[1][2] * a4[3][3]
		+ a4[2][1] * a4[1][3] * a4[3][2]
		+ a4[3][1] * a4[1][2] * a4[2][3]
		- a4[3][1] * a4[1][3] * a4[2][2];

	invers_A4[0][1] =
		-a4[0][1] * a4[2][2] * a4[3][3]
		+ a4[0][1] * a4[2][3] * a4[3][2]
		+ a4[2][1] * a4[0][2] * a4[3][3]
		- a4[2][1] * a4[0][3] * a4[3][2]
		- a4[3][1] * a4[0][2] * a4[2][3]
		+ a4[3][1] * a4[0][3] * a4[2][2];

	invers_A4[0][2] =
		a4[0][1] * a4[1][2] * a4[3][3]
		- a4[0][1] * a4[1][3] * a4[3][2]
		- a4[1][1] * a4[0][2] * a4[3][3]
		+ a4[1][1] * a4[0][3] * a4[3][2]
		+ a4[3][1] * a4[0][2] * a4[1][3]
		- a4[3][1] * a4[0][3] * a4[1][2];

	invers_A4[0][3] =
		-a4[0][1] * a4[1][2] * a4[2][3]
		+ a4[0][1] * a4[1][3] * a4[2][2]
		+ a4[1][1] * a4[0][2] * a4[2][3]
		- a4[1][1] * a4[0][3] * a4[2][2]
		- a4[2][1] * a4[0][2] * a4[1][3]
		+ a4[2][1] * a4[0][3] * a4[1][2];

	invers_A4[1][0] =
		-a4[1][0] * a4[2][2] * a4[3][3]
		+ a4[1][0] * a4[2][3] * a4[3][2]
		+ a4[2][0] * a4[1][2] * a4[3][3]
		- a4[2][0] * a4[1][3] * a4[3][2]
		- a4[3][0] * a4[1][2] * a4[2][3]
		+ a4[3][0] * a4[1][3] * a4[2][2];

	invers_A4[1][1] =
		a4[0][0] * a4[2][2] * a4[3][3]
		- a4[0][0] * a4[2][3] * a4[3][2]
		- a4[2][0] * a4[0][2] * a4[3][3]
		+ a4[2][0] * a4[0][3] * a4[3][2]
		+ a4[3][0] * a4[0][2] * a4[2][3]
		- a4[3][0] * a4[0][3] * a4[2][2];

	invers_A4[1][2] =
		-a4[0][0] * a4[1][2] * a4[3][3]
		+ a4[0][0] * a4[1][3] * a4[3][2]
		+ a4[1][0] * a4[0][2] * a4[3][3]
		- a4[1][0] * a4[0][3] * a4[3][2]
		- a4[3][0] * a4[0][2] * a4[1][3]
		+ a4[3][0] * a4[0][3] * a4[1][2];

	invers_A4[1][3] =
		a4[0][0] * a4[1][2] * a4[2][3]
		- a4[0][0] * a4[1][3] * a4[2][2]
		- a4[1][0] * a4[0][2] * a4[2][3]
		+ a4[1][0] * a4[0][3] * a4[2][2]
		+ a4[2][0] * a4[0][2] * a4[1][3]
		- a4[2][0] * a4[0][3] * a4[1][2];

	invers_A4[2][0] =
		a4[1][0] * a4[2][1] * a4[3][3]
		- a4[1][0] * a4[2][3] * a4[3][1]
		- a4[2][0] * a4[1][1] * a4[3][3]
		+ a4[2][0] * a4[1][3] * a4[3][1]
		+ a4[3][0] * a4[1][1] * a4[2][3]
		- a4[3][0] * a4[1][3] * a4[2][1];

	invers_A4[2][1] =
		-a4[0][0] * a4[2][1] * a4[3][3]
		+ a4[0][0] * a4[2][3] * a4[3][1]
		+ a4[2][0] * a4[0][1] * a4[3][3]
		- a4[2][0] * a4[0][3] * a4[3][1]
		- a4[3][0] * a4[0][1] * a4[2][3]
		+ a4[3][0] * a4[0][3] * a4[2][1];

	invers_A4[2][2] =
		a4[0][0] * a4[1][1] * a4[3][3]
		- a4[0][0] * a4[1][3] * a4[3][1]
		- a4[1][0] * a4[0][1] * a4[3][3]
		+ a4[1][0] * a4[0][3] * a4[3][1]
		+ a4[3][0] * a4[0][1] * a4[1][3]
		- a4[3][0] * a4[0][3] * a4[1][1];

	invers_A4[2][3] =
		-a4[0][0] * a4[1][1] * a4[2][3]
		+ a4[0][0] * a4[1][3] * a4[2][1]
		+ a4[1][0] * a4[0][1] * a4[2][3]
		- a4[1][0] * a4[0][3] * a4[2][1]
		- a4[2][0] * a4[0][1] * a4[1][3]
		+ a4[2][0] * a4[0][3] * a4[1][1];

	invers_A4[3][0] =
		-a4[1][0] * a4[2][1] * a4[3][2]
		+ a4[1][0] * a4[2][2] * a4[3][1]
		+ a4[2][0] * a4[1][1] * a4[3][2]
		- a4[2][0] * a4[1][2] * a4[3][1]
		- a4[3][0] * a4[1][1] * a4[2][2]
		+ a4[3][0] * a4[1][2] * a4[2][1];

	invers_A4[3][1] =
		a4[0][0] * a4[2][1] * a4[3][2]
		- a4[0][0] * a4[2][2] * a4[3][1]
		- a4[2][0] * a4[0][1] * a4[3][2]
		+ a4[2][0] * a4[0][2] * a4[3][1]
		+ a4[3][0] * a4[0][1] * a4[2][2]
		- a4[3][0] * a4[0][2] * a4[2][1];

	invers_A4[3][2] =
		-a4[0][0] * a4[1][1] * a4[3][2]
		+ a4[0][0] * a4[1][2] * a4[3][1]
		+ a4[1][0] * a4[0][1] * a4[3][2]
		- a4[1][0] * a4[0][2] * a4[3][1]
		- a4[3][0] * a4[0][1] * a4[1][2]
		+ a4[3][0] * a4[0][2] * a4[1][1];

	invers_A4[3][3] =
		a4[0][0] * a4[1][1] * a4[2][2]
		- a4[0][0] * a4[1][2] * a4[2][1]
		- a4[1][0] * a4[0][1] * a4[2][2]
		+ a4[1][0] * a4[0][2] * a4[2][1]
		+ a4[2][0] * a4[0][1] * a4[1][2]
		- a4[2][0] * a4[0][2] * a4[1][1];

	det = a4[0][0] * invers_A4[0][0] + a4[0][1] * invers_A4[1][0] + a4[0][2] * invers_A4[2][0] + a4[0][3] * invers_A4[3][0];

	if (det == 0)

		return 0;



	det = 1.0 / det;



	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			A4[i][j] = invers_A4[i][j] * det;


	printf("\n 4x4 역행렬 출력 : \n\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%10.4f", A4[i][j]);
		}
		printf("\n");
	}
	return 0;
}