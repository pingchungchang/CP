#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	priority_queue<int,vector<int>,less<int>> pq1,pq2;
	ll sum = 0;
	for(int i = 0;i<n;i++){
		int tmp;
		cin>>tmp;
		sum += tmp;
		pq1.push(-tmp);
	}
	for(int i = 0;i<n;i++){
		int tmp;
		cin>>tmp;
		pq2.push(tmp);
	}
	while(k--&&pq2.top()>-pq1.top()){
		sum += pq1.top();
		pq1.pop();
		sum += pq2.top();
		pq1.push(-pq2.top());
		pq2.pop();
	}
	cout<<sum<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
