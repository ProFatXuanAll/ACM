#include <iostream>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

class POINT {
public:
	int x, y;
	bool operator< ( const POINT r ) const {
		return ( x < r.x ) || ( x == r.x && y < r.y );
	}
	bool operator== ( const POINT r ) const {
		return x == r.x && y == r.y;
	}
};

POINT p[1000], mid[1000000];

int main()
{
	int t;
	scanf("%d",&t);
	
	for(int i=0;i<t;i++){
		int n;
		scanf("%d",&n);
		
		for(int j=0;j<n;j++)
			scanf("%d%d",&p[j].x,&p[j].y);
		
		int m=0;
		for(int j=0;j<n;j++)
			for(int k=j+1;k<n;k++){
				mid[m].x = p[j].x + p[k].x;
				mid[m].y = p[j].y + p[k].y;
				m++;
			}

		sort(mid,mid+m);
		
		int count=1, result=0;
		for(int j=0;j<m;j++){
			if(mid[j-1] == mid[j])
				count++;
			else if(count>1){
				result+= count*(count-1)/2;
				count=1;
			}
		}
		
		printf("%d\n",result);
	}
	
	return 0;
}
