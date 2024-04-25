#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	ll n,m,x;
	cin>>n>>m>>x;
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	for(int i = 1;i<=m;i++)pq.push(make_pair(0,i));
	vector<int> ans(n);
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		auto now = pq.top();pq.pop();
		pq.push(make_pair(now.fs+k,now.sc));
		ans[i] = now.sc;
	}
	cout<<"YES\n";
	for(auto i:ans)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

