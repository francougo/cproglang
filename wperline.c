#include <stdio.h>

#define OUT 0
#define IN 1

int main(){
        int state = OUT;
        for (int c;(c = getchar()) != EOF;){
                if (c != ' ' && c != '\t' && c != '\n')
                        state = IN;
                else if (state == IN){
                        putchar('\n');
                        state = OUT;
                }
                putchar(c);
        }
}

