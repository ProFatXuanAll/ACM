#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

#define MAX_N (100)

struct graph{
	int to[MAX_N+1];
	int count;
};

static struct graph G[MAX_N+1];
static int max_step;
static int max_V;
static void FALP(int V,int n);

int main(void)
{
	int n, s;
	int from, to;
	int count=1;

	while(1){
		scanf("%d",&n);

		if(!n){
			break;
		}

		scanf("%d",&s);

		for(int i=1;i<=n;i++){
			G[i].count=0;
		}
		max_step=0;

		while(1){
			scanf("%d%d",&from,&to);
			if(!from&&!to){
				break;
			}

			G[from].to[G[from].count]=to;
			G[from].count++;
		}

		FALP(s,n);
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",count++,s,max_step,max_V);
	}

	return 0;
}

static void FALP(int V,int n)
{
	queue<int> q;
	int step[n+1];

	q.push(V);
	memset(step+1,0,sizeof(int)*n);

	while(!q.empty()){
		int cur=q.front();
		q.pop();

		if(step[cur]>max_step){
			max_step=step[cur];
			max_V=cur;
		}
		else if(step[cur]==max_step&&max_V>cur){
			max_V=cur;
		}
		for(int i=0;i<G[cur].count;i++){
			if(step[cur]+1>step[G[cur].to[i]]){
				step[G[cur].to[i]]=step[cur]+1;
				q.push(G[cur].to[i]);
			}
		}
	}
}
