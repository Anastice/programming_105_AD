#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>

void first_task(void);
void second_task(void);
int IsPrime(unsigned int number);
void print_menu(void);
int get_variant(int count);

int main()
{
    int variant;
    do {
        print_menu();
        variant = get_variant(3);
        if (variant == 1)
        {
            first_task();
        }
        else if(variant == 2)
        {
            second_task();
        }

        if (variant != 3)
            system("pause");
    } while (variant != 3);
    return 0;
}

void first_task()
{
    int i, n, *mas, av, *m;
    int sum = 0 ;
    printf("Enter the number of array elements: ");
    scanf("%d", &n);
    srand(time(NULL));
    mas = malloc(n * sizeof(int));
    m = malloc(n * sizeof(int));
    printf("Your array: ");
    for (i = 0; i < n; ++i){
        mas[i] = rand() % 100;
        printf("%d ", mas[i]);
        }
    for ( i = 0; i<n; i++) {
        sum += mas[i];
        av = sum/n ;
       }
    putchar('\n');
    printf("Arithmetic average of the array: %d", av);
    putchar('\n');
    printf("Your new array: ");
    for ( i = 0; i < n; ++i) {
        m[i] = mas[i] - av;
        printf("%d ", m[i]);
       }
    putchar('\n');
    free(mas);
    free(m);
}

void second_task()
{
    int lines, columns, prime_num = 0, sum = 0;
    printf("Enter number of lines: ");
    scanf("%d", &lines);
    printf("Enter number of columns: ");
    int **matrix = (int**)malloc(lines * sizeof(int));
    srand(time(NULL));
    scanf("%d", &columns);
    for (int i = 0; i < lines; ++i)
    {
        matrix[i] = (int*)malloc(columns * sizeof(int));
    }
    for (int i = 0; i < lines; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            matrix[i][j] = rand()%101 -20;
        }
    }
    printf("\nYour matrix :\n");
    for (int i = 0; i < lines; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n\n");
    }
    printf("Prime number(s): ");
    for (int i = 0; i < lines; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if(IsPrime(matrix[i][j]))
            {
                sum += matrix[i][j];
                printf("%d[%d][%d]\t", matrix[i][j], i, j);
                prime_num++;
            }
        }
    }
    printf("\nTotal primes: %d", prime_num);
    printf("\nAverage of prime numbers: %d", sum/prime_num);

    for (int i = 0; i < lines; ++i)
        {
            free(matrix[i]);
        }
        free(matrix);

}

int IsPrime(unsigned int number)
{
    if (number <= 1) return 0;
    unsigned int i;
    for (i=2; i*i<=number; i++)
    {
        if (number % i == 0) return 0;
    }
    return 1;
}

void print_menu() {
    system("cls");
    printf("============ MENU ============ \n");
    printf("1. Enter the number of array elements \n");
    printf("   Calculate arithmetic average of the array\n");
    printf("   Build a new one-dimensional array with the differences of the corresponding elements and the resulting average \n");
    putchar('\n');
    printf("2. Print the indices of prime numbers \n");
    printf("   Calculate the total number and average value \n");
    putchar('\n');
    printf("3. Exit \n");
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
