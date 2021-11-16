#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double f(double t, double y) {
    return 5*exp(5*t)*(y-t)*(y-t)+1;
}
double fy(double t, double y) {
    return 10*exp(5*t)*(y-t);
}
double y(double t) {
    return t-exp(-5*t);
}
double Runge_Kutta(double t, double w, double h) {
    double k1=h*f(t,w);
    double k2=h*f(t+0.5*h,w+0.5*k1);
    double k3=h*f(t+0.5*h,w+0.5*k2);
    double k4=h*f(t+h,w+k3);
    return w+(1.0/6)*(k1+2*k2+2*k3+k4);
}
double Trapezoidal(double t, double w, double h) {
    int M = 10;
    double TOL=pow(10,-6);
    double w1, w2;
    double diff;
    w1=w;
    w2 = w1-((w1-w-h*0.5*(f(t,w)+f(t+h,w1))) / (1-h*0.5*fy(t+h,w1)));
    for(int i=0;i<M;i++)
    {
        diff=fabs(w2-w1);
        if(diff<TOL) break;
        w1=w2;
        w2=w1-((w1-w-h*0.5*(f(t,w)+f(t+h,w1))) / (1-h*0.5*fy(t+h,w1))) ;
    }
    return w2;
}
int main()
{
    double h = 0.2;
    double TOL = 1/1000000;
    double t=h;
    double w=-1;
    double r=-1;
    double exact=-1; //실제 함숫값
    int e;
    int N=1/h;
    
    printf("         Runge-Kutta method                  Trapezoidal Method            \n");
    printf("-----------------------------------------------------------------------------\n");
    printf("                h=0.2                                h=0.2                   \n");
    printf("-----------------------------------------------------------------------------\n");
    printf(" ti           wi          |y(ti)-wi|          wi          |y(ti)-wi|    \n");
    printf("-----------------------------------------------------------------------------\n");
    
    for(int i=0;i<=N;i++)
    {
        e=i-1;
        if(i!=0)
        {
            exact=y((i)*t);
            r=Runge_Kutta(t*e,r,h);
            w=Trapezoidal(t*e,w,h);
        }
        
        printf(" %.2f     %10.7f      %10.7f      %10.7f      %10.7f \n",t*i,r,fabs(exact-r),w,fabs(exact-w));
    }
    return 0;
}
