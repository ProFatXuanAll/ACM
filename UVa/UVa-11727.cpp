#include <cstdio>
using namespace std;

int main()
{
	int T;
	int a[3], temp;
	
	scanf("%d",&T);
	
	for(int i=1;i<=T;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&a[j]);
		}
		
		for(int j=2;j>0;j--){
			for(int k=0;k<j;k++){
				if(a[k]>a[k+1]){
					temp=a[k];
					a[k]=a[k+1];
					a[k+1]=temp;
				}
			}
		}
		
		printf("Case %d: %d\n",i,a[1]);
	}
	
	return 0;
}
