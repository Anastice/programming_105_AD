#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void first_task(void);
void second_task(void);
void third_task(void);
void print_menu(void);
int get_variant(int count);

int main()
{
    int variant;
    do {
        print_menu();
        variant = get_variant(4);
        if (variant == 1)
        {
            first_task();
        }
        else if(variant == 2)
        {
            second_task();
        }
         else if(variant == 3)
        {
            third_task();
        }

        if (variant != 4)
            system("pause");
    } while (variant != 4);
    return 0;
}

void first_task()
  {
     int n, x, i;
     printf( "Enter n :" );
     scanf( "%d", &n );
     printf( "Enter x :" );
     scanf( "%d", &x );

     int *a_array ;
     a_array = (int*)malloc(n * sizeof(int));
     for (i = 0; i<n; i++)
  {
    printf("a[%d] = ", i);
    scanf("%d", &a_array[i]);
  }
     int *mult_array ;
     mult_array = (int*)malloc(n * sizeof(int));
     for (i = 0; i<n; i++) {
     mult_array[i]=a_array[i]*pow(x,n-i);
     printf("Monom [%d] %d \n", i, mult_array[i]);
     }
    int polinom = 0;
    for (i = 0; i<n; i++) {
     polinom +=  mult_array[i];
     }
    printf("Polynomial value %d \n", polinom);
  getchar();
 }
void second_task()
{
    double f(double x)
{
    return 18*x - asin(x) - 83;
}
    double x0 = 0.1;
    double x1 = 0.9;
    double e = 0.00001;

    double method_chord(double x_prev, double x_curr, double e)
{
    double x_next = 0;
    double tmp;
    do
    {
        tmp = x_next;
        x_next = x_curr - f(x_curr) * (x_prev - x_curr) / (f(x_prev) - f(x_curr));
        x_prev = x_curr;
        x_curr = tmp;
    } while (abs(x_next - x_curr) > e);
  return x_next;
}
    double x = method_chord(x0, x1, e);
    printf("Method_chord %f", x);
    putchar('\n');
}
void third_task()
{
  double InFunction(double x)
  {
  return pow(sqrt(x)-1,2);
  }
double Rectangle_method(double a, double b, int n)
{
  int i;
  double result, h;
  result = 0;
  h = (b - a) / n;
  for(i = 0; i < n; i++)
  {
     result += InFunction(a + h * (i + 0.5));
  }
  result *= h;
  return result;
}
double Simpson_method(double a, double b, int n)
{
	int i;
    double result, h;
    result = 0;
    h = (b - a) / n;
      for(i = 0; i < n; i++)
  {
    result += ((b - a)/6)* InFunction(a) + 4*InFunction((a+b)/2) + InFunction(b);
  }
     result *= h;
  return result;
}

  double integral, integral2;
  integral = Rectangle_method(1, 2, 500);
  printf("Rectangle_method : %lf \n", integral);
  integral2 = Simpson_method(1, 2, 500);
  printf("Simpson_method: %lf \n", integral2);
}

void print_menu() {
    system("cls");
    printf("============ MENU ============ \n");
    printf("1. Horner's Scheme \n");
    putchar('\n');
    printf("2. Chord Method for Equation \n");;
    putchar('\n');
    printf("3. The rectangle method and the Simpson method for the integral \n");;
    putchar('\n');
    printf("4. Exit \n");
    printf("=>");
}

int get_variant(int count) {
    int variant;
    char s[100];
    scanf("%s", s);
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Incorrect input. Try again: ");
        scanf("%s", s);
    }
    return variant;
}
