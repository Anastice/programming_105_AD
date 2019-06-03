#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>

int main(int argc, char *argv[])
{
    int i = 0, n=20;
    double *arr ;

    arr = malloc(sizeof(double) * n);

    double *p = arr ;
     printf("Enter arr[...]\n");
    while( scanf("%lf", p++))
    {}

    *(p-1) = NAN;

   for (p=arr;!isnan(*p);++p){
        printf("%f\n", *p);
  }
  return 0;
}
