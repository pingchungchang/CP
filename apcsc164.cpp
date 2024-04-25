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

class cmp{
	public:
		bool operator()(pll a,pll b){
			return a.fs*b.sc<b.fs*a.sc;
		}
};
int main(){
	io
	ll n,m;
	cin>>n>>m;
	priority_queue<pll,vector<pll>,cmp> pq;
	for(ll i = 0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		pq.push(make_pair(a,b));
	}
	ll ans= 0;
	while(!pq.empty()){
		ans += m/pq.top().sc*pq.top().fs;
		m %= pq.top().sc;
		pq.pop();
	}
	cout<<ans;
}

