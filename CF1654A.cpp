#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void solve(){
	int n;
	cin>>n;
	priority_queue<int,vector<int>,less<int>> pq;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		pq.push(k);
	}
	int a = pq.top();
	pq.pop();
	if(!pq.empty())a += pq.top();
	cout<<a<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

