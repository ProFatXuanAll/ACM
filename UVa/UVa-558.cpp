#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

#define MAX_V (1000)
#define MAX_W (2000)
#define MAX_T (INT_MAX/2)

struct graph{
	int y[MAX_W];
	int t[MAX_W];
	int count;
	int sssp;
};

static struct graph G[MAX_V];

static void init(int n);
static bool BellmanFord(int n);

int main(void)
{
	int c, m, n;
	int x, y, t;

	scanf("%d",&c);
	while(c--){
		scanf("%d%d",&n,&m);
		init(n);
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&t);
			G[x].y[G[x].count]=y;
			G[x].t[G[x].count]=t;
			G[x].count++;
		}

		if(BellmanFord(n)){
			printf("not possible\n");
		}
		else{
			printf("possible\n");
		}
	}

	return 0;
}

static void init(int n)
{
	for(int i=0;i<n;i++){
		G[i].count=0;
		G[i].sssp=MAX_T;
	}
	G[0].sssp=0;
}

static bool BellmanFord(int n)
{
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<G[j].count;k++){
				if(G[j].sssp+G[j].t[k]<G[G[j].y[k]].sssp){
					G[G[j].y[k]].sssp=G[j].sssp+G[j].t[k];
					//printf("update: %d[%d]~ %d ~>%d[%d]\n",j,G[j].sssp,G[j].t[k],G[j].y[k],G[G[j].y[j]].sssp);
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<G[i].count;j++){
			if(G[i].sssp+G[i].t[j]<G[G[i].y[j]].sssp){
				return false;
			}
		}
	}
	return true;
}
