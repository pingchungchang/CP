//failed

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define int ll
ll n,q,x;
main(){
	io
	cin>>n>>q>>x;
	ll xx = x;
	vector<vector<ll>> dp(n+1,vector<ll>(34,0LL));
	vector<ll> v(n+1,0),pref(n*2+1,0);
	for(int i = 1;i<=n;i++){
		cin>>v[i];
		pref[i] = v[i]+pref[i-1];
	}
	for(int i = n+1;i<=n*2;i++)pref[i] = pref[i-1]+v[i-n];
//	for(auto i:pref)cout<<i<<' ';cout<<'\n';
	x %= pref[n];
	for(int i = 1;i<=n;i++){
		int pos = lower_bound(pref.begin(),pref.end(),pref[i-1]+x)-pref.begin();
		pos++;
		while(pos>n)pos -= n;
		dp[i][0] = pos;
	}
	for(int i = 1;i<34;i++){
		for(int j = 1;j<=n;j++){
			dp[j][i] = dp[dp[j][i-1]][i-1];
		}
	}
//	for(int i= 1;i<=n;i++){
//		for(int j = 0;j<4;j++)cout<<dp[i][j]<<' ';cout<<endl;
//	}
	while(q--){
		ll k;
		cin>>k;
		k--;
		int now = 1;
		for(int i = 0;i<34;i++){
			if((k&1) != 0){
				now = dp[now][i];
			}
			k>>=1;
		}
		int pos = lower_bound(pref.begin(),pref.end(),pref[now-1]+x)-pref.begin();
		ll ans = xx/pref[n]*n+(pos-now+1);
//		cout<<ans<<' '<<pref[n]<<'\n';
		cout<<now<<' '<<pos<<' '<<xx/pref[n]*n<<' '<<ans<<'\n';
	}
}

