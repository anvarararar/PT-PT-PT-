#include <stdio.h>
#include <math.h>
#include <assert.h>

int kvadratnoe_uravnenie (double a, double b, double c);
int linear_uravnenie(double b, double c);

int main()
{
    printf ("Reshalka kvadratnogo uravnenia v.100500(c)Anvar\n");

    printf ("Vvedi chisla a,b,c:\n");
    double a, b, c;
    int x = scanf("%lg %lg %lg", &a, &b, &c);
    if (x!=3)
        {
        printf ("Do you know, chto takoe chislo? Yes? Tak pochemu je you vvodish kakuyto dich?!?!!!\nZapusti programmu zanovo i vvedi chisla!\n");
        return -1;
        }

    kvadratnoe_uravnenie (a, b, c);
    return 0;
}

//-----------------------------------------------------------------------------

int kvadratnoe_uravnenie (double a, double b, double c)
{
    double discr = b*b-4*a*c;

    if (a == 0)
        linear_uravnenie(b, c);

    else if      (discr > 0)
    {
        double x1=(-b+sqrt(b*b-4*a*c))/2/a;
        double x2=(-b-sqrt(b*b-4*a*c))/2/a;
        printf ("dva kornya\n    x1=%lg\n    x2=%lg\n",x1,x2);
    }

    else if (discr < 0)
        printf ("Net korney");

    else if (discr = 0)
        printf ("odin koren\n   x=%lg\n",(-b)/(2*a));

    return 0;
}


//-----------------------------------------------------------------------------

int linear_uravnenie (double a, double b)
{
    if (a!=0)
    {
        double x=((-b)/a);
        printf ("odin koren\n   x=%lf\n",x);
    }

    if ((a==0) && (b==0))
        printf ("beskonechnoe kolichestvo korney\n");


    if ((a==0) && (b!=0))
        printf ("korney net\n");

    printf ("\nPT!PT!PT!\n");

}






