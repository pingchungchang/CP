#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

map<ll,ll> mp,cnt;
const ll mod = 998244353;

inline ll pw(ll a,ll b){
	ll re =1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
inline ll mub(ll a,ll b){
	return mad(a,mod-b);
}

void solve(){
	mp.clear();
	cnt.clear();
	ll now;
	cin>>now;
	ll ans = 0;
	mp[now] = 1;
	cnt[now] = 1;
	while(now){
		ll sl = (now+1)>>1,sr = now>>1;
		auto tmp = mub(pw(2,sl),1)*mub(pw(2,sr),1)%mod*mp[now]%mod;
		if(now == 1)tmp = mp[now];
		ans = mad(ans,tmp);
		//cout<<now<<":"<<tmp<<endl;
		if(now == 1)break;
		mp[sl] = mad(mp[sl],mad(mp[now],mp[now]));
		cnt[sl] = mad(cnt[sl],cnt[now]);
		mp[sr] = mad(mp[sr],mad(mp[now],mad(mp[now],cnt[now])));
		cnt[sr] = mad(cnt[sr],cnt[now]);
		now = (--mp.lower_bound(now))->fs;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
