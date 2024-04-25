#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 1e9+7;

inline ll pw(ll a,ll b){
	ll re = 1;
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
	if(!b)return a;
	return mad(a,mod-b);
}

ll n,p;

void solve(){
	cin>>n>>p;
	map<ll,ll> mp,add;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		mp[k]++;
	}
	if(p == 1){
		cout<<(n&1)<<'\n';
		return;
	}
	auto now = mp.begin()->fs;
	while(mp.find(now) != mp.end()){
		if(mp[now]>=p){
			add[now+1] = mp[now]/p;
			mp[now]%=p;
			mp[now+1] += add[now+1];
		}
		if(now == mp.rbegin()->fs)break;
		now = (++mp.find(now))->fs;
	}
	for(auto it = mp.rbegin();it != mp.rend();it++){
		if(it->sc%2 == 0)continue;
		if(add.find(it->fs) == add.end()){
			ll ans = pw(p,it->fs);
			for(auto rit = next(it);rit != mp.rend();rit++){
				ans = mub(ans,pw(p,rit->fs)*rit->sc%mod);
			}
			cout<<ans<<'\n';
			return;
		}
		next(it)->sc+=p;
	}
	cout<<"0\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
