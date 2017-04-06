#include <cstdio>
#include <algorithm>

using namespace std;


#define MAX (13)
#define DIM (6)

static void p(int dim);
static int arr[DIM];
static int k;
static int S[MAX];


int main(void){
	int i;
	bool start=false;

	while(1){
		scanf("%d",&k);
		if(k==0){
			break;
		}
		
		if(start){
			puts("");
		}

		for(i=0;i<k;i++){
			scanf("%d",&S[i]);
		}

		sort(S,S+k);

		p(0);
		start=true;
	}
	return 0;
}

static void p(int dim)
{
	int i;
	if(dim>=DIM){
		for(i=0;i<DIM-1;i++){
			printf("%d ",S[arr[i]]);
		}
		printf("%d\n",S[arr[DIM-1]]);
		return;
	}
	else if(dim<DIM){
		for(i=(dim>0?arr[dim-1]+1:dim);i<k-(DIM-dim-1);i++){
			arr[dim]=i;
			p(dim+1);
		}
	}
}
