#include <stdio.h>
#include <math.h>

float data = 0.0f;
FILE* fp;
FILE* fp2;

int main(void)
{
    double  a, b, c;
    double t = 0;
    double y_t = 0;
    double frequency_n = 0, zeta = 0, frequency_d = 0;
    double num1 = 0, num2 = 0;
    fp = fopen("Contral_Time.txt", "w");
    fp2 = fopen("calculated value.txt", "w");

    if (fp == NULL)
    {
        printf("fp 파일 열기 실패\n");
    }
    else
    {
        printf("fp 파일 열기 성공\n");
    }

    if (fp == NULL)
    {
        printf("fp2 파일 열기 실패\n");
    }
    else
    {
        printf("fp2 파일 열기 성공\n");
    }

    /*printf("이차방정식 ax^2+bx+c=0\n");
    printf("a: ");
    scanf_s("%lf", &a);

    printf("b: ");
    scanf_s("%lf", &b);

    printf("c: ");
    scanf_s("%lf", &c);
    */
    //frequency_n = sqrt(c);
    //zeta = b / (2 * frequency_n);
    printf("zeta: ");
    scanf_s("%lf", &num1);
    zeta = num1;

    printf("frequency_n: ");
    scanf_s("%lf", &num2);
    frequency_n = num2;



    frequency_d = frequency_n * sqrt(1 - zeta * zeta);

    for (t = 0.0; t < 5.0; t += 0.001)
    {
        if (zeta > 0 && zeta < 1)
        {
            y_t = 1 - (exp(-zeta * frequency_n * t) / sqrt(1 - zeta * zeta)) * sin(frequency_d * t + atan(sqrt(1 - zeta * zeta) / zeta));
            fprintf(fp, "%f \n", t);
            fprintf(fp2, "%.8f\n", y_t);
            printf("%.8f \n", y_t);
        }
        // zeta = 0
        else if (zeta == 1)
        {
            y_t = 1 - exp(-frequency_n * t) - frequency_n * t * exp(-frequency_n * t);
            fprintf(fp, "%f \n", t);
            fprintf(fp2, "%.8f\n", y_t);
            printf("%.8f \n", y_t);
        }
        // zeta > 1
        else if (zeta > 1)
        {
            y_t = 1 - (0.5) * (zeta / sqrt(zeta * zeta - 1) + 1) * exp(-frequency_n * (zeta - sqrt(zeta * zeta - 1)) * t) + (0.5) * (zeta / sqrt(zeta * zeta - 1) - 1) * exp(-frequency_n * (zeta + sqrt(zeta * zeta - 1)) * t);
            fprintf(fp, "%f \n", t);
            fprintf(fp2, "%.8f\n", y_t);
            printf("%.8f \n", y_t);
        }
        else if (zeta == 0)
        {
            y_t = 1.0 - cos(frequency_n * t);
            fprintf(fp, "%f \n", t);
            fprintf(fp2, "%.8f\n", y_t);
            printf("%.8f \n", y_t);
        }
        else
        {
            printf("시스템이 불안정하게 된다.");
        }
    }

    fclose(fp);

    printf("zeta = %f", zeta);


    return 0;
}