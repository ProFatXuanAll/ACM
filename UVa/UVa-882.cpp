#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define INF (99999999)

static int dp[11][101][101]={0};
static bool used[11][101][101]={0};

int DFS(int k, int l, int r) 
{
    if(l == r)
		return 0;
    
	if(k == 0)  
		return INF;
    
	if(used[k][l][r])
        return dp[k][l][r];
    
	used[k][l][r] = true;
    
	int i;
    int result;
    result = INF;
    
	for(i = l+1; i <= r; i++)
        result = min(result, i+max(DFS(k-1, l, i-1),DFS(k, i, r)));
    
	return dp[k][l][r]=result;
}

int main() 
{
    int N, k, m;
    
	scanf("%d", &N);
    
	while(N--) 
	{
        scanf("%d %d", &k, &m);
        printf("%d\n", DFS(k, 0, m));
    }

    return 0;
}
