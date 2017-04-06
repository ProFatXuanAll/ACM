#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int Scenario, m, n;
	scanf("%d",&Scenario);
	
	for(int i=1;i<=Scenario;i++){
		scanf("%d%d",&m,&n);
		
		if((m*n)%2)
			printf("Scenario #%d:\n%.2f\n\n",i,(float)m*n-1+sqrt((float)2));
		else
			printf("Scenario #%d:\n%.2f\n\n",i,(float)m*n);
	}
	
	return 0;
}
