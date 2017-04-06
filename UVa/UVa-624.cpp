#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MAX (100)

static int N, num, track[MAX], cur[MAX], best[MAX], max, songs;

static void p(int dim, int sum, int top);

int main(void)
{
	while(scanf("%d",&N)!=EOF){
		scanf("%d",&num);

		for(int i=0;i<num;i++){
			scanf("%d",&track[i]);
		}

		max=0;
		songs=0;
		p(0,0,0);

		for(int i=0;i<songs;i++){
			printf("%d ",best[i]);
		}
		printf("sum:%d\n",max);
	}

	return 0;
}

static void p(int dim, int sum, int top){
	
	if(sum>max&&sum<=N){
		for(int i=0;i<top;i++){
			best[i]=cur[i];
		}
		songs=top;
		max=sum;
	}
		for(int i=dim;i<num;i++){
			if(track[i]+sum<=N){
				cur[top]=track[i];
				p(i+1,sum+track[i],top+1);
			}
		}
}
