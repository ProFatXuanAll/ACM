#include <cstdio>
#include <cmath>

using namespace std;

#define swap(x,y,tmp) {	\
	(tmp)=(x);(x)=(y);(y)=(tmp);	\
}

static int p,q,r,s,t,u;
static inline float f(const float x);

int main(void)
{
	float low, mid, high, ls, ms, hs, tmps;
	bool flag;

	while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)!=EOF){
		flag=false;
		low=0.0f;
		high=1.0f;
		
		//while(low<high){
		for(int i=0;i<50;i++){
			mid=(low+high)/2;
			if(f(mid)>0){
				low=mid;
			}
			else{
				high=mid;
			}
		}

		if(fabs(f(mid))<0.0001){
			printf("%.4f\n",mid);
		}
		else{
			printf("No solution\n");
		}

	}

	return 0;
}

static inline float f(const float x){
	return p*exp((-1)*x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
