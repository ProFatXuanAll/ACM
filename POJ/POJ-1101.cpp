#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX (75)
#define START (0)
#define UP (1)
#define DOWN (2)
#define LEFT (3)
#define RIGHT (4)
using namespace std;

static char board[MAX+2][MAX+2]={0};
static int dis[MAX+2][MAX+2]; 
static int w, h;
static int x1, y1, x2, y2;
static int min;

struct queue{
	int row[(MAX+2)*(MAX+2)];
	int col[(MAX+2)*(MAX+2)];
	int dir[(MAX+2)*(MAX+2)];
	int front;
	int rear;
	void push(int r,int c){
		row[rear]=r;
		col[rear++]=c;
	}
	void pop(int& r,int& c){
		r=row[front];
		c=col[front++];
	}
};

static struct queue q;

static void BFS(void);
static bool ismargin(int r,int c);

int main(void)
{
	char tmp;
	int round=1;
	int pairs;

	while(1){
		scanf("%d%d",&w,&h);
		
		if(w==0&&h==0){
			break;
		}

		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				scanf("%c",&board[i][j]);
				if(board[i][j]=='\n'){
					j--;
				}
			}
		}
		
		printf("Board #%d:\n",round++);
		pairs=1;

		while(1){
			scanf("%d %d %d %d",&y1,&x1,&y2,&x2);

			if(x1==0&&y1==0&&x2==0&&y2==0){
				break;
			}
			
			for(int i=0;i<=h+1;i++){
				for(int j=0;j<=w+1;j++){
					dis[i][j]=-1;
				}
			}
			dis[x1][y1]=0;
			q.front=0;
			q.rear=0;
			q.push(x1,y1);
			BFS();
			if(dis[x2][y2]!=-1){
				printf("Pair %d: %d segments.\n",pairs++,dis[x2][y2]);
			}
			else{
				printf("Pair %d: impossible.\n",pairs++);
			}
		}
		puts("");
	}

	return 0;
}

static void BFS(void){
	int r, c;
	int tmpr, tmpc;

	while(q.front!=q.rear){	// queue not empty
		q.pop(r,c);

		if(r==x2&&c==y2){
			return;
		}

		// up
		tmpr=r-1;
		tmpc=c;
		while(tmpr>=0&&tmpr<=h+1&&tmpc>=0&&tmpc<=w+1&&dis[tmpr][tmpc]<0){
			dis[tmpr][tmpc]=dis[r][c]+1;
			if(!ismargin(tmpr,tmpc)&&board[tmpr][tmpc]=='X'){
				break;
			}
			q.push(tmpr,tmpc);
			tmpr--;
		}
		// left
		tmpr=r;
		tmpc=c-1;
		while(tmpr>=0&&tmpr<=h+1&&tmpc>=0&&tmpc<=w+1&&dis[tmpr][tmpc]<0){
			dis[tmpr][tmpc]=dis[r][c]+1;
			if(!ismargin(tmpr,tmpc)&&board[tmpr][tmpc]=='X'){
				break;
			}
			q.push(tmpr,tmpc);
			tmpc--;
		}
		// down
		tmpr=r+1;
		tmpc=c;
		while(tmpr>=0&&tmpr<=h+1&&tmpc>=0&&tmpc<=w+1&&dis[tmpr][tmpc]<0){
			dis[tmpr][tmpc]=dis[r][c]+1;
			if(!ismargin(tmpr,tmpc)&&board[tmpr][tmpc]=='X'){
				break;
			}
			q.push(tmpr,tmpc);
			tmpr++;
		}
		// right
		tmpr=r;
		tmpc=c+1;
		while(tmpr>=0&&tmpr<=h+1&&tmpc>=0&&tmpc<=w+1&&dis[tmpr][tmpc]<0){
			dis[tmpr][tmpc]=dis[r][c]+1;
			if(!ismargin(tmpr,tmpc)&&board[tmpr][tmpc]=='X'){
				break;
			}
			q.push(tmpr,tmpc);
			tmpc++;
		}
	
	}
}

static bool ismargin(int r,int c){
	return r==0||c==0||r==h+1||c==w+1;
}
