#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

#define MAX (76+1)


int main(void)
{
	int n;
	int dp[MAX]={0};

	dp[1]=1;
	dp[2]=2;
	dp[3]=2;

	for(int i=4;i<=76;++i)
	{
		dp[i]=dp[i-2]+dp[i-3];
	}

	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",dp[n]);
	}

	return 0;
}
