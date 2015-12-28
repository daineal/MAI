#include <stdio.h>
#include <ctype.h>
using namespace std;
 
int main(){
        int length = 0, number = 0;
        char ch;
        printf("Insert text: \n");
        while(ch != EOF){
                ch = getchar();
                if (isalpha(ch)) {length += 1; continue;}
                if (isspace(ch) || ch == ',') {
                        if (length >= 3) number += 1;
                        length = 0;
                }
                if (ch == '\n') {
                        printf("%d\n", number);
                        number = 0;
                        printf("Insert text: \n");
                }
        }
    return 0;
}
