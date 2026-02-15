#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 10

int mystrcmp(char *, char *);


int main()
{
    FILE *fp1, *fp2;
    char line[BUFFER_SIZE], words[150][BUFFER_SIZE];
	int i, j, wordCount = 0;

    fp1 = fopen("words.txt", "r");
    if(fp1 == NULL)
    {
        printf("ERROR!! Can't open the file.\n");
        exit(1);
    }

    while(fgets(line, BUFFER_SIZE, fp1) != NULL)
    {
        strcpy(words[wordCount], line);
        wordCount++;
    }

    fclose(fp1);
/*
    printf("Input:\n");
    for(i = 0; i < wordCount; i++)
        printf("%s", words[i]);
*/
    /// sorting the words
    for(i = 0; i < wordCount - 1; i++)
        for(j = 0; j < wordCount - 1 - i; j++)
            if(mystrcmp(words[j], words[j+1]) > 0)
            {
                strcpy(line, words[j]);
                strcpy(words[j], words[j+1]);
                strcpy(words[j+1], line);
            }
/*
    printf("Output:\n");
    for(i = 0; i < wordCount; i++)
        printf("%s", words[i]);
*/
    fp2 = fopen("sorted_words.txt", "w");
    if(fp2 == NULL)
    {
        printf("ERROR!! Can't open the file.\n");
        exit(1);
    }

    for(i = 0; i < wordCount; i++)
        fputs(words[i], fp2);

    fclose(fp2);

    return 0;
}


/** mystrcmp: return < 0 if s < t,
                    0 if s = t,
                    > 0 if s > t
 */
int mystrcmp(char *s, char *t)
{
    int i;

    for(i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;

    return s[i] - t[i];
}
