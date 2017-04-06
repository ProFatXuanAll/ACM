#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define MAX (10000)
using namespace std;

int main()
{
	int N, i, j, cow[MAX];
	long long int Total=0;

	scanf("%d",&N);

	for(i=0;i<N;i++){
		scanf("%d",&cow[i]);
	}

	sort(cow,cow+N);

	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			Total+=cow[j]-cow[i];
		}
	}

	printf("%lld",2*Total);

	return 0;
}
