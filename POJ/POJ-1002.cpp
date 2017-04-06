#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int N, phone_number[100001] = {0}, times[100001] = {0};

int main()
{
	char input;
	int output=0, counter=1;
	int temp;
	
	scanf("%d",&N);
	
	for(int i=0,j=0;i<N;i++){
		
		for(j=0;j<7;j++){
			scanf("%c",&input);
			
			switch(input){
				case '0':
					phone_number[i] *= 10;
					break;
				case '1':
					phone_number[i] = phone_number[i]* 10 + 1;
					break;
				case 'A':
				case 'B':
				case 'C':
				case '2':
					phone_number[i] = phone_number[i]* 10 + 2;
					break;
				case 'D':
				case 'E':
				case 'F':
				case '3':
					phone_number[i] = phone_number[i]* 10 + 3;
					break;
				case 'G':
				case 'H':
				case 'I':
				case '4':
					phone_number[i] = phone_number[i]* 10 + 4;
					break;
				case 'J':
				case 'K':
				case 'L':
				case '5':
					phone_number[i] = phone_number[i]* 10 + 5;
					break;
				case 'M':
				case 'N':
				case 'O':
				case '6':
					phone_number[i] = phone_number[i]* 10 + 6;
					break;
				case 'P':
				case 'R':
				case 'S':
				case '7':
					phone_number[i] = phone_number[i]* 10 + 7;
					break;
				case 'T':
				case 'U':
				case 'V':
				case '8':
					phone_number[i] = phone_number[i]* 10 + 8;
					break;
				case 'W':
				case 'X':
				case 'Y':
				case '9':
					phone_number[i] = phone_number[i]* 10 + 9;
					break;
				default:
					j--;
			}
		}		
	}

	sort(phone_number,phone_number+N);

	temp=phone_number[0];
	
	for(int i=1;i<N;i++){
		if(phone_number[i]==temp){
			counter++;
			output=1;
		}
		else if(counter>1){
			printf("%.3d-%.4d %d\n",temp/10000,temp%10000,counter);
			counter=1;
			temp=phone_number[i];
		}
		else{
			temp=phone_number[i];
		}
	}
	if(counter>1){
		printf("%.3d-%.4d %d\n",temp/10000,temp%10000,counter);
	}
	
	if(!output)
		printf("No duplicates.\n");
	
	return 0;
}

/*
// TLE version 3
int N, phone_number[100001] = {0}, times[100001] = {0};

int main()
{
	char input;
	int output=0;
	int temp;
	int cases=0;
	
	scanf("%d",&N);
	
	for(int i=0,j=0;i<N;i++){
		
		for(j=0;j<7;j++){
			scanf("%c",&input);
			
			switch(input){
				case '0':
					phone_number[i] *= 10;
					break;
				case '1':
					phone_number[i] = phone_number[i]* 10 + 1;
					break;
				case 'A':
				case 'B':
				case 'C':
				case '2':
					phone_number[i] = phone_number[i]* 10 + 2;
					break;
				case 'D':
				case 'E':
				case 'F':
				case '3':
					phone_number[i] = phone_number[i]* 10 + 3;
					break;
				case 'G':
				case 'H':
				case 'I':
				case '4':
					phone_number[i] = phone_number[i]* 10 + 4;
					break;
				case 'J':
				case 'K':
				case 'L':
				case '5':
					phone_number[i] = phone_number[i]* 10 + 5;
					break;
				case 'M':
				case 'N':
				case 'O':
				case '6':
					phone_number[i] = phone_number[i]* 10 + 6;
					break;
				case 'P':
				case 'R':
				case 'S':
				case '7':
					phone_number[i] = phone_number[i]* 10 + 7;
					break;
				case 'T':
				case 'U':
				case 'V':
				case '8':
					phone_number[i] = phone_number[i]* 10 + 8;
					break;
				case 'W':
				case 'X':
				case 'Y':
				case '9':
					phone_number[i] = phone_number[i]* 10 + 9;
					break;
				default:
					j--;
			}
		}
		
		
		temp=phone_number[i];
		
		for(j=i-1;j>=0;j--){
			if(phone_number[j]>temp){
				phone_number[j+1]=phone_number[j];
			}
			else break;
		}		
		phone_number[j+1]=temp;
		
	}

	temp=phone_number[0];
	
	for(int i=1,counter=1;i<N;i++){
		if(phone_number[i]==temp){
			counter++;
			output=1;
		}
		else if(counter>1){
			printf("%.3d-%.4d %d\n",temp/10000,temp%10000,counter);
			counter=1;
			temp=phone_number[i];
		}
		else{
			temp=phone_number[i];
		}
	}
	
	if(!output)
		printf("No duplicates.");
	
	return 0;
}
*/

/*
// TLE version 2
int N, phone_number[100001][8];

int compare(int a[], int b[]);

int main()
{
	char input;
	int output=0;
	int temp[8];
	
	scanf("%d",&N);
	
	for(int i=0,j=0;i<N;i++){
		
		for(j=0;j<7;j++){
			scanf("%c",&input);
			
			switch(input){
				case '0':
					temp[j]=phone_number[i][j] = 0;
					break;
				case '1':
					temp[j]=phone_number[i][j] = 1;
					break;
				case 'A':
				case 'B':
				case 'C':
				case '2':
					temp[j]=phone_number[i][j] = 2;
					break;
				case 'D':
				case 'E':
				case 'F':
				case '3':
					temp[j]=phone_number[i][j] = 3;
					break;
				case 'G':
				case 'H':
				case 'I':
				case '4':
					temp[j]=phone_number[i][j] = 4;
					break;
				case 'J':
				case 'K':
				case 'L':
				case '5':
					temp[j]=phone_number[i][j] = 5;
					break;
				case 'M':
				case 'N':
				case 'O':
				case '6':
					temp[j]=phone_number[i][j] = 6;
					break;
				case 'P':
				case 'R':
				case 'S':
				case '7':
					temp[j]=phone_number[i][j] = 7;
					break;
				case 'T':
				case 'U':
				case 'V':
				case '8':
					temp[j]=phone_number[i][j] = 8;
					break;
				case 'W':
				case 'X':
				case 'Y':
				case '9':
					temp[j]=phone_number[i][j] = 9;
					break;
				default:
					j--;
			}
		}
		
		temp[7]=phone_number[i][7]=1;
		
		for(j=i-1;j>=0;j--){
			int equality = compare(phone_number[j],temp);
			
			if(equality==1){
				phone_number[j+1][0]=phone_number[j][0];
				phone_number[j+1][1]=phone_number[j][1];
				phone_number[j+1][2]=phone_number[j][2];
				phone_number[j+1][3]=phone_number[j][3];
				phone_number[j+1][4]=phone_number[j][4];
				phone_number[j+1][5]=phone_number[j][5];
				phone_number[j+1][6]=phone_number[j][6];
				phone_number[j+1][7]=phone_number[j][7];
			}
			else if(equality==0){
				phone_number[j+1][0]=phone_number[j][0];
				phone_number[j+1][1]=phone_number[j][1];
				phone_number[j+1][2]=phone_number[j][2];
				phone_number[j+1][3]=phone_number[j][3];
				phone_number[j+1][4]=phone_number[j][4];
				phone_number[j+1][5]=phone_number[j][5];
				phone_number[j+1][6]=phone_number[j][6];
				phone_number[j+1][7]=phone_number[j][7];
				temp[7]++;
			}
			else break;
		}
		
		phone_number[j+1][0]=temp[0];
		phone_number[j+1][1]=temp[1];
		phone_number[j+1][2]=temp[2];
		phone_number[j+1][3]=temp[3];
		phone_number[j+1][4]=temp[4];
		phone_number[j+1][5]=temp[5];
		phone_number[j+1][6]=temp[6];
		phone_number[j+1][7]=temp[7];
		
	}

	for(int i=0;i<N;){
		if(phone_number[i][7]>1){
			for(int j=0;j<3;j++)
				printf("%d",phone_number[i][j]);
			printf("-");
			for(int j=3;j<7;j++)
				printf("%d",phone_number[i][j]);
			printf(" %d\n",phone_number[i][7]);
			
			i+=phone_number[i][7];
			output++;
		}
		else
			i++;
	}
	
	if(!output)
		printf("No duplicates.");
	
	return 0;
}

int compare(int a[], int b[])
{
	
	for(int i=0;i<7;i++){
		if(a[i]>b[i])
			return 1;
		else if(a[i]<b[i])
			return -1;
	}
	
	return 0; // equal
}
*/


/*
// TLE version
int N, phone_number[100001][7], combine[100001][7];

void MergeSort(int low, int high);
int compare(int a, int b);

int main()
{
	char input;
	
	scanf("%d",&N);
	
	for(int i=0;i<N;i++){
		
		for(int j=0;j<7;j++){
			scanf("%c",&input);
			
			switch(input){
				case '0':
					phone_number[i][j] = 0;
					break;
				case '1':
					phone_number[i][j] = 1;
					break;
				case 'A':
				case 'B':
				case 'C':
				case '2':
					phone_number[i][j] = 2;
					break;
				case 'D':
				case 'E':
				case 'F':
				case '3':
					phone_number[i][j] = 3;
					break;
				case 'G':
				case 'H':
				case 'I':
				case '4':
					phone_number[i][j] = 4;
					break;
				case 'J':
				case 'K':
				case 'L':
				case '5':
					phone_number[i][j] = 5;
					break;
				case 'M':
				case 'N':
				case 'O':
				case '6':
					phone_number[i][j] = 6;
					break;
				case 'P':
				case 'R':
				case 'S':
				case '7':
					phone_number[i][j] = 7;
					break;
				case 'T':
				case 'U':
				case 'V':
				case '8':
					phone_number[i][j] = 8;
					break;
				case 'W':
				case 'X':
				case 'Y':
				case '9':
					phone_number[i][j] = 9;
					break;
				default:
					j--;
			}
		}	
	}

	MergeSort(0,N-1);

	int output=0;
	for(int i=0,counter=1;i<N;){
		if(compare(i,i+counter)==2){
			counter++;
		}
		else{
			
			if(counter!=1){
				for(int j=0;j<3;j++)
					printf("%d",phone_number[i][j]);
				printf("-");
				for(int j=3;j<7;j++)
					printf("%d",phone_number[i][j]);
				printf(" %d\n",counter);
				
				output++;
			}
			
			i+=counter;
			counter=1;
		}
	}
	
	if(!output)
		printf("No duplicates.");
	
	return 0;
}

void MergeSort(int low, int high)
{
	if(low<high){
		int mid = (low+high) / 2;
		
		MergeSort(low,mid);
		MergeSort(mid+1,high);
		
		for(int i=low,j=mid+1,k=0;i<=mid||j<=high;){
			if(i>mid){
				for(int copy=0;copy<7;copy++)
					combine[k][copy]=phone_number[j][copy];
				j++;
				k++;
			}
			else if(j>high){
				for(int copy=0;copy<7;copy++)
					combine[k][copy]=phone_number[i][copy];
				i++;
				k++;
			}
			else if(compare(i,j)){
				for(int copy=0;copy<7;copy++)
					combine[k][copy]=phone_number[i][copy];
				i++;
				k++;
			}
			else{
				for(int copy=0;copy<7;copy++)
					combine[k][copy]=phone_number[j][copy];
				j++;
				k++;
			}
		}
		
		for(int i=low,j=0;i<=high;i++,j++)
			for(int k=0;k<7;k++)
				phone_number[i][k]=combine[j][k];	
	}

}

int compare(int a, int b)
{
	
	for(int i=0;i<7;i++){
		if(phone_number[a][i]>phone_number[b][i])
			return 0;
		else if(phone_number[a][i]<phone_number[b][i])
			return 1;
	}
	
	return 2; // equal
}*/
