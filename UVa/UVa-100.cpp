#include <cstdio>
using namespace std;

int main()
{
	int i, j, temp,change;
	
	while(scanf("%d",&i)!=EOF){
		change =0;
		scanf("%d",&j);
		
		if(i>j){
			temp = i;
			i = j;
			j = temp;
			change = 1;
		}
		
		int max=0;
		
		for(int k=i;k<=j;k++){
			
			int n=k;
			int count=1;
			while(n!=1){
				if(n%2){
					n=3*n+1;
					count++;
				}
				else{
					n=n/2;
					count++;
				}
			}
			
			if(count>max)max=count;
		}	
	
		if(change)printf("%d %d %d\n",j,i,max);
		else printf("%d %d %d\n",i,j,max);
	}

	return 0;
} 
