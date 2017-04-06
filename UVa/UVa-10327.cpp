#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int N;
	int *ptr;
	int flip, temp;
	
	while(scanf("%d",&N)!=EOF){
		ptr = (int*)malloc(sizeof(int)*N);
		flip=0;
		
		for(int i=0;i<N;i++){
			scanf("%d",&ptr[i]);
		}
		
		for(int i=N-1;i>0;i--){
			for(int j=0;j<i;j++){
				if(ptr[j]>ptr[j+1]){
					temp = ptr[j];
					ptr[j] = ptr[j+1];
					ptr[j+1] = temp;
					flip++;
				}
			}
		}
		
		printf("Minimum exchange operations : %d\n",flip);
	}
}
