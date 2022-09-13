#define MASK_LENGTH 	(5)

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

int raw_array[MASK_LENGTH] = {0,};
int raw_array_index = 0;
float x;
/* Mask 크기만큼 데이터를 평균낸다. */
float movingAverageFilter()
{
    int i = 0;
    int j = 0;
    int sum = 0;

    for (i = 0; i < MASK_LENGTH; i++) {
    	sum += raw_array[i];
    }
    return ((float)sum / MASK_LENGTH);

    
}

/* 새로운 데이터를 array에 넣는다. */
void insertIntoRawArray(int value)
{
    raw_array[raw_array_index] = value;

    raw_array_index++;

    printf("new num = %d \n",value);

    if (raw_array_index >= MASK_LENGTH) {
    	raw_array_index = 0;
    }

    printf("array = ");

    for(int j = 0 ; j < MASK_LENGTH ; j++){
        
        printf("  %d", raw_array[j]);
    }
    printf("\n");
}

int main(void)
{
    srand(time(NULL));	
		/*printf("입력    ");
		scanf("%f",&x);*/

        for( int i = 0 ; i < 15; i++){
        
        x = rand()%10;
        //printf("arrye num : %0.2f \n",x);
		insertIntoRawArray(x);
		printf("movingAverageFilter = %0.2f\n", movingAverageFilter());
        }
	
	
return 0;
}