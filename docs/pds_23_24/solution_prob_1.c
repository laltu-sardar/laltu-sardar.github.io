#include<stdio.h>
#include<stdlib.h>


typedef struct _matrix
                        {
                            int index;
                            int val;
                        } matrix;


int main()
{
    FILE *file1, *file2;
    matrix matL[50], matR[50], matR2[50], matRes[50];
    int i, j, n, n2, temp;
    int matrix[50][50];

    /// read matrix_a
    file1 = fopen("matrix_a.txt", "r");
    if (file1 == NULL)
    {
        printf("ERROR!! Can't open the file.\n");
        return 0;
    }

    fscanf(file1, "%d", &n);
/*
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            fscanf(file1, "%d", &matrix[i][j]);
*/
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            fscanf(file1, "%d", &temp);
            if(temp != 0)
            {
                matL[i].index = j;
                matL[i].val = temp;
            }
        }

    fclose(file1);
/*
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
*/
    printf("matL: ");
    for(i = 1; i <= n; i++)
        printf("[%d] = <%d, %d> ", i, matL[i].index, matL[i].val);
    printf("\n");

    /// read matrix_b
    file2 = fopen("matrix_b.txt", "r");
    if (file2 == NULL)
    {
        printf("ERROR!! Can't open the file.\n");
        return 0;
    }

    fscanf(file2, "%d", &n2);
/*
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            fscanf(file2, "%d", &matrix[i][j]);
*/
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            fscanf(file2, "%d", &temp);
            if(temp != 0)
            {
                matR[i].index = j;
                matR[i].val = temp;
            }
        }

    fclose(file2);
/*
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
*/
    printf("matR: ");
    for(i = 1; i <= n; i++)
        printf("[%d] = <%d, %d> ", i, matR[i].index, matR[i].val);
    printf("\n");

    for(i = 1; i <= n; i++)
    {
        matR2[matR[i].index].index = i;
        matR2[matR[i].index].val = matR[i].val;
    }

    printf("matR2: ");
    for(i = 1; i <= n; i++)
        printf("[%d] = <%d, %d> ", i, matR2[i].index, matR2[i].val);
    printf("\n");

    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            if(matL[i].index == matR2[j].index)
            {
                matRes[i].index = j;
                matRes[i].val = matL[i].val * matR2[j].val;
            }

    printf("matRes: ");
    for(i = 1; i <= n; i++)
        printf("[%d] = <%d, %d> ", i, matRes[i].index, matRes[i].val);
    printf("\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(matRes[i].index == j)
                printf("%d ", matRes[i].val);
            else
                printf("0 ");
        }
        printf("\n");
    }

    return 0;
}
