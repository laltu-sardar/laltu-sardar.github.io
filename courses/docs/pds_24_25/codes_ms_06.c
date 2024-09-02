#include <stdio.h>
#include <string.h>
int convert(char * inpStr){
    int n = strlen(inpStr);
    int res = 0;
    int c;
    for (int i = 0; i < n; i++) {
        c =  inpStr[n-i-1]-'0';
        c = c<<i;
        res = res | c;
    }

    return res;
}

int substring_search(char * str1, char * str2){
    int n = strlen(str1);
    int m  = strlen(str2);

    for (int i = 0; i < n; i++) {
        if (str1[i] == str2[0]){
            int flag = 0;
            for (int j = 1; (j < m) && (i+j < n) ; j++) {
                if (str1[i+j]  != str2[j]){
                    flag = 1;
                    break;
                }
            }
            if (flag==0) {
                printf("Found\n" );
            }
        }

    }


    return 0;
}



int main(int argc, char const *argv[]) {
    int s = sizeof(int) +1;
    char inpStr[s];

    scanf("%s", inpStr);

    char str1[] = "ABABACRESTB";

    //int result = convert(inpStr);

    int result = substring_search(str1, inpStr);

    printf("%d\n", result);
    return 0;
}
