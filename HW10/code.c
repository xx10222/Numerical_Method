#include <stdio.h>
#include <math.h>
double f(double t, double y) {
    return y-t*t+1;
}
double Exact(double t) {
    return t*t+2*t+1-0.5*exp(t);
}
double Euler(double t, double w) {
    double h=0.025;
    for(int i=0;i<4;i++) w=w+h*f(t+h*i,w);
    return w;
}
double Modified_Euler(double t, double w) {
    double h=0.05;
    double y;
    int e;
    for(int i=1;i<=2;i++) 
    {
        e=i-1;
        y=f(t+h*e,w);
        w= w + h*0.5*(y+f(t+h*i, w+h*y));
    }
    return w;
}
double Runge_Kutta(double t, double w) {
    double h=0.1;
    double k1=h*f(t,w);
    double k2=h*f(t+0.5*h,w+0.5*k1);
    double k3=h*f(t+0.5*h,w+0.5*k2);
    double k4=h*f(t+h,w+k3);
    return w+(1.0/6)*(k1+2*k2+2*k3+k4);
    
}
int main()
{
    double t=0.1;
    double w=0.5;
    double mw=0.5;
    double r=0.5;
    int e;
    printf(" ti        Exact         Euler       Modified Euler     Runge-Kutta  \n");
    printf(" %.1f     %.7f     %.7f       %.7f         %.7f\n",0.0,Exact(0.0),w,w,w);
    for(int i=1;i<=5;i++)
    {
        e=i-1;
        w=Euler(t*e,w);
        mw=Modified_Euler(t*e,mw);
        r=Runge_Kutta(t*e,r);
        printf(" %.1f     %.7f     %.7f       %.7f         %.7f\n",t*i,Exact(t*i),w,mw,r);
    }
    return 0;
}
