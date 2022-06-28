#include <stdio.h>

#define OUT 0
#define IN 1

// Histogram of lenghts of words

int main(){
        int lengths[50];
        int state = OUT, count = 0;
        for (int i = 0; i<50;++i)
                lengths[i] = 0;

        for (int c; (c = getchar()) != EOF;){
                if (!(c == ' ' || c == '\t' || c == '\n')){
                        state = IN;
                        ++count;
                } else {
                        if (state == IN){
                                ++lengths[count];
                                count = 0;
                        }
                }
        }
        if (count > 0)
                ++lengths[count];

        for (int j = 0; j<50; ++j){
                if (lengths[j] > 0){
                        printf("%d ", j);
                        for (int k = 0; k<lengths[j]; ++k){
                                printf("|");
                        }
                        printf("\n");
                }
        }
}
