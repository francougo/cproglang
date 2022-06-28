#include <stdio.h>

#define L_SIZE 200

int clearline(char s[]){ 
        int last = -1;
        for (int i = 0; s[i] != '\n' && s[i] != '\0'; ++i){
                if (s[i] != ' ' && s[i] != '\t')
                        last = i;
        }
        s[last + 1] = '\n';
        s[last + 2] = '\0';
        return last;
}

int get_line(char s[], int size){
        int i, c;
        for (i = 0; i < (size - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
                s[i] = c;
        if (c == '\n'){
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}
int main(){
        int line[L_SIZE];
        int size = L_SIZE;
        int len;

        while ( (len = get_line(line, size)) > 0){
                clearline(line);
                printf("%s", line);
        }
}

