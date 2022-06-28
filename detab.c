#include <stdio.h>

#define N 8

int main(){
        int c;
        int pos = 0;
        while ((c = getchar()) != EOF){
                if (c == '\t'){
                        for (int i = 0; i< N - pos; ++i)
                                putchar(' ');
                        pos = 0;
                } else {
                        putchar(c);
                        if (c == '\n')
                                pos = 0;
                        else
                                pos = (pos + 1) % N;
                }
        }
}

