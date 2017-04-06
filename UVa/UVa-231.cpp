#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MAX (100000)

int stack[MAX];
int LIS[MAX];

int main(void)
{
	int test=1;
	int counter=0; 
	int max_pos;

	while(1){
		counter=0;
		while(1){
			scanf("%d",&stack[counter]);
			if(stack[counter]==-1){
				break;
			}
			else{
				counter++;
			}
		}

		if(counter==0){
			break;
		}

		max_pos=0;
		for(int i=0;i<counter;i++){
			LIS[i]=1;
			for(int j=0;j<i;j++){
				if(stack[j]>=stack[i]&&LIS[j]+1>LIS[i]){
					LIS[i]=LIS[j]+1;
					if(LIS[i]>LIS[max_pos]){
						max_pos=i;
					}
				}
			}
		}

		if(test!=1){
			puts("");
		}
		printf("Test #%d:\n",test++);
		printf("  maximum possible interceptions: %d\n",LIS[max_pos]);
	}

	return 0;
}
