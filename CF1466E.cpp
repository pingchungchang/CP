#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 1e9+7;

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

void solve(){
	ll n;
	cin>>n;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	ll cnt[60] = {};
	ll orsum[n],andsum[n];
	for(auto &i:arr){
		for(int j = 0;j<60;j++){
			if((1LL<<j)&i)cnt[j]++;
		}
	}
	ll ans = 0;
	for(int i = 0;i<n;i++){
		orsum[i] = andsum[i] = 0;
		for(int j = 0;j<60;j++){
			ll p = 1LL<<j;
			if(p&arr[i])orsum[i] = mad(orsum[i],p%mod*n%mod),andsum[i] = mad(andsum[i],p%mod*cnt[j]%mod);
			else orsum[i] = mad(orsum[i],p%mod*cnt[j]%mod);
		}
		ans = mad(ans,andsum[i]*orsum[i]%mod);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
