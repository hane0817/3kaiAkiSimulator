#include <stdio.h> /* printf */
#include <math.h>  /* pow */

int main(void)
{
    double ans;
    double base, exp;

    base = 2;
    exp = 2;
    ans = pow(base, exp);

    printf("%f ^ %f = %f\n", base, exp, ans);

    base = 10000;
    exp = -1.25;
    ans = pow(base, exp);

    printf("%f ^ %f = %f\n", base, exp, ans);

    return 0;
}