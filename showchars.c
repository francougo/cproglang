#include <stdio.h>

int main(){
        char e;
        for (int c = 0; (c = getchar()) != EOF; e = 'a'){
                if (c == '\t'){
                        c = 't';
                        e = '\\';
                }
                if (c == '\b'){
                        c = 'b';
                        e = '\\';
                }
                if (c == '\\'){
                        c = '\\';
                        e = '\\';
                }
                if (e == '\\')
                        putchar(e);
                putchar(c);
        }
}
