#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 101


int main()
{
    FILE *fp;
	char temp, line[BUFFER_SIZE];
	int lineSize, wordStart = 0, wordEnd, i, j;

    fp = fopen("sentence.txt", "r");
    if (fp == NULL)
    {
        printf("ERROR!! Can't open the file.\n");
        exit(1);
    }

    fgets(line, BUFFER_SIZE, fp);
    fclose(fp);

    printf("The input line is: \n");
    printf("%s", line);

    lineSize = strlen(line) - 1;
    for(i = 0; i < lineSize/2; i++)
    {
        temp = line[i];
        line[i] = line[lineSize - 1 - i];
        line[lineSize - 1 - i] = temp;
    }

    for(i = 0; i < lineSize; i++)
    {
        if(line[i] == ' ')
        {
            wordEnd = i - 1;
            while(wordStart < wordEnd)
            {
                temp = line[wordStart];
                line[wordStart] = line[wordEnd];
                line[wordEnd] = temp;
                wordStart++;
                wordEnd--;
            }
            wordStart = i + 1;
        }
    }

    printf("The output is: \n");
    printf("%s", line);

    return 0;
}
