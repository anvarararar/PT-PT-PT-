#include <stdio.h>
#include <math.h>
#include <assert.h>

int kvadratnoe_uravnenie (double a, double b, double c, double* x1, double* x2, double* x);
int linear_uravnenie (double b, double c, double* x);
int vvod_chisel (double* a, double* b, double* c);

int main()
{
    printf ("Reshalka kvadratnogo uravnenia v.100500(c)Anvar\n");

    double x1 = NAN;
    double x2 = NAN;
    double x = NAN;
    double a = NAN;
    double b = NAN;
    double c = NAN;

    int proverka = vvod_chisel (&a, &b, &c);

    if (proverka == 4)
        return 0;

    int kolichestvo_korney = kvadratnoe_uravnenie (a, b, c, &x1, &x2, &x);

    if (kolichestvo_korney == 2)
        printf ("dva kornya\n    x1 = %lg\n    x2 = %lg\n", x1, x2);

    else if (kolichestvo_korney == 1)
         printf ("odin koren\n   x = %lg\n", x);

    else if (kolichestvo_korney == -1)
        printf ("beskonechnoe kolichestvo korney\n");

    else if (kolichestvo_korney == 0)
        printf ("korney net\n");

    return 0;
}

//-----------------------------------------------------------------------------

int kvadratnoe_uravnenie (double a, double b, double c, double* x1, double* x2, double* x)
{
    double discr = (b*b-4*a*c);

    if (a == 0)
        return linear_uravnenie(b, c, x);

    else if      (discr > 0)
    {
        double t = sqrt(discr);// корень из дискриминанта
        *x1 = ((-b+t))/2/a;
        *x2 = (-b-t)/2/a;
        return 2;
    }

    else if (discr < 0)
        return 0;

    else if (discr == 0)
    {
        *x = (-b)/(2*a);
        return 1;
    }

    return 3;
}


//-----------------------------------------------------------------------------

int linear_uravnenie (double a, double b, double* x)
{
    if (a!=0)
    {
        *x = ((-b)/a);
        return 1;
    }

    if ((a==0) && (b==0))
        return -1;

    if ((a==0) && (b!=0))
        return 0;


    printf ("\nPT!PT!PT!\n");

}


//-----------------------------------------------------------------------------

int vvod_chisel (double* a, double* b, double* c)
{
    printf ("Vvedi chisla a,b,c:\n");
    int y = scanf("%lg %lg %lg", a, b, c);
    if (y != 3)
        {
            printf ("Do you know, chto takoe chislo? Yes?"
            "Tak pochemu je you vvodish kakuyto dich?!?!!!\n"
            "Zapusti programmu zanovo i vvedi chisla!\n");
            return 4;
        }
}





