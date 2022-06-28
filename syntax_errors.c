#include <stdio.h>

#define IN 1
#define OUT 0

int main(){
        int c, prev, state = OUT;
        int error, quote, d_quote, comm, long_comm, braces, brackets, par;
        error = quote = d_quote = comm = long_comm = braces = brackets = par = 0;

        while ((c = getchar()) != EOF){
                if (state == OUT){
                        if (c == '{')
                                ++braces;
                        if (c == '}')
                                --braces;
                        if (c == '(')
                                ++par;
                        if (c == ')')
                                --par;
                        if (c == '[')
                                ++brackets;
                        if (c == ']')
                                --brackets;
                        if (c == '\''){
                                state = IN;
                                ++quote;
                        }
                        if (c == '"'){
                                state = IN;
                                ++d_quote;
                        }
                        if (c == '/' && prev == '/'){
                                state = IN;
                                ++comm;
                        }
                        if (c == '*' && prev == '/'){
                                state = IN;
                                ++long_comm;
                        }
                } else {
                        if (comm > 0 && c == '\n'){
                                --comm;
                                state = OUT;
                        }
                        if (long_comm > 0 && prev == '*' && c == '/'){
                                --long_comm;
                                state = OUT;
                        }
                        if (quote > 0 && c == '\''){
                                --quote;
                                state = OUT;
                        }
                        if (d_quote > 0 && c == '"'){
                                --d_quote;
                                state = OUT;
                        }
                }
                prev = c;
        }
        if (braces == 0 && par == 0 && brackets == 0 && error == 0)
                printf("No errors\n");
        else if (error == 1)
                printf("Found closing character first\n");
        else
                printf("Missing: braces: %d parenthesis: %d brackets: %d\n", braces, par, brackets);
}
