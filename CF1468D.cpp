#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

void solve(){
	ll n,m,a,b;
	cin>>n>>m>>a>>b;
	ll times = 0;
	if(a<b)times = b-1;
	else times = n-b;
	ll cnt = max(a-b,b-a)-1;
	priority_queue<ll,vector<ll>,less<ll>> pq;
	while(m--){
		ll k;
		cin>>k;
		pq.push(k);
	}
	ll ans = 0;
	ll now = 1;
	while(!pq.empty()&&cnt>ans){
		while(!pq.empty()&&times<pq.top()+now)pq.pop();
		if(!pq.empty()){
			ans++;
			pq.pop();
		}
		now++;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

