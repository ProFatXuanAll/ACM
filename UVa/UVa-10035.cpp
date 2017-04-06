#include <cstdio>

using namespace std;

int main(void)
{
	int a, b, ad, bd, c, count;

	while(1){
		scanf("%d%d",&a,&b);
		if(!a&&!b){
			break;
		}
		c=count=0;
		while(a>0||b>0){
			ad=a%10;
			bd=b%10;
			a/=10;
			b/=10;
			if(ad+bd+c>=10){
				count++;
				c=1;
			}
			else{
				c=0;
			}
		}
		if(count>1){
			printf("%d carry operations.\n",count);
		}
		else if(count==0){
			printf("No carry operation.\n");
		}
		else{
			printf("1 carry operation.\n");
		}
	}

	return 0;
}
