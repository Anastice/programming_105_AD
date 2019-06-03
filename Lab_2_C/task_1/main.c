#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N;
    double x, leftX = -1, rightX = 1;

    printf("Enter x, N: ");
    if (scanf("%lf %d", &x, &N) != 2) {
        printf("Invalid input\n");
        return -1;
    }

    if (x < leftX || x > rightX) {
        char* fmt = "Incorrect %.4f. Need from [%.4f, %.4f]\n";
        printf(fmt, x, leftX, rightX);
        return -1;
    }

    double a = x*x, S = a;

    for (int n = 0; n <= N; ++n) {
        double q = pow(x,4)/(2*n+3)*(2*n+1);
        a *= q;
        S += a;
    }
    //Calc result
    S = S;
    double y = 1/2 * log10((x*x+1)/(x*x-1));
    printf("S=%.7f\n", S);
    printf("y=%.7f\n", y);
    double eps = fabs(y-S)/fabs(S)*100;
    printf("e=%.2f%%\n", eps);

    return 0;
}
