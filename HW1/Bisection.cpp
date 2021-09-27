#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
double f(double x) {
    return x*x*x+4*x*x-10;
}
void compute()
{
    double a1=1;
    double b1=2;
    double an=a1;
    double bn=b1;
    double TOL=0.0005;
    int n=min(20, (int)(log((b1-a1)/TOL)/log(2.0)+0.5));
    
    printf(" n        an             bn             pn            f(pn)\n");
    for(int i=0;i<n;i++)
    {
        double pn=an+(bn-an)/2.0;
        printf("%2d   %.10f   %.10f   %.10f ", i+1,an,bn,pn);
        if(f(pn)>0) printf(" ");
        printf(" %.10f \n",f(pn));
        
        if(f(an)*f(pn)<0) bn=pn;
        else an=pn;
    }
}
int main()
{
    compute();
    return 0;
}