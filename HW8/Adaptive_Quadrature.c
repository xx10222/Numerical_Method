#include <stdio.h>
#include <math.h>

double f(double x){
    return exp(2*x)*sin(3*x);
}
double simpson(double a, double b)
{
    double h;
    h = ((b-a)/2.0);
    return (h/3)*(f(a)+4*f(a+h)+f(b));
}
double adaptive(double a, double b, double TOL)
{
    double res1=simpson(a,b);
    double res2=simpson(a, (a+b)/2)+simpson((a+b)/2, b);
    if(fabs(res1-res2) <= 15*TOL)
        return res2;
    else
        return adaptive(a,(a+b)/2,TOL/2)+adaptive((a+b)/2,b,TOL/2); 
}
void main()
{
    double a=1;
    double b=3;
    double TOL = pow(10,-5); 
    printf("%.6f\n", adaptive(a,b,TOL));
}