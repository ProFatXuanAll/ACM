#include<iostream>  
#include<cstdio>  
#include<cmath>  
#include<algorithm>  

using namespace std;  
#define FOR(i,m,n) for( int i=m; i<n; ++i)  

double const epx = 1e-8;  

int dcmp( double x)  
{  
    if( fabs(x) < epx)  
        return 0;  
    return x < 0 ?-1:1;  
}  

struct node  
{  
    double x,y,d;  

    node(double a,double b)
		:x(a),y(b)
	{
	}  
    
	node()
	{
	}	
};  

typedef node vec;  
  
vec operator - ( node a,node b)  
{  
    return vec( a.x-b.x,a.y-b.y);  
}  

node point[ 110 ];  
  
double length( node a,node b)  
{  
    vec A = a - b;  
    return sqrt(A.x*A.x + A.y*A.y);  
}  

double crosspruduct(node a,node b,node c)  
{  
    vec AB = b - a;  
    vec AC = c - a;  
    return AB.x * AC.y - AB.y * AC.x ;  
}  

bool idcmp(node a ,node b)  
{  
    return ( a.x == b.x )? ( a.y < b.y ): ( a.x < b.x );  
}  
  
bool anglecmp( node a,node b)  
{  
    double cp = crosspruduct( point[0],a,b);  
    if( dcmp(cp) == 0 )  
       return  a.d < b.d;  
    return cp > 0;  
}  
  
double graham( int n)  
{  
    if( n > 1 )  
    {  
        sort( point,point+n,idcmp);  
        FOR(i,1,n)  
            point[i].d = length(point[0],point[i]);  
  
        sort(point+1,point+n,anglecmp);  
    }  
    int top = n-1;  
    if( n > 2 )  
    {  
        top = 1;  
        for( int i = 2;i <n ;++i)  
        {  
            while( top > 0  
                  &&crosspruduct( point[ top-1],point[top],point[i])<0)  
                    --top;  
  
            point[++top] = point[i];  
  
        }  
    }  
    point[++top] = point[0];  
  
    double sum = 0.0;  
    FOR(i,0,top)  
    {  
        sum += length( point[i],point[i+1]);  
    }  
  
    return sum ;  
  
}  
  
int main()  
{  
    int cas,len,num;  
    cin>>cas;  
    while( cas-- )  
    {  
        cin>>len>>num;  
        FOR(i,0,num)  
        {  
            scanf("%lf %lf",&point[i].x,&point[i].y);  
        }  
  
        double ans = graham(num);  
        if( ans < len )  
            ans = (double)len ;  
        printf("%.5lf\n",ans);  
  
    }  
  
    return 0;  
}
