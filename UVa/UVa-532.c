#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIM 30
#define MAX_DIM_CUB	((MAX_DIM)*(MAX_DIM)*(MAX_DIM))

static int L;	/* number of levels making up the dungeon */
static int R;	/* number of rows making up the plan of each level */
static int C;	/* number of columns making up the plan of each level */
static char dungeon[MAX_DIM][MAX_DIM][MAX_DIM];	/* map of dungeon */
static int distance[MAX_DIM][MAX_DIM][MAX_DIM];	/* distance of map */
static int minute;	/* minute counter */

static void BFS(void);	/* Breadth Fisrt Search */

struct Pos{
	int l;
	int r;
	int c;
};
static struct Pos queue[MAX_DIM_CUB];	/* queue for BFS */
static int front=0;	/* front of queue */
static int rear=0;	/* rear of queue */
static struct Pos data;	/* temporary data storage */
static void push(struct Pos p);	/* push into queue */
static struct Pos pop(void);	/* pop from queue */

int main(void){

	int i,j,k;	/* loop counter */
	int start_l, start_r, start_c;	/* start position */
	int end_l,end_r,end_c;	/* end position */

	while(1){
		scanf("%d%d%d",&L,&R,&C);	/* get input */

		if(L==0&&R==0&&C==0){	/* end of input */
			break;
		}
		
		minute=0;	/* initailize minute */

		for(i=0;i<L;i++){	/* initialize dungeon and distance */
			for(j=0;j<R;j++){
				for(k=0;k<C;k++){
					scanf(" %c",&dungeon[i][j][k]);	/* get input */
					
					if(dungeon[i][j][k]=='#'){	/* block */
						distance[i][j][k]=-1;
					}
					else if(dungeon[i][j][k]=='.'){	/* pass */
						distance[i][j][k]=MAX_DIM_CUB;
					}
					else if(dungeon[i][j][k]=='S'){	/* start */
						distance[i][j][k]=0;
						start_l=i;
						start_r=j;
						start_c=k;
					}
					else{	/* end */
						distance[i][j][k]=MAX_DIM_CUB;
						dungeon[i][j][k]='.';
						end_l=i;
						end_r=j;
						end_c=k;
					}
				}	/* end inner for */
			}	/* end middle for */
		}	/* end outer for */

		data.l=start_l;
		data.r=start_r;
		data.c=start_c;
		push(data);
		BFS();
		
		if(distance[end_l][end_r][end_c]==MAX_DIM_CUB){
			printf("Trapped!\n");
		}
		else{
			printf("Escaped in %d minute(s).\n",distance[end_l][end_r][end_c]);
		}

	}	/* end of while */


	return 0;
}

static void BFS(void)
{
	int l, r, c;

	while(front!=rear){	/* stop when queue is empty */
		data=pop();
		l=data.l;
		r=data.r;
		c=data.c;
		if(c+1<C){	/* east is in boundary */
			if(dungeon[l][r][c+1]=='.'&&distance[l][r][c]+1<distance[l][r][c+1]){	/* east can walk and is shorter */
				distance[l][r][c+1]=distance[l][r][c]+1;
				data.l=l;
				data.r=r;
				data.c=c+1;
				push(data);
			}
		}
		if(r-1>=0){	/* north is in boundary */
			if(dungeon[l][r-1][c]=='.'&&distance[l][r][c]+1<distance[l][r-1][c]){	/* north can walk and is shorter */
				distance[l][r-1][c]=distance[l][r][c]+1;
				data.l=l;
				data.r=r-1;
				data.c=c;
				push(data);
			}
		}
		if(c-1>=0){	/* west is in boundary */
			if(dungeon[l][r][c-1]=='.'&&distance[l][r][c]+1<distance[l][r][c-1]){	/* west can walk and is shorter */
				distance[l][r][c-1]=distance[l][r][c]+1;
				data.l=l;
				data.r=r;
				data.c=c-1;
				push(data);
			}
		}
		if(r+1<R){	/* south is in boundary */
			if(dungeon[l][r+1][c]=='.'&&distance[l][r][c]+1<distance[l][r+1][c]){	/* south can walk and is shorter */
				distance[l][r+1][c]=distance[l][r][c]+1;
				data.l=l;
				data.r=r+1;
				data.c=c;
				push(data);
			}
		}
		if(l+1<L){	/* up is in boundary */
			if(dungeon[l+1][r][c]=='.'&&distance[l][r][c]+1<distance[l+1][r][c]){	/* up can walk and is shorter */
				distance[l+1][r][c]=distance[l][r][c]+1;
				data.l=l+1;
				data.r=r;
				data.c=c;
				push(data);
			}
		}
		if(l-1>=0){	/* down is in boundary */
			if(dungeon[l-1][r][c]=='.'&&distance[l][r][c]+1<distance[l-1][r][c]){	/* down can walk and is shorter */
				distance[l-1][r][c]=distance[l][r][c]+1;
				data.l=l-1;
				data.r=r;
				data.c=c;
				push(data);
			}
		}
	}	/* end of while */
	
	return;
}	/* end function BFS */

static void push(struct Pos p)
{
	queue[front]=p;
	front= (front+1) % MAX_DIM_CUB;
}	/* end function push */

static struct Pos pop(void)
{
	struct Pos tmp = queue[rear];
	rear=(rear+1)%MAX_DIM_CUB;
	return tmp;
}	/* end function pop */
