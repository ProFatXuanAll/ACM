#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define TOTAL (1000)
#define SIZE (12)

static int t, n, input[SIZE], trace[SIZE], last_trace[SIZE];
bool flag;

void p(int dim, int sum, int top);

int main(void)
{
	while(1){
		scanf("%d%d",&t,&n);
		
		if(n==0){
			break;
		}

		for(int i=0;i<n;i++){
			scanf("%d",&input[i]);
		}
	
		printf("Sums of %d:\n",t);
		flag=0;
		p(0,0,0);
		if(flag==0){
			printf("NONE\n");
		}
	}

	return 0;
}

void p(int dim, int sum, int top){
	if(sum==t){
			for(int i=0;i<top-1;i++){
				printf("%d+",trace[i]);
			}
			printf("%d\n",trace[top-1]);
			flag=1;
	}
	else if(top<SIZE){
		for(int i=dim;i<n;i++){
			if(sum+input[i]<=t){
				trace[top]=input[i];
				p(i+1,sum+input[i],top+1);
				trace[top]=0;
				for(int j=i+1;j<n&&input[i]==input[j];j++){
					i=j;
				}
			}
		}
	}
	else{
		return;
	}
}
