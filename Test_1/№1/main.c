#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double a,b,x,d;
    printf ("Enter a,b,x:");
    scanf("%lf %lf %lf", &a, &b, &x) ;

    d = cbrt(6-x);
    if (d<0){
            printf("cannot be counted") ;
            return -1;
    }


    double res = pow(x,a) - pow(b , x* log(d)) ;

    printf("Result is %.5f\n", res );
    return 0;

}
