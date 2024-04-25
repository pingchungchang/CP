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
	vector<ll> v(m);
	for(ll i = 0;i<m;i++)cin>>v[i];
	sort(v.begin(),v.end());
	priority_queue<ll,vector<ll>,less<ll>> pq;
	if(m == 1){
		pq.push(n-1);
	}
	else{
		v.push_back(v[0]+n);
		for(ll i = 1;i<=m;i++)pq.push(v[i]-v[i-1]-1);
	}
	ll tmp = 0;
	ll ans = 0;
	while(!pq.empty()){
		auto now = pq.top();
//		cout<<now<<',';
		pq.pop();
		if(tmp*2+1==now){
			ans +=now-1;
			tmp++;
		}
		else if(tmp*2+1>=now){
			ans += now;
		}
		else{
			ans += tmp*2+1;
			tmp += 2;
		}
	}
	cout<<ans+m<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

