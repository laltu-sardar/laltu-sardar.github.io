#include <stdio.h>
#include <stdlib.h>


int ** memory_for_2d(int m, int n){
    int i;
    int ** a = malloc(m * sizeof(int *));
    if (a==NULL) {
        goto Error;
    }

    for (i = 0; i < m; i++) {
        a[i] = malloc(n * sizeof(int));
        if (a[i]==NULL) {
            goto Error;
        }
    }
    return a;

    Error:
        printf("Error in allocating Memory\n" );
        return NULL;

}

int free_2d_matrix(int ** a, int m){
    int i;
    for (i = 0; i < m; i++) {
        free(a[i]) ;
    }
    free(a);
    return 0;
}


void matrix_scan(int m, int n, int **a){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter the %d%d th entry",i,j);
            scanf("%d",&a[i][j] );
        }
    }
}



void matrix_print(int m,int n,int **a){
    int i, j;
    for ( i = 0; i < m; i++) {
        for ( j = 0; j < n; j++) {
            printf("%d\t",a[i][j]);

        }
        printf("\n" );
    }
    return;
}

int ** matrix_add( int **a,  int **b, int m, int n){
    int ** c = memory_for_2d(m,n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            c[i][j] = a[i][j] +b[i][j];
        }
    }
    return c;
}


void matrix_scan_from_file(int m, int n, int **a, FILE * f_ptr){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            //printf("Enter the %d%d th entry",i,j);
            fscanf(f_ptr,"%d",&a[i][j] );
        }
    }
}

struct Matrix {
    char c, d;
    int row;
    int col; 
    int ** mat;
    
};


struct Matrix    matrix_transpose(struct Matrix A ){
    struct Matrix B;
    B.row = A.col;
    B.col = A.row;
    B.mat =   memory_for_2d(B.row, B.col);
      for (int i = 0; i < B.row; i++) {
        for (int j = 0; j < B.col; j++) {
            B.mat[i][j] = A.mat[j][i];
        }
    }
    return B;
}

struct Matrix matrix_multi(struct Matrix A, struct Matrix B){
    struct Matrix C;
    C.row = A.row;
    C.col = B.col;
    C.mat = memory_for_2d(C.row, C.col);
    for (int i = 0; i < A.row; i++) {
        for (int j = 0; j < B.col; j++) {
            for (int k = 0; k < A.col; k++)
                C.mat[i][j] = A.mat[i][k]*B.mat[k][j];
        }
    }
    return C;
}
    
    

void new_matrix_print(struct Matrix A){
    int i, j;
    for ( i = 0; i < A.row; i++) {
        for ( j = 0; j < A.col; j++) {
            printf("%d\t",A.mat[i][j]);

        }
        printf("\n" );
    }
    return;
}



int main(int argc, char const *argv[])
{
    int n=2, m=2;
    
    
    struct Matrix A, B; 
    A.row = 2; 
    A.col = 2;
    A.mat = memory_for_2d(m,n);
    
    B = matrix_transpose(A);
    
    printf("Size of A= %lu\n", sizeof(A));
    printf("Size of  %lu %lu  %lu  %lu  %lu\n",  & (A.c), & (A.d), & ( A.row),  & ( A.col),  & ( A.mat) );
    
    //int *b;
    //int i, j;

    int **a=memory_for_2d(m,n);//
    //matrix_scan(m,n,a);
    FILE * f1, * f2;
    f1 = fopen("matrix_a.csv","r"); //create this file yourself
    if (f1==NULL) {
        goto Error;
    }
    matrix_scan_from_file(m,n,a, f1);
    matrix_scan_from_file_new( A, "matrix_a.csv");
    
    
    matrix_print(m,n,a);
    fclose(f1);

    int **b=memory_for_2d(m,n);//
    //matrix_scan(m,n,b);
    //FILE * f2;
    f2 = fopen("matrix_a.csv","r");
    matrix_scan_from_file(m,n,b, f2);
    matrix_print(m,n,b);
    fclose(f2);
    
    

    int ** c  = matrix_add(a,b,m,n);

  

    free_2d_matrix(a, m);
    free_2d_matrix(b, m);
    free_2d_matrix(c, m);



    //printf("%lu\n", sizeof(b));
    //printf("%lu\n", sizeof(mat[2][2]));
    //printf("%lu\n", sizeof(mat[i]));



        return 0;
Error:
    printf("Errror in openning file\n");
    exit(0);        
        
}
