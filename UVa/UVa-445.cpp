#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(void)
{
	char tmp='\0';
	bool next=false;
	int sum=0;

	while((tmp=getchar())!=EOF){
		if('1'<=tmp&&'9'>=tmp){
			sum=tmp-'0';
			while(tmp=getchar()){
				if('1'<=tmp&&tmp<='9'){
					sum+=tmp-'0';
				}
				else{
					if(tmp=='b'){
						for(int i=0;i<sum;i++){
							printf(" ");
						}
					}
					else{
						for(int i=0;i<sum;i++){
							printf("%c",tmp);
						}
					}
					break;
				}
			}
		}
		else if(tmp=='!'){
			printf("\n");
		}
		else if(tmp=='\n'&&next==false){
			next==true;
			printf("\n");
		}
		else{
			next=false;
			printf("\n");
		}
	}

	return 0;
}
