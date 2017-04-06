#include <stdio.h>

static int gcd(int a,int b);

int main(void)
{
	int a,b;

	while(scanf("%d",&a)!=EOF)
	{
		scanf("%d",&b);
		if(gcd(a,b)==1){
			printf("%10d%10d    Good Choice\n",a,b);
		}
		else{
			printf("%10d%10d    Bad Choice\n",a,b);
		}
		puts("");
	}

	return 0;
}

static int gcd(int a,int b)
{
	if(a%b==0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}
}
