#include <stdio.h>
int Factorial(int n)
{
    int table = 1;
    for (int i = 1; i <= n; i++)
        table *= i;
    return table;
}
int main()
{
    float p, h;
    int n, size;
    printf("Please Input no of terms:");
    scanf("%d", &n);
    size = n;

    float x[n], y[n], table[n][n], val = 1895, result=0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            table[i][j] = 0;
    printf("***Input value for X and f(x)***\n");
    for (int i = 0; i < n; i++)
        scanf("%f%f", &x[i], &y[i]);
    printf("Please input X value :");
    scanf("%f", &val);
    p = (val - x[0]) / (x[1] - x[0]);
    result += y[0];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
            if (i == 0)
                table[i][j] = y[j + 1] - y[j];
            else
                table[i][j] = table[i - 1][j + 1] - table[i - 1][j];
        size--;
    }

    size = n;
    printf("\n*****Table For Newton's Forward Interpolation.**\n");
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (j == 0)
            {
                printf("%0.1f  ", x[i]);
                printf("%0.1f  ", y[i]);
            }
            printf("%0.1f  ", table[j][i]);
        }
        printf("\n");
        size--;
        if (size == 1)
        {
            printf("%0.1f  ", x[n - 1]);
            printf("%0.1f  ", y[n - 1]);
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (i == 0)
            result += p * table[i][0];
        else
        {
            int temp = 1;
            for (int k = i; k >= 0; k--)
                temp *= (p - k);
            result += ((temp * table[i][0]) / (Factorial(i + 1)));
        }
    }

    printf("\nValue at %f is : %0.04f ", val, result);
    return 0;
}