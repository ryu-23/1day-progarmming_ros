#define MASK_LENGTH 	5
#define alpha      0.2 // 0<alpha<1

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

int raw_array[MASK_LENGTH] = { 0, };
int raw_array_index = 0;
float x;
float prevX = 0;


/* pass filter */

/* pass filter */
float lowpassfilter() {

    float x_LPF = alpha * prevX + (1 - alpha) * x;
    printf("%0.2f = %0.2f * %0.2f + (1- %0.2f) * x %0.2f \n", x_LPF, alpha, prevX, alpha, x);
    prevX = x_LPF;


    return x_LPF;


}

/* inset new array */
void insertIntoRawArray(int value)
{
    raw_array[raw_array_index] = value;

    raw_array_index++;

    printf("new num = %d \n", value);

    if (raw_array_index >= MASK_LENGTH) {
        raw_array_index = 0;
    }

}

int main(void)
{
    printf("x_lPF = alpha * prevX + (1- alpha) * x \n");
    srand(time(NULL));
    for (int i = 0; i < 15; i++) {
        x = rand() % 10;
        insertIntoRawArray(x);
        
        printf("lowpassfilter = %0.2f\n", lowpassfilter());
        

    }


    return 0;
}