#include <stdio.h>
#include <math.h>
/*
*Year       Population(y)       Dy      D2y     D3y     D4y
*1891           46              20      -5      2       -3
*1901           66              15      -3      -1
*1911           81              12      -4
*1921           93              8
*1931           101


Find for x = 1926 (BACKWARD)
*/
int main(){
    int n;
    printf("Enter no. of records:: "); scanf("%d", &n);

    int table[n][n + 1];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n + 1; j++){
            table[i][j] = 0;
        }
    }

    int year = 0, population = 0;
    for(int i = 0; i < n; i++){
        printf("RECORD %d::\n", i + 1);
        printf("Year:"); scanf("%d", &year);
        printf("Population:"); scanf("%d", &population);

        table[i][0] = year;
        table[i][1] = population;

        printf("\n");
    }
    for(int j = 1; j < n; j++){
        for(int i = j; i < n; i++){
            table[i][j + 1] = table[i][j] - table[i - 1][j];
        }
    }
    /*
    * Check the table using::
    *for(int i = 0; i < n; i++){
    *    for(int j = 0; j < n + 1; j++){
    *        printf("%d ", table[i][j]);
    *    }
    *
    *    printf("\n");
    *}
    */

    int x;
    printf("\nEnter the Population:: "); scanf("%d", &x);
    int h = table[1][0] - table[0][0];
    //printf("%d\n", h);
    float p = (x - table[n - 1][0])/(float)h;
    //printf("%d\n", p);
    float y = 0;
    int fact = 1;
    float pp = 1.0;

    for(int j = 1; j < n + 1; j++){
        y += (float)pp * table[n - 1][j]/fact;
        pp *= p++;
        //printf("%d\n", pp);
        fact *= j;
    }
    printf("Population = %0.3f", y);
}



