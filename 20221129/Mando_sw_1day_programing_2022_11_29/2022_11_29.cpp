#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>

int main()
{
    int Max_rpm = 3000;
    int num1, num2;
    float rpm, pulse, hz, total_pulse ,min_period;
    printf("insert rpm : ");
    scanf("%d", &num1);
    printf("insert pulse : ");
    scanf("%d", &num2);

    
    rpm = num1;
    pulse = num2;
    rpm = rpm >= Max_rpm ? Max_rpm : rpm;
        hz = rpm * (1.0 / 60.0);
        total_pulse = hz * pulse;
        min_period = 1 / total_pulse * 1000;

        printf("hz = %0.2f Hz \n", hz);
        printf("min_period  = %0.2f msec \n", min_period);
    
    
    return 0;
}
