#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <locale.h>

#define ENG 26
#define RUS 32

#define N 50

#define PUT_DELIM(x, h, b) (x) + (h) >= (b) ? '\n' : ' '

#define COND1(x) (x) <= -1.0
#define FUNC1(x) sqrt (1 - (x))

#define COND2(x) (x) > -1 && (x) <= 2.0
#define FUNC2(x) asin((x)+2)
#define FUNC3(x) (x) + 1

#define FUNC(x) COND1(x) ? FUNC1(x): (COND2(x) ? FUNC2(x) : FUNC3(x))

void first_task(void);
void second_task(void);
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

printf ("Click to tab and calculate the integral function");

    FILE *fp = fopen("output.txt" , "w");

    double a = -3.0, b = 3.0, x, h = 0.2;

    fprintf (fp,"x: \t");
     for (x = a; x <= b; x +=h)     {
             fprintf (fp,"%6.2f %c", x, PUT_DELIM(x, h, b));
     }

    fprintf (fp,"y: \t");

    for (x = a; x <= b; x +=h)     {
        fprintf (fp,"%6.3f%c", FUNC(x), PUT_DELIM(x, h, b));
    }
   putchar('\n');
   //rectangle method
	double S = 0, h1;
	h1 = (b - a)/N;
	x = a + h1;
	while (x < (b))
	{
		S = S + 4*FUNC(x);
		x = x + h1;
		if (x >= (b)) break;
		S = S + 2*FUNC(x);
		x = x + h1;
	}
	S = (h1/3)*(S + FUNC(a) + FUNC(b));
	fprintf (fp,"Integral is %f", S);
	_getch ();

	fclose (fp);
	printf ("The result was successfully saved in the file 'output.txt'");
    putchar('\n');
}
void second_task()
{
	setlocale(LC_ALL,"Russian");
	int n;
	printf ("Enter natural number n: ");
	scanf("%d", &n);
	getchar ();
	if (n < 1) return 0;
	printf ("To encrypt text, enter '1' or other symbol to exit: ");
	char c;
	scanf("%c", &c);
	if (c == '1') encrypt (n);
}
void encrypt (int n)
{
	FILE *fp1 = fopen("input.txt" , "r");
	FILE *fp2 = fopen("output_text.txt" , "w");
	int flag;
	char c;
	c = getc(fp1);
	while (!feof(fp1))
	{
		flag = 0;
		if (c >= 'A' && c <= 'Z')
		{
			c = c + (n % ENG);
			if (c > 'Z') c = 'A' + (c - 'Z') - 1;
			fprintf (fp2, "%c", c);
			flag = 1;
		}
		if (c >= 'a' && c <= 'z')
		{
			c = c + (n % ENG);
			if (c > 'z') c = 'a' + (c - 'z') - 1;
			fprintf (fp2, "%c", c);
			flag = 1;
		}
		if (c >= 'À' && c <= 'ß')
		{
			c = c + (n % RUS);
			if (c > 'ß') c = 'À' + (c - 'ß') - 1;
			fprintf (fp2, "%c", c);
			flag = 1;
		}
		if (c>='à' && c<='ÿ')
		{
			c = c + (n % RUS);
			if (c > 'ÿ') c = 'à' + (c - 'ÿ') - 1;
			fprintf (fp2, "%c", c);
			flag = 1;
		}
		if (!flag) fprintf (fp2, "%c", c);
		c = getc(fp1);
	}
	fclose (fp1);
	fclose (fp2);

	printf ("The result was successfully saved in the file 'output_text.txt'");
    putchar('\n');
}

void print_menu() {
    system("cls");
    printf("============ MENU ============ \n");
    printf("1. Tab and calculate the integral function \n");
    putchar('\n');
    printf("2. Caesar cipher to encrypt text with the 'n' shift\n");;
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
