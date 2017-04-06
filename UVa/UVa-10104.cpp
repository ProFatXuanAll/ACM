#include <cstdio>

using namespace std;

static int GCD(int a, int b, int& x, int& y);

int main(void)
{
	int X, Y, A, B, gcd;

	while(scanf("%d%d",&A,&B)!=EOF){
		
		gcd=GCD(A,B,X,Y);
		
		printf("%d %d %d\n",X,Y,gcd);
	}

	return 0;
}

static int GCD(int a, int b, int&x, int& y)
{
	int tmpgcd, tmpx;

	if(b==0){
		x=1;
		y=0;
		return a;
	}
	else{
		tmpgcd=GCD(b,a%b,x,y);
		tmpx=x;
		x=y;
		y=tmpx-y*(a/b);
		return tmpgcd;
	}
}
