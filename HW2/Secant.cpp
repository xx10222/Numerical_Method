#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

double f(double x) {
    return x*x*x+4*x*x-10;
}
void compute()
{
    double p0=1;
    double p1=2;
    double TOL=0.0005;
    double temp;
    
    int n=min(20, (int)(log((p1-p0)/TOL)/log(2.0)+0.5))/2.0;
    
    printf(" n        pn            f(pn)\n");
    for(int i=1;i<=n;i++)
    {
        double pn=p1-((f(p1)*(p1-p0))/(f(p1)-f(p0)));
        printf("%2d   %.10f ", i+1,pn);
        if(f(pn)>0) printf(" ");
        printf(" %.10f \n",f(pn));
        
        p0=p1;
        p1=pn;
    }
}
int main()
{
    compute();
    return 0;
}
