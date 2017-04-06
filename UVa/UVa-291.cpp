#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define NODE (5)
#define LINE (8)

static int map[NODE+1][NODE+1]={{0,0,0,0,0,0},
						{0,0,1,1,0,1},
						{0,1,0,1,0,1},
						{0,1,1,0,1,1},
						{0,0,0,1,0,1},
						{0,1,1,1,1,0}};

static int mark[NODE+1][NODE+1] = {0};

static int route[LINE][2];

static void p(int dim,int num);

int main(void)
{
	p(0,1);

	return 0;
}

static void p(int dim,int num){
	if(dim==LINE){
		for(int i=0;i<LINE;i++){
			printf("%d",route[i][0]);
		}
		printf("%d\n",route[LINE-1][1]);
	}
	else{
		for(int i=1;i<=5;i++){
			if(map[num][i]==1&&mark[num][i]==0){
				mark[num][i]=1;
				mark[i][num]=1;
				route[dim][0]=num;
				route[dim][1]=i;
				p(dim+1,i);
				mark[num][i]=0;
				mark[i][num]=0;
			}
		}
	}
}
