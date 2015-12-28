#include <stdio.h>
int abs(int x){
	if(x>=0){return x;}
	else{return -1*x;}
}
int min(int x,int y){
	if(x<y)return x;
	else return y;
}
int max(int x,int y){
	if(x>y)return x;
	else return y;
}
int sign(int x){
	if (x>0){return 1;}
	if (x<0){return -1;}
	else{return 0;}
}
int i,j,l,k,i0=-11,j0=-6,l0=-5;
bool found=0;
int main(){
for(k=0;k<50;k++){
	if((i0>5) and (i0<15) and (j0<-5) and (j0>-15)){
		printf("Остановка на k:%d",k);
		printf(" i:%d",i0);
		printf(" j:%d",j0);
	    printf(" l:%d",l0);
		printf("\n");
		found =1;
		break;
		}
	i=(i0+j0+l0)*(k+1)%25 - i0*j0*l0*(k+2)%10 +10;
	j=min((i0+j0+l0)*(k+3)%25,i0*j0*l0*(k+4)%25)+ 10;	
	l=2*sign(l0)*abs((i0+j0+l0)*(k+5)%10 -i0*j0*l0*(k+6)%25);
	
	i0=i;
	j0=j;
	l0=l;	
}
if(found==0){printf("Точка не попала в зону");}
return 0;
} 
