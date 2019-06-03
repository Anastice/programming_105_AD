#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double a,b,x,d,u ;
    printf ("Enter a,b,x:");
    scanf("%lf %lf %lf", &a, &b, &x) ;

    d = x+1 ;   //значение под корнем
    if (d<0){
            printf("cannot be counted") ;
            return -1;
    }

    u = b- sqrt(d); //знаменатель
    if (u == 0){
            printf("cannot be counted") ;
            return -1;
    }

    double res = (1 - tan(a*x))/u ;

    printf("Result is %.5f\n", res );
    return 0;

}
