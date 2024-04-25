#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	deque<int> dq;
	vector<int> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
		if(!dq.empty()&&dq.back() == v[i])continue;
		dq.push_back(v[i]);
	}
	dq.push_back(-1);
	int now = dq.front();
	dq.pop_front();
	while(!dq.empty()){
//		cout<<dq.front()<<',';
		if(now<dq.front()){
			now = dq.front();
			dq.pop_front();
		}
		else break;
	}
	for(int i:v){
		if(i != now)cout<<i<<' ';
	}
	return 0;
	
}
