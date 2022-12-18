//newton raphson
#include<stdio.h>
#include<math.h>
#define e 0.000001
double f_(double x)
{
	return 3*x*x-4;
}
double f(double x)
{
    return x*x*x-4*x-9;
}
void newton_raphson(double x)
{
    double c=f(x)/f_(x);
	while(fabs(c)>=e)
    {
        c=f(x)/f_(x);
        x=x-c;
        printf("\n roots=%lf ",x);
    }
    printf("\nfinal root=%lf",x);
}
int main()
{
	double x;
	printf("enter x =");
	scanf("%lf",&x);
	newton_raphson(x);
    return 0;
}

