#include <stdio.h>
using namespace std;
 
int main(){
        int n, step = 1, x, y, startPoint,count = 0;
        printf("Insert size of the matrix: \n");
        scanf("%d", &n);
 
        int a[n][n];
        for (int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
//                      scanf("%d", &a[i][j]);
                        a[i][j] = (i+1)*10 + j+1;
                }
        }
 
        if (n % 2 == 1) startPoint = n/2;
        else startPoint = n/2 - 1;
        x = startPoint; y = startPoint;
        printf("%d", a[x][y]);
 
        while (1){
                for (int i = 0; i < step; i++){
                        if (count == n*n-1) {printf("\n"); return 0;};
                        y += 1;
                        printf(" %d", a[y][x]);
                        count += 1;
                }
                for (int i = 0; i < step; i++){
                        if (count == n*n-1) {printf("\n"); return 0;};
                        x += 1;
                        printf(" %d", a[y][x]);
                        count += 1;
                }
                step += 1;
                for (int i = 0; i < step; i++){
                        if (count == n*n - 1) {printf("\n"); return 0;};
                        y -= 1;
                        printf(" %d", a[y][x]);
                        count += 1;
                }
                for (int i = 0; i < step; i++){
                        if (count == n*n - 1) {printf("\n"); return 0;};
                        x -= 1;
                        printf(" %d", a[y][x]);
                        count += 1;
                }
                step += 1;
        }
 
        for (int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
                        printf("%d", a[i][j]);
                }
        }
}
