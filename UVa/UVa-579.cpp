#include <cstdio>
using namespace std;

int main()
{
	int hour;
	int minute;
	
	float Hangle;
	float Mangle;
	float angle;
	
	while(scanf("%d:%2d",&hour,&minute)){
		if(hour==0&&minute==0){
			break;
		}
		
		Mangle=(float)minute*6;
		Hangle=(float)hour*30+(float)minute/2;
		
		if(Mangle>Hangle)
			angle=Mangle-Hangle;
		else if(Mangle == Hangle)
			angle=Mangle;
		else
			angle=Hangle-Mangle;
			
		if(angle>180)
			angle=360-angle;
		
		printf("%.3f\n",angle);
	}
	
	return 0;
}
