#include <cstdio>

using namespace std;

struct Pair{
	int x;
	int y;
};

static struct Pair gcd(int a, int b);
static int D;

int main(void)
{
	int X, Y, A, B;
	struct Pair tmp;

	while(scanf("%d%d",&A,&B)!=EOF){
		D=1;
		tmp=gcd(A,B);
		
		if(tmp.x<tmp.y){
			printf("%d %d %d\n",tmp.x,tmp.y,D);
		}
		else{
			printf("%d %d %d\n",tmp.y,tmp.x,D);
		}
	}

	return 0;
}

static struct Pair gcd(int a, int b)
{
	struct Pair tmp, tmp2;
	
	if(a%b==0){
		tmp.x=1;
		tmp.y=-(a/b)+1;
		D=b;
		return tmp;
	}
	else{
		tmp=gcd(b,a%b);
		tmp2.x=tmp.y;
		tmp2.y=tmp.x-tmp.y*(a/b);
		return tmp2;
	}
}
