#include <cstdio>
#include <cstdlib>

#define SIZE (8)
#define DIM (8)

using namespace std;

static bool map[DIM][DIM]={false};

struct Stack{
	int row[SIZE];
	int col[SIZE];
	int top;
	Stack(){
		top=0;
	}
	void push(int r,int c){
		if(!isFull()){
			row[top]=r;
			col[top]=c;
			top++;
		}
		else{
			printf("[error]: stack is full.\n");
			exit(EXIT_FAILURE);
		}
	}
	void pop(int& r, int& c){
		if(!isEmpty()){
			top--;
			r=row[top];
			c=col[top];
		}
		else{
			printf("[error]: stack is empty.\n");
			exit(EXIT_FAILURE);
		}
	}
	bool isFull(){
		return top==SIZE;
	}
	bool isEmpty(){
		return top==0;
	}
};

static struct Stack record[92];
static struct Stack s;
static int counter=0;
static int value[DIM][DIM];

void Queen(int index,int dim);
bool QCR(int r,int c);
bool QCC(int r,int c);
bool QCD(int r,int c);

int main(void)
{
	int i, j, k, l, r, c, max, tmp;

	Queen(0,0);
	scanf("%d",&k);

	while(k--){
		for(i=0;i<DIM;i++){
			for(j=0;j<DIM;j++){
				scanf("%d",&value[i][j]);
			}
		}
		max=0;
		
		for(l=0;l<92;l++){
			tmp=0;
			for(i=0;i<DIM;i++){
				tmp+=value[record[l].row[i]][record[l].col[i]];
			}
			if(max<tmp){
				max=tmp;
			}
		}
		printf("%5d\n",max);
	}

	return 0;
}

void Queen(int index,int dim){
	int r;
	int c;
	int i;

	if(dim==DIM){
		record[counter++]=s;
		return;
	}
	else{
		for(i=index>0?index+1:0;i<DIM*DIM;i++){
			r=i/DIM;
			c=i-r*DIM;
			if(QCR(r,c)&&QCC(r,c)&&QCD(r,c)){
				map[r][c]=true;
				s.push(r,c);
				Queen(i,dim+1);
				s.pop(r,c);
				map[r][c]=false;
			}
		}
	}
}

bool QCR(int r,int c){
	int i;
	for(i=0;i<DIM;i++){
		if(map[r][i]==true){
			return false;
		}
	}
	return true;
}

bool QCC(int r,int c){
	int i;
	for(i=0;i<DIM;i++){
		if(map[i][c]==true){
			return false;
		}
	}
	return true;
}

bool QCD(int r,int c){
	int i;
	for(i=0;i<DIM;i++){
		if(r-i>=0&&c-i>=0){
			if(map[r-i][c-i]==true){
				return false;
			}
		}
		else{
			break;
		}
	}
	for(i=0;i<DIM;i++){
		if(r-i>=0&&c+i<DIM){
			if(map[r-i][c+i]==true){
				return false;
			}
		}
		else{
			break;
		}
	}
	for(i=0;i<DIM;i++){
		if(r+i<DIM&&c+i<DIM){
			if(map[r+i][c+i]==true){
				return false;
			}
		}
		else{
			break;
		}
	}
	for(i=0;i<DIM;i++){
		if(r+i<DIM&&c-i>=0){
			if(map[r+i][c-i]==true){
				return false;
			}
		}
		else{
			break;
		}
	}
	return true;
}
