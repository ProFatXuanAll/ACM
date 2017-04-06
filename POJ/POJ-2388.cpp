#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N, cow[10000];
	
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
		scanf("%d",&cow[i]);
		
	sort(cow,cow+N);
	
	printf("%d",cow[N/2]);
	
	return 0;
}
