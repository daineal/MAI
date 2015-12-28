#include <stdio.h>
using namespace std;
 
int dop(int number){
        int z1, z2, z3;
        z1 = number % 10;
        if (number / 10 != 0) z2 = (number / 10) % 10;
        if (number / 100 != 0) z3 = (number / 100) % 10;
        if (z1 > z2){
                if (z2 > z3){
                        printf("result = %d%d%d\n", z1, z2, z3);
                }
        }
        return number;
}
 
 int main(){
        int number;
        printf("Insert number: ");
        while (scanf("%d", &number) != EOF){
                if (number == -1) {
                        printf("This number is out of integer type. Please enter another number: ");
                        continue;
                }
                while(number >= 123){
                        dop(number);
                        number /= 10;
                }
                printf("Insert number: ");
        }
 }
