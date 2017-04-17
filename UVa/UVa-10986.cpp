#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <queue>

using namespace std;

#define MAX_N (20000)
#define MAX_M (50000)
#define MAX_T (99999999)

struct graph{
	int y[MAX_N];
	int t[MAX_N];
	int count;
	int sssp;
};

static struct graph G[MAX_N];

static void init(int n);
static void SPFA(int S,int n);

int main(void)
{
	int N, n, m, S, T;
	int from, to, time;

	scanf("%d",&N);
	for(int j=1;j<=N;j++){
		scanf("%d%d%d%d",&n,&m,&S,&T);
		
		init(n);
		
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&from,&to,&time);
			G[from].y[G[from].count]=to;
			G[from].t[G[from].count]=time;
			G[from].count++;
			G[to].y[G[to].count]=from;
			G[to].t[G[to].count]=time;
			G[to].count++;
		}
		G[S].sssp=0;
		SPFA(S,n);
		if(G[T].sssp==MAX_T){
			printf("Case #%d: unreachable\n",j);
		}
		else{
			printf("Case #%d: %d\n",j,G[T].sssp);
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
}

static void SPFA(int S,int n)
{
	queue<int> q;
	bool inq[n];

	q.push(S);
	memset(inq,false,sizeof(bool)*n);

	while(!q.empty()){
		int cur=q.front();
		inq[cur]=false;
		q.pop();
		for(int i=0;i<G[cur].count;i++){
			if(G[cur].sssp+G[cur].t[i]<G[G[cur].y[i]].sssp){
				G[G[cur].y[i]].sssp=G[cur].sssp+G[cur].t[i];
				if(!inq[G[cur].y[i]]){
					q.push(G[cur].y[i]);
					inq[G[cur].y[i]]=true;
				}
			}
		}
	}
}
