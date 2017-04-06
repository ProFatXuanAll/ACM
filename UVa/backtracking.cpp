#include <cstdio>

using namespace std;

#define MAX (5)
#define DIM (3)

static void p(int dim);
static int arr[DIM];

int main(void){
	p(0);
	return 0;
}

static void p(int dim)
{
	int i;
	if(dim>=DIM){
		for(i=0;i<DIM;i++){
			printf("%d ",arr[i]);
		}
		puts("");
		return;
	}
	else if(dim<DIM){
		for(i=(dim>0?arr[dim-1]+1:dim);i<MAX-(DIM-dim-1);i++){
			arr[dim]=i;
			p(dim+1);
		}
	}
}
