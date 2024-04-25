#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	pll arr[n];
	for(auto &i:arr)cin>>i.fs>>i.sc,i.sc = -i.sc;
	sort(arr,arr+n);
	for(auto &i:arr)i.sc = -i.sc;
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	ll ans = 0;
	ll cnt = 0;
	ll big = 0;
	for(auto &i:arr){
		if(big>=i.fs)continue;
		pq.push(i.fs);
		ans += i.sc;
		//cout<<i.fs<<' '<<i.sc<<',';
		big = max(big,(ll)pq.size());
		while(!pq.empty()&&pq.top()<=big)pq.pop();
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
