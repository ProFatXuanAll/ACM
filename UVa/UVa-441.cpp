#include <cstdio>
#include <algorithm>

using namespace std;
#define MAX (12)
#define DIM (6)

static int k;
static int S[MAX];
static int arr[DIM];

void p(int dim);

int main(void)
{
	int i;

	while(1){
		scanf("%d",&k);
		if(!k){
			break;
		}

		for(i=0;i<k;i++){
			scanf("%d",&S[i]);
		}

		sort(S+1,S+k+1);

		p(0);
	}
	return 0;
}

void p(int dim)
{
	int i;
	
	if(dim==DIM){
		for(i=0;i<6;i++){
			printf("%d ",S[arr[i]]);
		}
		puts("");
		return;
	}
	for(i=(dim==0?0:arr[dim-1]+1);i<k-(DIM-dim-1);i++){
		arr[dim]=i;
		p(dim+1);
	}
}
