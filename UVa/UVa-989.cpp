#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX (3)

using namespace std;

static int map[MAX*MAX][MAX*MAX];
static int n;

static void sudoku(int dim,bool& flag);
bool checkrow(int row, int num);
bool checkcol(int col, int num);
bool checkblock(int row, int col, int num);

int main(void)
{
	bool flag;
	bool first=true;

	while(scanf("%d",&n)!=EOF){
		if(!first){
			puts("");
		}

		for(int row=0;row<n*n;row++){
			for(int col=0;col<n*n;col++){
				scanf("%d",&map[row][col]);
			}
		}
		
		flag=false;

		sudoku(0,flag);

		if(flag){
			for(int row=0;row<n*n;row++){
				for(int col=0;col<n*n-1;col++){
					printf("%d ",map[row][col]);
				}
				printf("%d\n",map[row][n*n-1]);
			}
		}
		else{
			printf("NO SOLUTION\n");
		}
		first=false;
	}

	return 0;
}

static void sudoku(int dim,bool& flag){
	int row, col;
	bool find_zero=false;
	if(!flag){
		for(int i=dim;i<n*n*n*n;i++){
			row=i/(n*n);
			col=i%(n*n);
			if(map[row][col]!=0){
				continue;
			}
			find_zero=true;
			for(int j=1;j<=n*n;j++){
				if(checkrow(col,j)&&checkcol(row,j)&&checkblock(row,col,j)){
					map[row][col]=j;
					sudoku(i+1,flag);
					if(flag){
						return;
					}
					map[row][col]=0;
				}
			}
			return;
		}
		if(!find_zero){
			flag=true;
		}
	}
	else{
		return;
	}
}

bool checkrow(int col, int num){
	for(int i=0;i<n*n;i++){
		if(map[i][col]==num){
			return false;
		}
	}
	return true;
}

bool checkcol(int row, int num){
	for(int i=0;i<n*n;i++){
		if(map[row][i]==num){
			return false;
		}
	}
	return true;
}

bool checkblock(int row, int col, int num){
	for(int i=row-row%n;i<row-row%n+n;i++){
		for(int j=col-col%n;j<col-col%n+n;j++){
			if(map[i][j]==num){
				return false;
			}
		}
	}
	return true;
}
