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
int main()
{
    double arr[3][4] = {{1,-5,1,7},{10,0,20,6},{5,0,-1,4}}; //a
    //double arr[3][4] = {{1,1,-1,1},{1,1,4,2},{2,-1,2,3}}; //b
    //double arr[3][4] = {{2,-3,2,5},{-4,2,-6,14},{2,2,4,8}}; //c
    //double arr[3][4] = {{0,1,1,6},{1,-2,-1,4},{1,-1,1,5}}; //d
    double pivot, temp, m;
    int n=3, maxIndex;
    printf("  [ Before Matirx ]");
    printmatrix(arr,n);
    
    for(int i=0;i<n;i++) //partial pivoting
    {
        pivot=arr[i][i]*1.0;
        maxIndex=i;
        for(int j=i+1;j<n;j++)
        {
            if(fabs(arr[j][i])>fabs(pivot))
            {
                maxIndex=j;
                pivot=arr[j][i];
            }
        }
        if(maxIndex!=i)
        {
            printf("\n *swap %dth %dth\n",i+1,maxIndex+1);
            for(int k=i;k<n+1;k++)
            {
                temp=arr[i][k];
                arr[i][k]=arr[maxIndex][k];
                arr[maxIndex][k]=temp;
            }
        }
        //Gaussian elimination
        for(int j=i+1;j<n;j++)
        {
            if(arr[j][i]==0) break;
            
            m=(arr[j][i]/pivot)*(-1.0);
            for(int k=i;k<n+1;k++)
            {
                arr[j][k]=arr[j][k]+m*arr[i][k];
            }
        }
    }
    printf("\n  [ Result Matirx ]");
    printmatrix(arr,n);
    return 0;
}
