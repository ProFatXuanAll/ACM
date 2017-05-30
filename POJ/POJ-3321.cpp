#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAX_N (100000)

static int N, M;
static int idxL[MAX_N];
static int idxR[MAX_N];
static vector<vector<int>>g(MAX_N);
static bool pick[MAX_N];
static int bit[MAX_N+10];

static void dfs(int u, int p); 
static void add(int idx, int x); 
static int sum(int idx);

int main() 
{
    scanf("%d", &N);
    
	for (int i=0;i<N-1;i++) 
	{
        int u, v;
		scanf("%d %d",&u,&v);
        u--; 
		v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0,-1);

    for(int v=0;v<N;v++) 
	{
        add(idxL[v],1);
        pick[v]=false;
    }

    scanf("%d",&M);

    while(M--) 
	{
        char cmd[2];
		int u;
        scanf("%s %d",cmd,&u);
        u--;

        if(cmd[0]=='C') 
		{
            if(pick[u])
                add(idxL[u],1);
            else
                add(idxL[u],-1);
            pick[u]=!pick[u];
        }
        else 
		{
            int cnt=sum(idxR[u]-1)-sum(idxL[u]-1);
            printf("%d\n",cnt);
        }
    }

    return 0;
}

static int sum(int idx) 
{
    int s=0;
   
   	for (int i=idx;i>0;i-=(i & -i))
        s+=bit[i];
   
   	return s;
}

static void add(int idx, int x) 
{
    for(int i=idx;i<=N;i+=(i&-i))
        bit[i]+=x;
}

static int dfn = 1;
static void dfs(int u, int p) 
{
    idxL[u]=dfn++;
    int sz=g[u].size();
    
	for(int i=0;i<sz;i++) 
	{
        int v=g[u][i];

        if(v==p)
			continue;
        else
			dfs(v,u);
    }
    
	idxR[u]=dfn;
}
