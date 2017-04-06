#include <cstdio>
#include <cstdlib>
using namespace std;

void Ultra_QuickSort(int low, int high);

int N, arr[500001], temp[500001];
long long int op=0;

int main()
{
	
	//freopen("test.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	scanf("%d",&N);
	
	while(N){
		
		for(int i=0;i<N;i++)
			scanf("%d",&arr[i]);
			
		Ultra_QuickSort(0,N-1); // merge sort
		
		/*
		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++){
				if(arr[i][1]>arr[j][1]){
					op+=arr[i][1]-arr[j][1];
					break;
				}
			}
		}*/
		
		printf("%lld\n",op);
		
		op=0;
		
		scanf("%d",&N);
	}
	
	return 0;
}

void Ultra_QuickSort(int low, int high)
{
	int mid = (low+high)/2;
	
	if(low<high){ // divide condition
	
		// divide into 2 part
		Ultra_QuickSort(low,mid);
		Ultra_QuickSort(mid+1,high);
		
		// merge
		for(int i=low,j=mid+1,k=0;i<=mid||j<=high;){
			if(i>mid){ // copy the left right part
				temp[k]=arr[j];
				k++;
				j++;
			}
			else if(j>high){ // copy the left left part
				temp[k]=arr[i];
				k++;
				i++;
			}
			else if(arr[i]<=arr[j]){ // choose the smallest one from left, stable sorting
				temp[k]=arr[i];
				k++;
				i++;
			}
			else{ // choose the smallest one from right
				temp[k]=arr[j];
				k++;
				j++;
				op+=mid-i+1;
			}
		}
		
		for(int i=low,k=0;i<=high;i++,k++){ // copy back to origin array
			arr[i]=temp[k];
		}
	}
	
	return;
}
