#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	int a[n],b[n];
	for(auto &i:a)cin>>i;
	for(auto &i:b)cin>>i;
	for(int i = 0;i<n;i++)pq.push({a[i],b[i]});
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(now.first<=k)k += now.second;
	}
	cout<<k<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
