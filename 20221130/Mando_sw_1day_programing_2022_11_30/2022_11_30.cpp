#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>

int main()
{
    int num1, num2;
    float BPS, byte, total_time, one_time;
    printf("insert BPS : ");
    scanf("%d", &num1);
    printf("insert byte : ");
    scanf("%d", &num2);

    BPS = num1;
    byte = num2;
    
    total_time = (byte / BPS) *1000;
    one_time = total_time / byte;

    printf("total time = %f msec \n", total_time);
    printf("one_time = %f msec", one_time);

    //T = A/S A = 8byte S = 19200 B/s
    //  8B/19200B/s = T

    return 0;
}