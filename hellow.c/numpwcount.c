#include<stdio.h>

int gyum(int n,int m);

int main(){ 
	int n,m,s;
    printf("사용할숫자 갯수 : ");
    scanf("%d",&n);
	printf("비밀번호 길이 : ");
    scanf("%d",&m);
	s = gyum(n,m);
	printf("총 경우의 수 : %d",s);
    return 0;
}

int gyum(int n, int m){
	int i,s=1;
	for(i=1;i<=m;i++){
		s *= n;
	}
	return s;
}