#include<stdio.h>
#include<stdlib.h>

typedef struct poly {
  float * coef;
  int size;
  int deg;
} POLY;

int max(int a; int b){
 if (a>b) return a;
 return b;
}
int min(int a; int b){
 if (a<b) return a;
 return b;
}

int compute_degree(POLY C){
  int n = C.size, i;
  for (i=n; i>=0; i--){
     if (C[i] !=0){
       break;
     }
  } 
  return i;  
}


struct poly poly_add(struct poly  A, POLY B){
  POLY C;
  int i, size_c;
  size_c = max(A.deg, B.deg);
  min_deg = min(A.deg, B.deg);
  C.coef = (float * )calloc(size_c,sizeof(float));
  C.size = size_c;
  for(i = 0; i< min_deg; i++){
    C.coef[i]  = A.coef[i]+B.coef[i];
  }
  if(A.deg > B.deg){
    for(i = min_deg; i< max_deg; i++){
    C.coef[i]  = A.coef[i];
  }else if (A.deg < B.deg){
    for(i = min_deg; i< max_deg; i++){
    C.coef[i]  = B.coef[i];
  }
  C.deg = compute_degree(C);
  C.coef = realloc(C.coef,C.deg+1);
  return C;
}

POLY C poly_mult(POLY A, POLY B){
  POLY C;
  if(A.deg==0 && A.coef[0]==0){
    C.deg = 0;
    C.size = 1;
    C.coef = (float *)calloc(1, sizeof(float));        
    return C; 
  }
  if(B.deg==0 && B.coef[0]==0){
    C.deg = 0;
    C.size = 1;
    C.coef = (float *)calloc(1, sizeof(float));        
    return C;  
  }
  C.deg  = A.deg+ B.deg;
  C.size = C.deg +1;
  C.coef = (float *)calloc(C.size, sizeof(float));        
  for (int i; i<C.size; i++){
    C.coef[i] = 0;
    for (j = 0; j <=A.deg; j++){
       k = i -j;
       if (k>=0){
         C.coef[i]  += A[j]*B[k]; 
       }
    }
  } 
  return C;
}

float compute_poly(POLY A, float x){

}

int main(){
  POLY A, B;
  A.coef = (float * )calloc(4,sizeof(float));
  B.coef = (float * )calloc(4,sizeof(float));
  A.size = 4;
  B.size = 4;
  A.deg = 3;
  B.deg = 3;
  for (int i =0; i<3; i++){
    A.coef[i] = i;
    B.coef[i] = -i+1;
  }
  C = add_poly(A, B)
}