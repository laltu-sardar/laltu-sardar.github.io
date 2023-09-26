/************************************************************
File Name: laltu_ap0303.c
Problem ID: AP0303.c
Name: Laltu Sardar
Collaborators: NA
Acknowledgements: NA
Time Spent: 3 hours
************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSTRLEN 15

typedef struct stringMatrix {
    int row;
    int col;
    char *** mat;
} StringMatrix;


char * allocate_string(int );
int char_to_pos(char );
char pos_to_char(int );
void free_string_matrix(StringMatrix );
void mult_strings(char * , char *, char * );
void add_strings(char * , char *, char * );
StringMatrix multiply_string_matrices(StringMatrix  , StringMatrix );
void show_string_matrix(StringMatrix );
StringMatrix read_string_matrix_from_file(char fileName[]);
char *** allocate_string_matrix(int  , int );


//=============================================
// Function to allocate memory for a 3D string matrix
char *** allocate_string_matrix(int m , int n){
    char *** mat;
    mat = (char ***) malloc(m * sizeof (char **));
    if ( mat ==NULL) { 
            printf("\nFailed to allocate memory in allocate_string_matrix:\n");
            return NULL; 
        }
    for (int i = 0; i< m ; i++) {
        mat[i] = (char **) malloc(n * sizeof (char *));
        if (mat[i]==NULL) { 
            printf("\nFailed to allocate memory in allocate_string_matrix:\n");
            return NULL; 
        }
    }
    return mat;
}

//=============================================
// Function to allocate memory for a string
char * allocate_string(int n){
    char * s=malloc(n * sizeof (char));
    if (s==NULL) {
        printf("\nFailed to allocate memory in allocate_string:\n");
    }
    return s;
}

//=============================================
// Function to read a string matrix from a file 
StringMatrix read_string_matrix_from_file(char fileName[]){
    int i, j, l;
    StringMatrix A = {0,0,NULL};
    char tempStr[MAXSTRLEN+1];
    
    FILE * inpFilePtr =  fopen(fileName, "r"); //Open the input file
    if (inpFilePtr == NULL){
        printf("\nFailed to open:%s \n", fileName);
        return A;
    }
    if(fscanf(inpFilePtr, "%d %d", & (A.row),& (A.col))==0 ){ //read number of rows and columns
        printf("\nFails to read matrix. Check matrix format.\n");
        return A;
    }
    
    printf("Reading %d x %d string matrix\n", A.row, A.col);
    
    A.mat = allocate_string_matrix(A.row, A.col); //Allocate memory for string matrix 
    for(i =0 ; i < A.row; i++ ){
        for(j =0 ; j < A.col; j++ ){
            if (fscanf(inpFilePtr,"%s", tempStr)==0){       //scan each cell
                printf("\nUnable to read A[%d][%d]\n",i,j );
                exit(0);
            }else{
                //l = strlen(tempStr);
                A.mat[i][j] =  allocate_string(MAXSTRLEN+1);       //Allocate memory to store cell string
                strcpy(A.mat[i][j],tempStr); //copy the scanned string in the matrix cell 
            }
        }
    }
    
    fclose(inpFilePtr);
    return A;
}

//=============================================
void show_string_matrix(StringMatrix A){
    if((A.row==0) || (A.col==0) ||  (A.mat==NULL)) {
        printf("\nThe Given String Matrix is either empty or invalid\n");
        return;
    }
    int i, j;
    for (i= 0; i < A.row; i++){
        for (j= 0; j < A.col; j++){
            printf("%s ",A.mat[i][j]);
            
        }
        printf("\n");
    }
    return;
}


//=============================================
StringMatrix multiply_string_matrices(StringMatrix A , StringMatrix B){
    int i, j, k, l;
    StringMatrix C ={0,0,NULL};
    char * prodStr, * sumStr;
    prodStr = allocate_string(MAXSTRLEN+1);
    sumStr = allocate_string(MAXSTRLEN+1);
    

    if ((A.row * A.col * B.row * B.col ==0) || (A.mat==NULL) || (B.mat==NULL) ){
        printf("\nThe Given String Matrix is either empty or invalid\n");
        return C;
    }
    if (A.col != B.row){
        printf("Multiplication not possible\n");
        return C;
    }
    C.row = A.row;
    C.col = B.col;
    C.mat = allocate_string_matrix(C.row, C.col );
    
    for (i= 0; i < C.row; i++){
        for (j= 0; j < C.col; j++){
            for (k= 0; k < A.col; k++){
                mult_strings(prodStr, A.mat[i][k], B.mat[k][j]); 
                if (k==0){
                    strcpy(sumStr, prodStr);
                }else{
                    add_strings( sumStr, sumStr,  prodStr)  ;  
                }
            }   
            l = strlen(sumStr);
            C.mat[i][j] = allocate_string(l); 
            strcpy(C.mat[i][j], sumStr) ;
        }
        printf("\n");
    }
    free(prodStr);
    free(sumStr);
    return C;
}

//=============================================
// Function to free memory allocated for a string matrix
void free_string_matrix(StringMatrix A){
    int i, j; 
    for (i= 0; i < A.row; i++){
        for (j= 0; j < A.col; j++){
            if (A.mat[i][j]){
                free(A.mat[i][j]);
            }else{ 
                goto error;
            }
        }
        if (A.mat[i]){
            free(A.mat[i]);
        }else{ 
            goto error;
        }
    }
    if (A.mat){
        free(A.mat);
    }else{ 
        goto error;
    }
    return;
    
error:
    printf("\nUnable to free the string matrix\n");
    return;
}

//=============================================
// Function to add two strings
//dstStr = aStr+bStr
//all memories are allocated earlier
void add_strings(char * dstStr, char *S1, char * S2){//special string addition of ap0303
    int i, l1, l2, l3;
    char tempChr;
    l1 = strlen(S1);
    l2 = strlen(S2);
    l3 = (l1 > l2)? l2 : l1 ;
    for (i = 0; i < l3; i++){
        tempChr = (char)( ( char_to_pos(S1[i]) * char_to_pos(S2 [i]) )%26 );
        dstStr[i]=pos_to_char(tempChr);
    }
    if (l1> l2){
        for (i = l3; i < l1; i++){
            dstStr[i]=S1[i];
        } 
        dstStr[l1]='\0';   
    }else{
        for (i = l3; i < l2; i++){
            dstStr[i]=S2[i];
        }
        dstStr[l2]='\0';
    }
    //printf("\nAddition Result Strings: %s\n",dstStr);
    return;
}

//=============================================
// Function to multiply two strings
void mult_strings(char * dstStr, char *S1, char * S2){//special string addition of ap0303
    int i, l1, l2, l3;
    char tempChr;
    l1 = strlen(S1);
    l2 = strlen(S2);
    //printf("\nWorking Strings: %s %s\n",S1 ,S2);
    l3 = (l1 > l2)? l2 : l1 ;
    for (i = 0; i < l3; i++){
        tempChr = (char)( ( char_to_pos(S1[i]) * char_to_pos(S2 [i]) )%26 );
        dstStr[i]=pos_to_char(tempChr);
    }
    if (l1> l3){
        for (i = l3; i < l1; i++){
            dstStr[i]=S1[i];
        }    
        dstStr[l1]='\0';  
    }else{
        for (i = l3; i < l2; i++){
            dstStr[i]=S2[i];
        }
        dstStr[l2]='\0';  
    }
    //printf("\nMult Result Strings: %s\n",dstStr);
    return;
}

//=============================================
// Function to convert a character to its position in the alphabet
int char_to_pos(char a){
    //printf("%c ", a);
    if((96 < (int) a) && ((int)a < 123) ){ 
        return (a-'a');
    }else{
        printf("invlaid character to convert\n");    
        return -1;
   }
}
//=============================================
// Function to convert a position in the alphabet to a character
char pos_to_char(int n){
    //printf("%d ", n);
    if((0 <= n) && (n< 26)){
        return (char)('a'+n);
    } else{
        printf("invlaid integer to convert to char\n");    
        return '\0';
    }
}


//=============================================
int main(){
    StringMatrix A, B, C;
    char inputFileNameA[] = "input_0303_a.txt";
    char inputFileNameB[] = "input_0303_b.txt";
    A = read_string_matrix_from_file(inputFileNameA);
    B = read_string_matrix_from_file(inputFileNameB);
    show_string_matrix(A);
    show_string_matrix(B);
    
    C = multiply_string_matrices(A, B);
    show_string_matrix(C);
    
    free_string_matrix(A);
    free_string_matrix(B);
    free_string_matrix(C);
}


