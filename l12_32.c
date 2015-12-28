#include <stdio.h>
 
int main()
{
  int n, c, k,zero=0,one=0,l=32;
 while(scanf("%d",&n) != EOF){
 
  for (c = 31; c >= 0; c--)
  {
    k = n >> c;
 
    if (k & 1){printf("1");one++;l--;}
    else{printf("0");zero++;l--;}
  }
  zero+=l; 
  printf("\n Нули:%d Единицы:%d \n",zero,one);
  if(zero==one){printf("Число единиц и нулей равно \n");}
  else{printf("Число единиц и нулей не равно \n");}
  
  l=32;zero=0;one=0;
 }
  return 0;
}
