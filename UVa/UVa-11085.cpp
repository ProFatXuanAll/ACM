#include <cstdio>
#include <cstdlib>

#define SIZE (8)
#define DIM (8)
#define MAX (1000)

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
static int input[DIM];


static void Queen(int index,int dim);
static bool QCR(int r,int c);
static bool QCC(int r,int c);
static bool QCD(int r,int c);
static void sort(int index);

int main(void)
{
	int min, tmp, testcase=0;

	Queen(0,0);

	while(scanf("%d",&input[0])!=EOF){
		for(int i=1;i<DIM;i++){
			scanf("%d",&input[i]);
		}
		
		min=8;
		for(int l=0;l<92;l++){
			tmp=0;
			for(int i=0;i<DIM;i++){
				if(record[l].row[i]!=input[i]-1){
					tmp++;
				}
			}
			if(min>tmp){
				min=tmp;
			}

		}
		printf("Case %d: %d\n",++testcase,min);
	}

	return 0;
}

static void Queen(int index,int dim){
	int r;
	int c;
	int i;

	if(dim==DIM){
		record[counter++]=s;
		sort(counter-1);
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

static bool QCR(int r,int c){
	int i;
	for(i=0;i<DIM;i++){
		if(map[r][i]==true){
			return false;
		}
	}
	return true;
}

static bool QCC(int r,int c){
	int i;
	for(i=0;i<DIM;i++){
		if(map[i][c]==true){
			return false;
		}
	}
	return true;
}

static bool QCD(int r,int c){
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

static void sort(int index){
	int tmpr, tmpc, i, j;

	for(i=0;i<DIM;i++){
		for(j=i+1;j<DIM;j++){
			if(record[index].col[i]>record[index].col[j]){
				tmpr=record[index].row[i];
				tmpc=record[index].col[i];
				record[index].row[i]=record[index].row[j];
				record[index].col[i]=record[index].col[j];
				record[index].row[j]=tmpr;
				record[index].col[j]=tmpc;
			}
		}
	}
}
