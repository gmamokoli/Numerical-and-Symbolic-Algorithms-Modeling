#include <stdio.h>
#include <stdlib.h>

float *UpperTriangularSystemAlgorithm(double **A,int n,double *b){
        float *x=(float *)malloc(sizeof(float)*n);
        if (x == NULL) {
            return NULL;
        }
        for(int i=n-1;i>=0;i--){
            x[i]=b[i];
            for(int j=i+1;j<n;j++){
                x[i]-=A[i][j]*x[j];
            }
            if(A[i][i]==0){
                free(x);
                return NULL;
            }
            x[i]/=A[i][i];
        }
        return x;
}

// int main(void){
//     int ligne1[] = {1, 3, 4};
//     int ligne2[] = {1, 3, 4};
//     int ligne3[] = {1, 3, 4};

//     int *lignes[] = {ligne1, ligne2, ligne3};
//     int **A = lignes;
//     // int A[][]={{1,3,4},{1,3,4},{1,3,4}};
//     int b[]={1,3,4};
//     float *x=UpperTriangularSystemAlgorithm(A,3,b);
//     printf("premier element %lf",x[1]);
// }