#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

#define MAX_F (5)
#define MAX_N (500)
#define MAX_M (2500)
#define MAX_W (200)
#define MAX_T (10000)

struct graph{
	int to[MAX_M+MAX_W+1];
	int dis[MAX_M+MAX_W+1];
	int count;
	int sssp;
};

static struct graph G[MAX_N+1];

static void init(int n);
static bool BellmanFord(int n);

int main(void)
{
	int F, N, M, W;
	int S, E, T;

	scanf("%d",&F);
	while(F--){
		scanf("%d%d%d",&N,&M,&W);
		
		init(N);
		for(int i=0;i<M;i++){
			scanf("%d%d%d",&S,&E,&T);
			G[S].to[G[S].count]=E;
			G[S].dis[G[S].count]=T;
			G[S].count++;
			G[E].to[G[E].count]=S;
			G[E].dis[G[E].count]=T;
			G[E].count++;
		}
		for(int i=0;i<W;i++){
			scanf("%d%d%d",&S,&E,&T);
			G[S].to[G[S].count]=E;
			G[S].dis[G[S].count]=-1*T;
			G[S].count++;
		}

		if(BellmanFord(N)){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}

	return 0;
}

static void init(int n)
{
	for(int i=1;i<=n;i++){
		G[i].count=0;
		G[i].sssp=MAX_T;
	}
	G[1].sssp=0;
}

static bool BellmanFord(int n)
{
	for(int i=0;i<n-1;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<G[j].count;k++){
				if(G[j].sssp+G[j].dis[k]<G[G[j].to[k]].sssp){
					G[G[j].to[k]].sssp=G[j].sssp+G[j].dis[k];
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<G[i].count;j++){
			if(G[i].sssp+G[i].dis[j]<G[G[i].to[j]].sssp){
				return false;
			}
		}
	}
	return true;
}
