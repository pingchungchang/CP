#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	ll ans[n] = {};
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		pq.push({k,i});
	}
	for(int i = n;i>=1;i--){
		auto now= pq.top();
		pq.pop();
		ans[now.sc] = i;
	}
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
