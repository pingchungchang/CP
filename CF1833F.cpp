#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mod = 1e9+7;
ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		a = a*a%mod;
		b>>=1;
	}
	return re;
}
ll inv(ll k){return pw(k,mod-2);}

void solve(){
	ll n,m;
	cin>>n>>m;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	vector<pll> v;
	sort(arr,arr+n);
	v.push_back({0,1});
	for(auto &i:arr){
		if(v.empty()||v.back().fs != i)v.push_back({i,1});
		else v.back().sc++;
	}
	for(int i = 1;i<v.size();i++)v[i].sc = v[i-1].sc*v[i].sc%mod;
	ll ans = 0;
	for(int i = m;i<v.size();i++){
		if(v[i-m+1].fs == v[i].fs-m+1){
			ans = (ans+v[i].sc*inv(v[i-m].sc))%mod;
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
