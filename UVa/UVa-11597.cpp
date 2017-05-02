#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;

	for(int i=1;;++i)
	{
		scanf("%d",&n);
		if(!n)
			break;

		printf("Case %d: %d\n",i,n/2);
	}

	return 0;
}
