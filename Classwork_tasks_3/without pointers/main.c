#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>

int main(int argc, char *argv[])
{
    float *arr;
    int n=20, i = 0;

    arr = malloc(sizeof(float) * n);

     printf("Enter arr[...]\n");
    while( scanf("%f", &arr[i++]))
    {}
    arr[i-1] = NAN ;
   for (i = 0; !isnan(arr[i]); ++i){
        printf("%f\n", arr[i]);
  }
  return 0;
}
