#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>

int main()
{
    int num1 = 0, num2;
    float BPS, byte, total_time, one_time;
    float BPS_select[] = {1200,2400,4800,9600,14400,19200,38400,57600,115200,230400,460800,921600};
    printf("-------------------SELECT_BPS---------------------\n");
    printf("1:1200 2:2400 3:4800 4:9600 5: 14400 6:19200  \n7:38400 8:57600 9:115200 10:230400 11:460800 12:921600\n");
    printf("--------------------------------------------------\n");
    printf("select BPS : ");
    scanf("%d", &num1);
    printf("insert byte : ");
    scanf("%d", &num2);

    BPS = BPS_select[num1-1];
    byte = num2;
    
    total_time = (byte / BPS) *1000;
    one_time = total_time / byte;

    printf("\nselect_BPS = (%d)%0.0f  \n", num1,BPS);
    printf("total time = %f msec \n", total_time);
    printf("one_time = %f msec\n", one_time);

    return 0;
}
