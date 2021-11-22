#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void printmatrix(double a[3][4], int n)
{
    int i,j;
    for(i = 1; i<=n; i++){
        printf("\n");
        for(j=1; j<=n+1; j++){
            printf(" %5.2f ",a[i-1][j-1]);
        }
    }
    printf("\n");
}
double maxS(double arr[3][4], int n, int i)
{
    double max=fabs(arr[i][0]);
    for(int k=1;k<n;k++)
    {
        if(max<fabs(arr[i][k])) max=fabs(arr[i][k]);
    }
    return max;
}
int main()
{
    //double arr[3][4] = {{1,-5,1,7},{10,0,20,6},{5,0,-1,4}}; //a
    //double arr[3][4] = {{1,1,-1,1},{1,1,4,2},{2,-1,2,3}}; //b
    //double arr[3][4] = {{2,-3,2,5},{-4,2,-6,14},{2,2,4,8}}; //c
    double arr[3][4] = {{0,1,1,6},{1,-2,-1,4},{1,-1,1,5}}; //d
    double pivot, temp, m;
    int n=3, maxIndex;
    double a0,a1,t0,t1;
    double s[n]; //reuse
    for(int i=0;i<n;i++)
    {
        s[i]=maxS(arr,n,i);
    }
    printf("  [ Before Matirx ]");
    printmatrix(arr,n);
    
    for(int i=0;i<n;i++)
    {
        //pivot 정하기 - scaled max
        pivot=arr[i][i]*1.0;
        a0=fabs(arr[i][i]);
        //s0=maxS(arr,n,i);
        t0=a0/s[i];
        maxIndex=i;
        //printf("a: %f s: %f\n",a0,s[i]);
        for(int j=i+1;j<n;j++)
        {
            a1=fabs(arr[j][i]);
            //s1=maxS(arr,n,j);
            t1=a1/s[j]; printf("a: %f s: %f\n",a1,s[j]);
            if(t0<t1)
            {
                maxIndex=j;
                pivot=arr[j][i];
            }
        }
        if(maxIndex!=i) //swap maxIndex, i
        {
            printf("\nswap %dth %dth\n",i+1,maxIndex+1);
            for(int k=i;k<n+1;k++)
            {
                temp=arr[i][k];
                arr[i][k]=arr[maxIndex][k];
                arr[maxIndex][k]=temp;
            }
            temp=s[i];
            s[i]=s[maxIndex];
            s[maxIndex]=temp;
            //printmatrix(arr,n);
        }
        
        //printf("pivot : %f\n",pivot);
        //가우스 소거법
        for(int j=i+1;j<n;j++)
        {
            if(arr[j][i]==0) break;
            
            m=(arr[j][i]/pivot)*(-1.0);
            //printf("j: %d i: %d  m : %f\n",j,i,m);
            for(int k=i;k<n+1;k++)
            {
                arr[j][k]=arr[j][k]+m*arr[i][k];
            }
        }
        //printf("\n%d result",i);
        //printmatrix(arr,n);
    }
    printf("\n  [ Result Matirx ]");
    printmatrix(arr,n);
    return 0;
}
