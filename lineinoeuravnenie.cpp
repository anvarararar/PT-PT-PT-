#include <stdio.h>
#include <math.h>
#include <assert.h>

int main()

    {
    printf ("Reshalka lineinih uravnenii- solves a linear equations (ax+b=0), v.100500(c)Anvar\n");

    printf ("Vvedi a:");
    double a=0;
    scanf ("%lf",&a);

    printf ("Vvedi b:");
    double b=0;
    scanf ("%lf",&b);

    if (a!=0)
    {
    double x=((-b)/a);
    printf ("odin koren, x=%lf\n",x);
    }

    if ((a==0) && (b==0))
    printf ("beskonechnoe kolichestvo korney\n");


    if ((a==0) && (b!=0))
    printf ("korney net\n");

    printf ("\nPT!PT!PT!\n");

}
