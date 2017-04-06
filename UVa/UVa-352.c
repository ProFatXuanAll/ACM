#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAX_DIM	25

static int dim;	/*	dimension	*/
static char image[MAX_DIM+2][MAX_DIM+2];	/*	adjacency matrix	*/
static int image_num=0;	/*	image number counter	*/
static int eagle;	/*	eagle's number	*/
static void DFS(int x, int y);	/*	depth first search	*/

int main(void)
{
	int i, j;	/*	loop counter	*/
	
	while(scanf("%d",&dim)!=EOF){	/*	main while loop	*/

		image_num++;	/* increment image number	*/
		eagle=0;	/*	initialize eagle's number	*/
		
		for(j=0;j<dim+2;j++){	/*	set border	*/
			image[0][j]='x';
			image[dim+1][j]='x';
		}	/*	end set border	*/

		for(i=1;i<=dim;i++){	/*	get image	*/
			for(j=1;j<=dim;j++){
				scanf(" %c",&image[i][j]);
			}
			image[i][dim+1]='x';	/*	set border	*/
			image[i][0]='x';	/*	set border	*/
		}	/*	end get image	*/
	
		for(i=1;i<=dim;i++){	/*	count eagle	*/
			for(j=1;j<=dim;j++){
				if(image[i][j]=='1'){
					DFS(i,j);
					eagle++;
				}
			}
		}	/*	end count eagle	*/

		printf("Image number %d contains %d war eagles.\n",image_num,eagle);

	}	/*	end while loop	*/

	return 0;
}

static void DFS(int x, int y)
{
	image[x][y]='c';	/*	set byte to check state	*/
	if(image[x][y+1]=='1'){	/*	go right	*/
		DFS(x,y+1);
	}
	if(image[x-1][y+1]=='1'){	/*	go up right	*/
		DFS(x-1,y+1);
	}
	if(image[x-1][y]=='1'){	/*	go up	*/
		DFS(x-1,y);
	}
	if(image[x-1][y-1]=='1'){	/*	go up left	*/
		DFS(x-1,y-1);
	}
	if(image[x][y-1]=='1'){	/*	go left	*/
		DFS(x,y-1);
	}
	if(image[x+1][y-1]=='1'){	/*	go down left	*/
		DFS(x+1,y-1);
	}
	if(image[x+1][y]=='1'){	/*	go down	*/
		DFS(x+1,y);
	}
	if(image[x+1][y+1]=='1'){	/* go down right	*/
		DFS(x+1,y+1);
	}
	return;
}	/*	end function DFS	*/
