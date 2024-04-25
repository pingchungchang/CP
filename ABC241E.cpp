#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll total;
vector<ll> v;
ll n;
ll k;
int main(){
	cin>>n>>k;
	v = vector<ll>(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	vector<ll> idx(n,-1);
	idx[0] = 0;
	ll nid = 0;
	ll now = v[0]%n;
	while(idx[now] == -1){
		nid++;
		idx[now] = nid;
		now = (now + v[now])%n;
	}
	ll ans =0;
	ll x = 0;
	while(k != 0&&x != now){
		k--;
		ans += v[x];
		x = (x+v[x])%n;
	}
	vector<ll> pref = {v[now]};
	x = (now+v[now])%n;
	while(x != now){
		pref.push_back(v[x]+ *pref.rbegin());
		x = (v[x]+x)%n;
	}
	ans += *pref.rbegin()*(k/pref.size());
	k %= pref.size();
	if(k == 0)cout<<ans;
	else cout<<ans+pref[k-1];
}
