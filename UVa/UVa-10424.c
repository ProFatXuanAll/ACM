#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cal(int a, int b);

int main()
{
	char c;
	int str1;
	int str2;
	int flag=-1;

	while((c=getchar())!=EOF){
		if(flag<=0){
			str1=0;
			str2=0;
			flag=1;
		}

		if(c=='\n'){
			if(flag==1){
				flag=2;
			}
			else{
				flag=0;
				cal(str1,str2);
			}
		}
		else if(c>='a'&&c<='z'){
			if(flag==1){
				str1+=(c-'a'+1);
			}
			else{
				str2+=(c-'a'+1);
			}
		}
		else if(c>='A'&&c<='Z'){
			if(flag==1){
				str1+=(c-'A'+1);
			}
			else{
				str2+=(c-'A'+1);
			}
		}
		else{

		}
	}

	return 0;
}

void cal(int a, int b)
{
	int i=0,j=0;
	do{
		for(i=0;a>0;a/=10){
			i+=a%10;
		}
		if(i<10){
			break;
		}
		else{
			a=i;
			continue;
		}
	}while(1);
	do{
		for(j=0;b>0;b/=10){
			j+=b%10;
		}
		if(j<10){
			break;
		}
		else{
			b=j;
			continue;
		}
	}while(1);
	
	if(i==0||j==0){
		printf("0.00 %%\n");
		return;
	}
	else if(i<j){
		i*=100;
		printf("%.2f %%\n",(float)i/j);
		return;
	}
	j*=100;
	printf("%.2f %%\n",(float)j/i);
	return;
}
