#include <cstdio>
#include <cstdlib>

using namespace std;
#define MAX (1000+1)

struct distance{
	int dis[MAX];
	int to[MAX];
	int node;
	int sssp;
};

static struct distance d[MAX];

int main(){
    int T, N;
    int from, to;

	for(int i=1;i<MAX;i++){
		d[i].node=0;
		d[i].sssp=-1;
	}

    scanf("%d%d",&T,&N);

    for(int i=0;i<T;i++){
		scanf("%d%d",&from,&to);
		d[from].to[d[from].node]=to;
		d[to].to[d[to].node]=from;
		scanf("%d",&d[from].dis[d[from].node]);
		d[to].dis[d[to].node]=d[from].dis[d[from].node];
		d[from].node++;
		d[to].node++;
    }
	d[N].sssp=0;

/*	for(int i=1;i<=N;i++){
		for(int j=0;j<d[i].node;j++){
			printf("%d %d %d\n",i,d[i].to[j],d[i].dis[j]);
		}
	}*/

	for(int i=0;i<N-1;i++){
		for(int j=1;j<=N;j++){
			for(int k=0;k<d[j].node;k++){
				if(d[j].sssp!=-1){
					if(d[d[j].to[k]].sssp!=-1&&d[j].sssp+d[j].dis[k]<d[d[j].to[k]].sssp){ // relax
						d[d[j].to[k]].sssp=d[j].sssp+d[j].dis[k];
					}
					else if(d[d[j].to[k]].sssp==-1){
						d[d[j].to[k]].sssp=d[j].sssp+d[j].dis[k];
					}
				}
			}
		}
	}
/*
	for(int i=1;i<=N;i++){
		for(int j=0;j<d[i].node;j++){
			printf("%d %d %d %d\n",i,d[i].to[j],d[i].dis[j],d[i].sssp);
		}
	}*/
	printf("%d",d[1].sssp);

    return 0;
}
