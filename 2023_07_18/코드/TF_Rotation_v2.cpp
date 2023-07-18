// TF_Rotation.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "math.h"

#define RAD2DEG(x)   x*180/M_PI
#define DEG2RAD(x)   x/180*M_PI

double transformed_y = 0;
double transformed_x = 0;
double transformed_x_inverse = 0;
double transformed_y_inverse = 0;

typedef struct 
{
	double x;
	double y;
	double theta;
} Pose2D;

typedef struct
{
	double x;
	double y;	
} Point2D;


Pose2D    base_link_origin;
Point2D   base_link_Point2D, base_link_map_Point2D, transformed, transformed_inverse, transformed2, transformed_inverse2;

double angle_degree;
double angle_radian;


double Rotation_matrix_inverse[2][2];
double Rotation_matrix[2][2];

void set_rotation_matrix(double m_angle_degree)
{
	angle_radian = DEG2RAD(m_angle_degree);	
	Rotation_matrix[0][0] = cos(angle_radian); Rotation_matrix[0][1] = -sin(angle_radian);
	Rotation_matrix[1][0] = sin(angle_radian); Rotation_matrix[1][1] = cos(angle_radian);

}

void set_rotation_matrix_inverse(double m_angle_degree)
{
	angle_radian = DEG2RAD(m_angle_degree);
	Rotation_matrix_inverse[0][0] = cos(angle_radian);  Rotation_matrix_inverse[0][1] = sin(angle_radian);
	Rotation_matrix_inverse[1][0] = -sin(angle_radian); Rotation_matrix_inverse[1][1] = cos(angle_radian);
}


void TF_base_link_base_link_map(Point2D* base_link_Point2D, Point2D* base_link_map_point2d, Pose2D base_link_origin) // Base_Link -> Base_Link_Map

{

	set_rotation_matrix_inverse(base_link_origin.theta);
	transformed.x = (Rotation_matrix_inverse[0][0] * base_link_Point2D->x) + (Rotation_matrix_inverse[0][1] * base_link_Point2D->y);
	transformed.y = (Rotation_matrix_inverse[1][0] * base_link_Point2D->x) + (Rotation_matrix_inverse[1][1] * base_link_Point2D->y);

	printf("========================================================================\n");
	printf("Transformed Point Matrix: %6.3lf  %6.3lf\n", base_link_Point2D->x, base_link_Point2D->y);
	printf("Base_Link -> Base_Link_Map: %6.3lf  %6.3lf\n", transformed.x, transformed.y);



	
}

void TF_base_link_map_map(Point2D* transformed, Pose2D base_link_origin)                                             //Base_Link_Map -> Map

{
	TF_base_link_base_link_map(&base_link_Point2D, &base_link_map_Point2D, base_link_origin);
	transformed2.x = transformed->x + base_link_origin.x;
	transformed2.y = transformed->y + base_link_origin.y;

	printf("========================================================================\n");
	printf("Transformed Point Matrix: %6.3lf  %6.3lf\n", transformed->x, transformed->y);
	printf("Base_Link_Map -> Map: %6.3lf  %6.3lf\n", transformed2.x, transformed2.y);

}

void TF_map_base_link_map(Point2D* transformed2, Pose2D base_link_origin)                                     //Map -> Base_Link_Map

{
	transformed_inverse2.x = transformed2->x - base_link_origin.x;
	transformed_inverse2.y = transformed2->y - base_link_origin.y;

	printf("========================================================================\n");
	printf("Transformed Point Matrix: %6.3lf  %6.3lf\n", transformed2->x, transformed2->y);
	printf("Map->Base_Link_Map: % 6.3lf % 6.3lf\n", transformed_inverse2.x, transformed_inverse2.y);

}

void TF_base_link_map_base_link(Point2D* transformed_inverse2, Point2D* base_link_map_point2d, Pose2D base_link_origin) //Base_Link_Map -> Base_Link 

{
	TF_map_base_link_map(&transformed2, base_link_origin);
	set_rotation_matrix(base_link_origin.theta);
	transformed_inverse.x = (Rotation_matrix[0][0] * transformed_inverse2->x) + (Rotation_matrix[0][1] * transformed_inverse2->y);
	transformed_inverse.y = (Rotation_matrix[1][0] * transformed_inverse2->x) + (Rotation_matrix[1][1] * transformed_inverse2->y);

	printf("========================================================================\n");
	printf("Transformed Point Matrix: %6.3lf  %6.3lf\n", transformed_inverse2->x, transformed_inverse2->y);
	printf("Base_Link_Map -> Base_Link : %6.3lf  %6.3lf\n", transformed_inverse.x, transformed_inverse.y);
}




int _tmain(int argc, _TCHAR* argv[])
{
	//angle_degree = 90;
	//angle_radian = DEG2RAD(angle_degree);
	

	base_link_origin.x = 5.0;
	base_link_origin.y = 3.0;
	base_link_origin.theta = -90;	

	base_link_Point2D.x = 1.0;//-0.707;
	base_link_Point2D.y = -1.0;//2.121;

	TF_base_link_map_map(&transformed, base_link_origin);
	TF_base_link_map_base_link(&transformed_inverse2, &base_link_map_Point2D, base_link_origin);


	return 0;
}

