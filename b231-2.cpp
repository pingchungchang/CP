#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int main(){
	priority_queue<pii,vector<pii>,less<pii>> pq;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int a,b;
		cin>>a>>b;
		pq.push(make_pair(b,a));
	}
	int mt = 0;
	int t = 0;
	while(!pq.empty()){
		t += pq.top().second;
		mt = max(mt,t+pq.top().first);
		pq.pop();
	}
	cout<<mt;
}
