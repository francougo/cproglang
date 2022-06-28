#include <stdio.h>

int main(){
        int count = 0;
        for (int c; (c = getchar()) != EOF;){
                if (c == ' ' || c == '\t' || c == '\n')
                        ++count;
        }
        printf("Whitespace count: %d\n", count);
}

