#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll inf = 2e18;

void solve(){
	ll n,m,d;
	cin>>n>>m>>d;
	set<ll> a,b;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		a.insert(k);
	}
	for(int i = 0;i<m;i++){
		ll k;
		cin>>k;
		b.insert(k);
	}
	a.insert(-inf);
	b.insert(-inf);
	ll ans = -1;
	for(auto &i:a){
		if(i == -inf)continue;
		auto it = *--b.upper_bound(i+d);
		if(abs(it-i)<=d)ans = max(ans,it+i);
	}
	for(auto &i:b){
		if(i == -inf)continue;
		auto it = *--a.upper_bound(i+d);
		if(abs(it-i)<=d)ans = max(ans,it+i);
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
