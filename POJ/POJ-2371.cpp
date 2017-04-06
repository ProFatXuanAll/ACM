#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
	int N, K, data[100005], query;
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++){
		scanf("%d",&data[i]);
	}
	
	sort(data+1,data+N+1);
	
	while(getchar()=='\n');
	getchar();
	getchar();
	
	scanf("%d",&K);
	
	for(int i=0;i<K;i++){
		scanf("%d",&query);
		
		printf("%d\n",data[query]);
	}
	
	return 0;
}
