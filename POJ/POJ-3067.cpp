#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX (1000*1000)

struct HighWay{
	int e;
	int w;
	bool operator < (const struct HighWay & in)const{
		return e==in.e?w<in.w:e<in.e;
	}
	bool operator << (const struct HighWay & in)const{
		return e<in.e&&w>in.w;
	}
};

static struct HighWay h[MAX];
static struct HighWay tmp[MAX];

static int N,M,K,T;
static long long int knots;

static void MergeSort(int l, int r);

int main(void)
{
	int i,j;

	scanf("%d",&T);

	for(i=1;i<=T;i++){
		scanf("%d%d%d",&N,&M,&K);
		for(j=0;j<K;j++){
			scanf("%d%d",&h[j].e,&h[j].w);
		}

		sort(h,h+K);
		knots=0;
		MergeSort(0,K-1);
		printf("Test case %d: %lld\n",i,knots);
	}

	return 0;
}

static void MergeSort(int l,int r)
{
	int i,j,k,mid;

	if(l<r){
		mid=(l+r)/2;
		MergeSort(l,mid);
		MergeSort(mid+1,r);

		for(i=l,j=mid+1,k=0;k<r-l+1;k++){
			if(i>mid){
				tmp[k]=h[j++];
			}
			else if(j>r){
				tmp[k]=h[i++];
			}
			else if(h[i]<<h[j]){
				knots+=mid-i+1;
				tmp[k]=h[j++];
			}
			else{
				tmp[k]=h[i++];
			}
		}

		for(i=l,k=0;k<r-l+1;k++){
			h[i++]=tmp[k];
		}
	}
}
