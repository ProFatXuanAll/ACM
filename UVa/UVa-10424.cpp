#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int SumDigit(int number);

int main()
{
	char first[50];
	char second[50];
	
	int firstN=0;
	int secondN=0;
	
	int firstSum=0;
	int secondSum=0;
	
	while(fgets(first,50,stdin)!=0){
		fgets(second,50,stdin);
		
		firstN=0;
		secondN=0;		
		
		for(int i=0;i<strlen(first);i++){
			if(first[i]>='a'&&first[i]<='z'){
				firstN += first[i] - 'a' + 1;
			}
			else if(first[i]>='A'&&first[i]<='Z'){
				firstN += first[i] - 'A' + 1;
			}
		}
		
		for(int i=0;i<strlen(second);i++){
			if(second[i]>='a'&&second[i]<='z'){
				secondN += second[i] - 'a' + 1;
			}
			else if(second[i]>='A'&&second[i]<='Z'){
				secondN += second[i] - 'A' + 1;
			}
		}
		
		if(firstN)
			firstSum=SumDigit(firstN);
		else
			firstSum=0;
		
		if(secondN)	
			secondSum=SumDigit(secondN);
		else
			secondSum=0;
		
		if(firstSum&&secondSum){
			if((float)secondSum/firstSum*100<=100)
				printf("%.2f %%\n",(float)secondSum/firstSum*100);
			else
				printf("%.2f %%\n",(float)firstSum/secondSum*100);
		}
		else if(firstSum&&secondSum==0)
			printf("0.00 %%\n");
		else if(firstSum==0&&secondSum)	
			printf("0.00 %%\n");
		else
			printf("\n");
	}

}

int SumDigit(int number)
{
	int Sum=0;
	
	for(;number/10!=0;){
		Sum+=number%10;
		number/=10;
	}
	Sum+=number;
	
	if(Sum>=10)
		Sum=SumDigit(Sum);
	
	return Sum;
	
}
