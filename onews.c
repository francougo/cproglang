#include <stdio.h>

#define IN 1
#define OUT 0

/* if read one blank put a space and dont put anything more until c is diff than blank */

int main(){
        int state = OUT;

        for (int c; (c = getchar()) != EOF;){
                if (state == OUT){
                        if (c == ' ' || c == '\t' || c == '\n')
                                state = IN;
                        putchar(c);
                } else {
                        if (c != ' ' && c != '\t' && c != '\n'){
                                putchar(c);
                                state = OUT;
                        }
                }
        }
}
    

