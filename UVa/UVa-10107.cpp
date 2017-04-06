#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	int i=0, j=0, ptr[10001], temp;
	
	while(scanf("%d",&ptr[i])!=EOF){
		temp = ptr[i];
		
		for(j=i-1;j>=0;j--){
			if(ptr[j]>temp) // shifting through right
				ptr[j+1]=ptr[j];
			else // found position
				break;
		}
		ptr[j+1]=temp; // might be the smallest one
		
		printf("%d\n",((i+1)%2)?ptr[i/2]:(ptr[i/2]+ptr[i/2+1])/2);
		
		i++;
	}
	
	return 0;
}
