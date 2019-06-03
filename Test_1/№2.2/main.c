#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f1(double);
double f2(double, double);

int main()
{
    double a = -3, b = 5, h = 0.1;

    printf("*************** Part 1 ***************\n");

    printf("x:\t");
    for (double x = a; x <= b; x += h) {
        char c = x + h < b ? '\t' : '\n';
        printf("%.3f%c", x, c);
    }

    printf("y:\t");
    for (double x = a; x <= b; x += h) {
        char c = x + h < b ? '\t' : '\n';
        printf("%.3f%c", f1(x), c);
    }

    printf("**************************************\n");

    printf("*************** Part 2 ***************\n");

    double a1=-1, b1 = 3, h1 = 0.2;
    double c1=-2, d1 = 2, h2 = 0.1;
    printf("y\\x\t");
    for (double x = a1; x <= b1; x += h1) {
        char c = x + h1 < b1 ? '\t' : '\n';
        printf("%.3f%c", x, c);
    }

    for (double y = c1; y <= d1; y += h2) {
        printf("%.3f\t", y);
        for (double x = a1; x <= b1; x += h1) {
            char c = x + h1 < b1 ? '\t' : '\n';
            printf("%.3f%c", f2(x, y), c);
        }
    }

    printf("**************************************\n");
    return 0;
}

double f1(double x) {
    if (x <= -1.0) {
        return -2*pow(x,3)+4*pow(x,2)+x;
    } else {
        if (x > -1.0 && x < 3.0) {
            return 5*pow(x,3)+x*x-1;
        } else {
            return pow(x,3)+2*x-3 ;
        }
    }
}

double f2(double x, double y) {
    return abs(pow(y,3)-2*x)/(x+2);
}
