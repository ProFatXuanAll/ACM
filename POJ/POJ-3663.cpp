#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N, S;
	scanf("%d%d",&N,&S);
	
	int cow[20000];
	
	for(int i=0;i<N;i++)
		scanf("%d",&cow[i]);
		
	sort(cow,cow+N);
	
	long long int pair=0;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if(cow[i]+cow[j]>S){
				break;
			}
			else pair++;
		}
	}
	
	printf("%lld",pair);
	
	return 0;
}
