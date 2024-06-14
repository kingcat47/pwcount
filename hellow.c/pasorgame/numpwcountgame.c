#include<stdio.h>

int gyum(int n,int m);

int main(){ 
	int n,m,s;
    printf("사용할숫자 갯수 : ");
    scanf("%d",&n);
	printf("비밀번호 길이 : ");
    scanf("%d",&m);
	s = gyum(n,m);
	printf("총 경우의 수 : %d\n",s);
	if(s>=1000000){
	    printf("보안 A급");
	}
	else if(s>100000){
	    printf("보안 B급");
	}
	if(100000>s>10000){
	    printf("보안 C급");
	}
	if(10000>s>1000){
	    printf("보안 D급");
	}
    return 0;
}

int gyum(int n, int m){
	int i,s=1;
	for(i=1;i<=m;i++){
		s *= n;
	}
	return s;
}