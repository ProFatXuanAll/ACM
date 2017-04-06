#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	int N, commend, element;
	
	while(scanf("%d",&N)!=EOF){
		
		stack<int> st;
		queue<int> q;
		priority_queue<int> pq;
		
		bool st_data=true, q_data=true, pq_data=true;
		
		for(int i=0;i<N;i++){
			scanf("%d%d",&commend,&element);
		
			switch(commend){
				case 1: // push
					st.push(element);
					q.push(element);
					pq.push(element);
					break;
				case 2:
					if(st_data&&!st.empty()&&st.top()==element){
						st.pop();
					}else{
						st_data=false;
					}
					
					if(q_data&&!q.empty()&&q.front()==element){
						q.pop();
					}
					else{
						q_data=false;
					}
					
					if(pq_data&&!pq.empty()&&pq.top()==element){
						pq.pop();
					}
					else{
						pq_data=false;
					}
					break;
			}				
		}
		
		if(st_data){
			if(!q_data&&!pq_data)
				printf("stack\n");
			else
				printf("not sure\n");
		}
		else if(q_data){
			if(!pq_data)
				printf("queue\n");
			else
				printf("not sure\n");
		}
		else if(pq_data)
			printf("priority queue\n");
		else
			printf("impossible\n");
		
	}
	
	return 0;
}
