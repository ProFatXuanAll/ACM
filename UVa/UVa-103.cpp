#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_DIM (10)
#define MAX_SEQ (30)

static int k, d;

struct BOX{
	int index;
	int dim[MAX_DIM];
	bool operator < (struct BOX& in){
		for(int i=0;i<d;i++){
			if(dim[i]<in.dim[i]){
				return true;
			}
			else if(dim[i]==in.dim[i]){
				continue;
			}
			else{
				return false;
			}
		}
		return true;
	}
	bool operator [] (struct BOX& in){
		for(int i=0;i<d;i++){
			if(dim[i]<=in.dim[i])
				return false;
		}
		return true;
	}
};

static struct BOX b[MAX_SEQ];
static int LIS[MAX_SEQ];
static int trace[MAX_SEQ];
static int max_pos;

static void ButtomUp();
static void printRes(int pos);

int main(void)
{
	int ans;

	while(scanf("%d%d",&k,&d)!=EOF){
		for(int i=0;i<k;i++){
			b[i].index=i+1;
			for(int j=0;j<d;j++){
				scanf("%d",&b[i].dim[j]);
			}
			sort(b[i].dim,b[i].dim+d);
		}
		sort(b,b+k);

		ButtomUp();
		printf("%d\n",LIS[max_pos]);
		printRes(max_pos);
		puts("");
	}

	return 0;
}

static void ButtomUp()
{
	max_pos=0;
	for(int i=0;i<k;i++){
		LIS[i]=1;
		for(int j=0;j<i;j++){
			if(b[i][b[j]] && LIS[j]+1 > LIS[i]){
				LIS[i]=LIS[j]+1;
				trace[i]=j;
				if(LIS[i]>LIS[max_pos]){
					max_pos=i;
				}
			}
		}
	}
}

static void printRes(int pos){
	if(LIS[pos]!=1){
		printRes(trace[pos]);
	}
	printf("%d ",b[pos].index);
}
