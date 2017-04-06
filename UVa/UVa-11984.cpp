#include <cstdio>
using namespace std;

int main()
{
	int T;
	double C, d;
	
	scanf("%d",&T);
	
	for(int i=1;i<=T;i++){
		scanf("%lf%lf",&C,&d);

		printf("Case %d: %.2f\n",i,C+d*5/9);
	}
	
	return 0;
}
