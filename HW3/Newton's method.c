#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cmath>
using namespace std;

double f(double x) {
    return x-pow(3,-x);
}
void compute()
{
    double p0=0.5;
    char temp[50];

    printf(" n         pn          |pn-pn-1|\n");
    printf("%2d    %.9f\n", 0, p0);
    for(int i=1;i<=3;i++)
    {
        double pn=p0-f(p0)/(1+pow(3,-p0)*log(3)); 
        sprintf(temp,"%0.9f",pn);
        pn=atof(temp);
        printf("%2d    %.9f     %.9f\n", i,pn, pn-p0);
        p0=pn;
    }
}
int main()
{
    compute();
    return 0;
}