#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float* Gauss_Elimination(float a[5][6], int n) //get real solution of matrix
{
    static float x[5] = {0, 0, 0, 0, 0};
    float temp,tmp;
    for(int k=1; k<=n; k++) { //Gauss Jordan Elimination  
        temp = a[k-1][k-1];
        if(temp == 0){
            for(int j=k; j<=n+1; j++){
                for(int l = k; l < n; l++){
                    if(a[l][j-1] != 0){
                        tmp = a[k-1][j-1];
                        a[k-1][j-1] = a[l][j-1];
                        a[k][j-1] = tmp;
                        break;
                    }
                }
            }
            temp = a[k-1][k-1];   
        }
        for(int j=k; j<=n+1; j++){       
            a[k-1][j-1] = a[k-1][j-1]/temp;
        }
        for(int i=k+1; i<=n; i++){           
            temp = a[i-1][k-1];
            for(int j=k; j<=n+1; j++){
                a[i-1][j-1] = a[i-1][j-1] - temp*a[k-1][j-1];
            }
        }
    }
    x[n-1] = a[n-1][n];
 
    for(int k=n-1; k>=1; k--){           
        x[k-1] = a[k-1][n];
        for(int j= k+1; j<=n; j++){
            x[k-1] = x[k-1] - a[k-1][j-1]*x[j-1];
            a[k-1][j-1] = 0;
        }
        a[k-1][n] = x[k-1];
    }
    return x;
}

void main()
{
    int n=5; //matrix size
    float matrix[5][6] = {{4,1,1,0,1,6},{-1,-3,1,1,0,6},{2,1,5,-1,-1,6},{-1,-1,-1,4,0,6},{0,2,-1,1,4,6}}; //matrix e
    float a[5][5]={{4,1,1,0,1},{-1,-3,1,1,0},{2,1,5,-1,-1},{-1,-1,-1,4,0},{0,2,-1,1,4}};
    float b[5]={6,6,6,6,6};
    float pivot;
    double TOL = pow(10,-3);

    int k=1;
 
    float *x = Gauss_Elimination(matrix,n); //real value
    float x0[5]={0,0,0,0,0};
    float x1[5]={0,0,0,0,0};
    
    printf("     x1      x2      x3      x4      x5\n");
    for(int k=1; k<=n; k++){            // x값 출력
        printf("  %5.3f ",x[k-1]);
    }
    printf("\n");
    for(int i=0;i<n;i++) //conversion matrix
    {
        pivot=a[i][i]*1.0;
        for(int j=0;j<n;j++)
        {
            if(i==j) {
                a[i][i]=0;
            }
            else {
                a[i][j]=(a[i][j]/pivot)*-1.0;
            }
        }
        b[i]=b[i]/pivot*1.0;
    }
    printf("\n");
    printf(" k      x1       x2       x3       x4       x5\n");
    printf(" 0 ");
    for(int i=0;i<n;i++)
    {
        printf("  %6.3f ",x0[i]);
    }
    printf("\n");
    while(1)
    {
        if(fabs(x[0]-x1[0])<TOL) break;
        else {
            for(int i=0;i<n;i++)
            {
                x0[i]=x1[i];
            }
        }
        printf("%2d ",k);
        
        /********** jacobi method **********/
        for(int i=0;i<n;i++) //jacobi
        {
            x1[i]=a[i][0]*x0[0]+a[i][1]*x0[1]+a[i][2]*x0[2]+a[i][3]*x0[3]+a[i][4]*x0[4]+b[i];
            printf("  %6.3f ",x1[i]);
        }
        /***********************************/
        
        /********** gauss-seidel method **********/
        //x1[0]=a[0][0]*x0[0]+a[0][1]*x0[1]+a[0][2]*x0[2]+a[0][3]*x0[3]+a[0][4]*x0[4]+b[0];
        //x1[1]=a[1][0]*x1[0]+a[1][1]*x0[1]+a[1][2]*x0[2]+a[1][3]*x0[3]+a[1][4]*x0[4]+b[1];
        //x1[2]=a[2][0]*x1[0]+a[2][1]*x1[1]+a[2][2]*x0[2]+a[2][3]*x0[3]+a[2][4]*x0[4]+b[2];
        //x1[3]=a[3][0]*x1[0]+a[3][1]*x1[1]+a[3][2]*x1[2]+a[3][3]*x0[3]+a[3][4]*x0[4]+b[3];
        //x1[4]=a[4][0]*x1[0]+a[4][1]*x1[1]+a[4][2]*x1[2]+a[4][3]*x1[3]+a[4][4]*x0[4]+b[4];
        //printf("  %6.3f   %6.3f   %6.3f   %6.3f   %6.3f",x1[0],x1[1],x1[2],x1[3],x1[4]);
         /*****************************************/
         
        k++;
        printf("\n");
    }
}
