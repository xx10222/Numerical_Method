#include <math.h>
#include <stdio.h>

double f(double x) { //given the function f at the following values
    double res;
    if(x==1.8) res=3.12014;
    else if(x==2.0) res=4.42569;
    else if(x==2.2) res=6.04241;
    else if(x==2.4) res=8.03014;
    else if(x==2.6) res=10.46675;
    return res;
}
double Midpoint(double a, double b) {
    return (b-a)*f((a+b)/2);
}
double Trapezoidal(double a, double b) {
    return ((f(a)+f(b))/2)*(b-a);
}
double Simpson(double a, double b) {
    return ((b-a)/6)*(f(a) + 4*f((a+b)/2) + f(b));
}
int main()
{
    double a=1.8;
    double b=2.6;
    
    printf("(1)Midpoint  (2)Trapezoidal  (3)Simpson\n");
    printf("  %.5f       %.5f        %.5f\n", Midpoint(a,b), Trapezoidal(a,b), Simpson(a,b));
 
    return 0;
}
