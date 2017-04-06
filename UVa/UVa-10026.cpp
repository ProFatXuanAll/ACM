#include <cstdio>
#include <cstdlib>
#undef DEBUG

using namespace std;


int main(){
	int N, Cases, day, fine, temp1;
	int number[1000];
	double ratio[1000], temp2;
	
	#ifdef DEBUG
	FILE* f1 = fopen("test.txt","r");
	FILE* f2 = fopen("result.txt","w");
	
	fscanf(f1,"%d",&N);
	#else
	scanf("%d",&N);
	#endif
	
	for(int i=0;i<N;i++){
		#ifdef DEBUG
		fscanf(f1,"%d",&Cases);
		#else
		scanf("%d",&Cases);
		#endif
		
		// ratio is the key
		
		for(int j=0,k=0;j<Cases;j++){
			#ifdef DEBUG
			fscanf(f1,"%d%d",&day,&fine);
			#else
			scanf("%d%d",&day,&fine);
			#endif
			number[j]=j+1;
			ratio[j]=(double)fine/day;

			temp1=number[j];
			temp2=ratio[j];
			
			for(k=j-1;k>=0;k--){
				if(ratio[k]<temp2){
					number[k+1]=number[k];
					ratio[k+1]=ratio[k];
				}
				else
					break;
			}
			
			number[k+1]=temp1;
			ratio[k+1]=temp2;
		}
		
		for(int j=0;j<Cases;j++){
			#ifdef DEBUG
			fprintf(f2,"%d",number[j]);
			if(j!=Cases-1)
				fprintf(f2," ");
			#else
			printf("%d",number[j]);
			if(j!=Cases-1)
				printf(" ");
			#endif
		}
		
		
		if(i!=N-1){
			#ifdef DEBUG
			fprintf(f2,"\n\n");
			#else
			printf("\n\n");
			#endif
		}
		else{
			#ifdef DEBUG
			fprintf(f2,"\n");
			#else
			printf("\n");
			#endif
		}
	}
	
}
