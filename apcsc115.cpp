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
int main(){
	io
	ll n,m;
	cin>>n>>m;
	vector<ll> v(n*2+1,0LL);
	ll total = 0;
	for(int i = 1;i<=n;i++){
		cin>>v[i];
		total += v[i];
	}
	for(int i = n+1;i<=n*2;i++){
		v[i] = v[i-n];
	}
	for(int i = 1;i<=n*2;i++)v[i] += v[i-1];
	ll now = 1;
	while(m--){
		ll k;
		cin>>k;
		k %= total;
		ll pos = lower_bound(_all(v),v[now-1]+k)-v.begin();
		pos++;
		now = (pos-1)%n+1;
	}
	cout<<now-1;
}

