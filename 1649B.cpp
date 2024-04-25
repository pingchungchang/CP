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
	priority_queue<ll,vector<ll>,less<ll>> pq;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		pq.push(k);
	}
	ll biggest = pq.top();
	pq.pop();
	ll rsum = 0;
	while(!pq.empty()){
		rsum += pq.top();
		pq.pop();
	}
	if(rsum == 0){
		cout<<0<<'\n';
		return;
	}
	else cout<<(biggest+rsum)/(rsum+1)<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

