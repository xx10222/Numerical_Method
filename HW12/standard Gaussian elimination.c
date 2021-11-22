#include <stdio.h>
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
    double arr[3][4] = {{0,1,1,6},{1,-2,-1,4},{1,-1,1,5}};
    double pivot, temp, m;
    int n=3;
 
    printmatrix(arr,n);
    
    for(int i=0;i<n;i++)
    {
        pivot=arr[i][i]*1.0;
        if(pivot==0) //row interchanges
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[j][i]!=0) //i행 j행 바꾸기
                {
                    printf("\nswap %dth %dth\n",i+1,j+1);
                    pivot=arr[j][i];
                    for(int k=i;k<n+1;k++)
                    {
                        temp=arr[i][k];
                        arr[i][k]=arr[j][k];
                        arr[j][k]=temp;
                    }
                    break;
                }
            }
            //printf("\nswap");
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
    printf("\nresult");
    printmatrix(arr,n);
    return 0;
}
