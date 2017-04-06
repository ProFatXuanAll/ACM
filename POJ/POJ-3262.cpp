#include <cstdio>
#include <iostream>

#define MAX (100000)
using namespace std;

static int N;
static long long int Ta=0, Da=0;

struct Cow{
	int T;
	int D;
	bool operator < (const struct Cow & in)const{
		return T*in.D<in.T*D;
	}
};
struct Cow c[MAX], tmp[MAX];

static void MergeSort(int l, int r);

int main(void)
{
	int i;
	
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		scanf("%d%d",&c[i].T,&c[i].D);
		Ta+=c[i].D;
	}

	MergeSort(0,N-1);

	Ta-=c[0].D;
	for(i=1;i<N;i++){
		Da+=Ta*2*c[i-1].T;
		Ta-=c[i].D;
	}

	printf("%lld",Da);

	return 0;
}

static void MergeSort(int l, int r)
{
	int i, j, k, mid;

	if(l<r){
		mid=(l+r)/2;
		MergeSort(l,mid);
		MergeSort(mid+1,r);

		for(i=l,j=mid+1,k=0;k<r-l+1;k++){
			if(i>mid){
				tmp[k]=c[j++];
			}
			else if(j>r){
				tmp[k]=c[i++];
			}
			else if(c[i]<c[j]){
				tmp[k]=c[i++];
			}
			else{
				tmp[k]=c[j++];
			}
		}

		for(i=l,k=0;k<r-l+1;k++){
			c[i++]=tmp[k];
		}
	}
}
