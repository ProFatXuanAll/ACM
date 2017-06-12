#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

#define MAX (100000)

struct Point
{
	int x;
	int y;
	bool operator <(Point in)
	{
		if(x==in.x)
			return y<in.y;
		return x<in.x;
	}
	bool operator ==(Point in)
	{
		return x==in.x&&y==in.y;
	}
};

static int cross(Point o,Point a,Point b);
static int Andrew_Montone(void);

static int n=0;
static Point poly[MAX];
static Point origin[MAX];
static Point chain[MAX];

int main(void)
{
	stringstream ss;
	string str;
	const string blank="";
	char comma;
	int count;
	bool flag=false;

	while(getline(cin,str))
	{
		if(str==blank)
		{
			count=Andrew_Montone();

			int start_ptr;

			for(int i=0;i<n;++i)
			{
				for(int j=0;j<count;++j)
				{
					if(chain[j]==origin[i])
					{
						start_ptr=j;
						i+=n;
						break;
					}
				}
			}

			for(int i=0;i<count;++i)
			{
				printf("%d, %d\n",chain[(i+start_ptr)%count].x,chain[(i+start_ptr)%count].y);
			}
			printf("%d, %d\n\n",chain[start_ptr].x,chain[start_ptr].y);

			n=0;
			flag=false;
		}
		else
		{
			ss << str;
			ss >> poly[n].x >> comma >> poly[n].y;
			origin[n]=poly[n];
			ss.clear();
			++n;
			flag=true;
		}
	}

	if(flag)
	{
			count=Andrew_Montone();

			int start_ptr;

			for(int i=0;i<n;++i)
			{
				for(int j=0;j<count;++j)
				{
					if(chain[j]==origin[i])
					{
						start_ptr=j;
						i+=n;
						break;
					}
				}
			}

			for(int i=0;i<count;++i)
			{
				printf("%d, %d\n",chain[(i+start_ptr)%count].x,chain[(i+start_ptr)%count].y);
			}
			printf("%d, %d\n",chain[start_ptr].x,chain[start_ptr].y);
	}
	
	return 0;
}

static int cross(Point o,Point a,Point b)
{
	return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);
}

static int Andrew_Montone(void)
{
	int m=0;

	sort(poly,poly+n);

	for(int i=0;i<n;++i)
	{
		while(m>=2 && cross(chain[m-2], chain[m-1], poly[i]) <= 0)
			m--;

		chain[m++] = poly[i];
	}

	for(int i=n-2, t=m+1;i>=0;--i)
	{
		while(m>=t && cross(chain[m-2], chain[m-1], poly[i]) <= 0)
			m--;

		chain[m++] = poly[i];
	}

	m--;

	return m;
}
