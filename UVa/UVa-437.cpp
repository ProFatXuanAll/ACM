#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX (30)

struct block{
	int x;
	int y;
	int z;
	bool operator < (struct block& in){
		return x>in.x ? true: x==in.x? y>in.y:false;
	}
};

int main(void)
{
	int n;
	int cases=1;
	struct block b[6*MAX];
	int LIS[6*MAX];
	int max_pos;

	while(1){
		scanf("%d",&n);
		
		if(n==0){
			break;
		}

		for(int i=0;i<n*6;i+=6){
			scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].z);
			b[i+1].x=b[i].x;b[i+1].y=b[i].z;b[i+1].z=b[i].y;
			b[i+2].x=b[i].y;b[i+2].y=b[i].x;b[i+2].z=b[i].z;
			b[i+3].x=b[i].y;b[i+3].y=b[i].z;b[i+3].z=b[i].x;
			b[i+4].x=b[i].z;b[i+4].y=b[i].x;b[i+4].z=b[i].y;
			b[i+5].x=b[i].z;b[i+5].y=b[i].y;b[i+5].z=b[i].x;
		}

		sort(b,b+n*6);

		max_pos=0;
		for(int i=0;i<n*6;i++){
			LIS[i]=b[i].z;
			for(int j=0;j<i;j++){
				if(b[j].x>b[i].x&&b[j].y>b[i].y&&LIS[j]+b[i].z>LIS[i]){
					LIS[i]=LIS[j]+b[i].z;
					if(LIS[i]>LIS[max_pos]){
						max_pos=i;
					}
				}
			}
		}

		printf("Case %d: maximum height = %d\n",cases++,LIS[max_pos]);

	}

	return 0;
}
