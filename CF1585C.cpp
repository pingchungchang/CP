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
	ll n,m;
	cin>>n>>m;
	priority_queue<ll,vector<ll>,less<ll>> pos,neg;
	for(ll i = 0;i<n;i++){
		ll k;
		cin>>k;
		if(k<0)neg.push(abs(k));
		else if(k>0)pos.push(k);
	}
	priority_queue<ll,vector<ll>,less<ll>> pq;
	ll ans = 0;
	while(!pos.empty()){
		pq.push(pos.top());
		ans += pos.top();
		for(ll i = 0;i<m&&!pos.empty();i++)pos.pop();
	}
	while(!neg.empty()){
		pq.push(neg.top());
		ans += neg.top();
		for(ll i = 0;i<m&&!neg.empty();i++)neg.pop();
	}
	cout<<ans*2-(!pq.empty()?pq.top():0LL)<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

