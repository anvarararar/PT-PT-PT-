#include <stdio.h>
#include <math.h>
#include <assert.h>

int kvadratnoe_uravnenie (double a, double b, double c, double* x1, double* x2);
int linear_uravnenie (double b, double c, double* x1);
int vvod_chisel (double* a, double* b, double* c);

int main()
{
    printf ("Reshalka kvadratnogo uravnenia v.100500(c)Anvar\n");

    //ToDo: const DOUBLE_POISON - not vazhno
    double x1 = NAN;
    double x2 = NAN;
    double a = NAN;
    double b = NAN;
    double c = NAN;
    char INPUT_ERROR = 0;

    int proverka = vvod_chisel (&a, &b, &c);


    if (proverka == INPUT_ERROR)
        return 0;


    int kolichestvo_korney = kvadratnoe_uravnenie (a, b, c, &x1, &x2);

    //ToDo: Switch
    {switch (kolichestvo_korney)
    {
        case 1:
            printf("odin koren\n   x1 = %lg\n", x1);
            break;
        case 2:
            printf("dva kornya\n    x1 = %lg\n    x2 = %lg\n", x1, x2);
            break;
        case -1:
            printf ("beskonechnoe kolichestvo korney\n");
            break;
        case 0:
            printf("korney net\n");
            break;}
            }


    return 0;
}

//-----------------------------------------------------------------------------

int kvadratnoe_uravnenie (double a, double b, double c, double* x1, double* x2)
{
    if (a == 0)
        return linear_uravnenie(b, c, x1);

    double discr = (b*b-4*a*c);

    if      (discr > 0)
    {
        double t = sqrt(discr);// корень из дискриминанта
        *x1 = ((-b+t))/2/a;
        *x2 = (-b-t)/2/a;
        assert (x1 != x2);
        return 2;
    }

    else if (discr < 0)
        return 0;

    else if (discr == 0)
    {
        *x1 = (-b)/(2*a);
        return 1;
    }

    return 3;
}


//-----------------------------------------------------------------------------

int linear_uravnenie (double a, double b, double* x1)
{
    printf ("\nPT!PT!PT!\n");
    if (a!=0)
    {
        *x1 = ((-b)/a);
        return 1;
    }

    if ((a==0) && (b==0))
        return -1;

    if ((a==0) && (b!=0))
        return 0;

}


//-----------------------------------------------------------------------------

int vvod_chisel (double* a, double* b, double* c)
{
    assert (a != nullptr);
    char INPUT_ERROR = 0;
    printf ("Vvedi chisla a,b,c:\n");
    int y = scanf("%lg %lg %lg", a, b, c);
    if (y != 3)
        {
            printf ("Do you know, chto takoe chislo? Yes?"
            "Tak pochemu je you vvodish kakuyto dich?!?!!!\n"
            "Zapusti programmu zanovo i vvedi chisla!\n");
            return INPUT_ERROR;
       }
}





