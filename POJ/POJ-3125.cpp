#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int cases;
	cin >> cases;
	
	for(int i=0;i<cases;i++){
		int n, m, temp, target, minute=0;
		
		queue<int> q;
		priority_queue<int> pq;
		
		cin >> n >> m;
		
		for(int j=0;j<n;j++){
			cin >> temp;
			
			q.push(temp);
			pq.push(temp);
			
			if(j==m)
				target=temp;
		}
		
		for(;!q.empty();){
			if(pq.top()>q.front()){ // need to shift
				for(;q.front()!=pq.top();){
					temp=q.front();
					q.pop();
					q.push(temp);
					m>0?m--:m=q.size()-1;
				}
				q.pop();
				pq.pop();
				minute++;
				if(m>0)
					m--;
				else
					break;
			}
			else if(m!=0){
				q.pop();
				pq.pop();
				minute++;
				m--;
			}
			
			if(m==0&&pq.top()==target){
				minute++;
				break;
			}
			
		}
		
		cout << minute << endl;
	}
	
	
	return 0;
}
