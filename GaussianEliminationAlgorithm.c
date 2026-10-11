#include <stdio.h>
#include <stdlib.h>
#include "UpperTriangularSystemAlgorithm.c"

struct Result {
    double **A;
    double *b;
};
struct Result *GaussianEliminationAlgorithm(double **A,int n,double *b){
    struct Result *r=malloc(sizeof(struct Result));
    r->A=A;
    r->b=b;   
    for(int i=0;i<n;i++){
            int j=i;
            while(j<n && A[j][i]==0)
                j+=1;
            if(j==n){
                
                printf("No unique solution");
                return NULL;
            }
            double *t=(double *)malloc(sizeof(double)*(n-i+1));
            double u=b[i];
            for(int k=i;k<n;k++){
                t[k]=A[i][k];
            }
            for(int k=i;k<n;k++){
                A[i][k]=A[j][k];
            }
            b[i]=b[j];
            for(int k=i;k<n;k++){
                A[j][k]=t[k];
            }
            b[j]=u;

            for(int j=i+1;j<n;j++){
                double m = A[j][i] / A[i][i];
                b[j] -= m * b[i];
                for(int k=i;k<n;k++){
                    A[j][k] -= m * A[i][k];
                }
            }
            free(t);
        }
        
        return r;
}

int main(void){
    double ligne1[] = {2, 1, -1};
    double ligne2[] = {-3, -1, 2};
    double ligne3[] = {-2, 1, 2};

    double *lignes[] = {ligne1, ligne2, ligne3};
    double **A = lignes;

    double b[] = {8, -11, -3};
    struct Result *r=GaussianEliminationAlgorithm(A,3,b);

    float *x=UpperTriangularSystemAlgorithm(r->A,3,r->b);

    printf("x1 = %f\n", x[0]);
    printf("x2 = %f\n", x[1]);
    printf("x3 = %f\n", x[2]);
}