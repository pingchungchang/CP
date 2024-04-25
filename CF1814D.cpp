#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxn = 3030;
#define pll pair<ll,ll>
#define fs first
#define sc second
ll n,k;
ll f[mxn],g[mxn];

ll calc(ll tar){
	vector<pair<ll,pll>> v;
	for(int i = 1;i<=n;i++){
		if(f[i]*g[i] == tar)continue;
		ll tmp = tar/f[i]*f[i];
		if(tar-tmp<=k){
			pair<ll,pll> re;
			re.fs = tmp;
			re.sc.fs = i;
			re.sc.sc = 1;
			if(tmp == f[i]*g[i])re.sc.sc = 0;
			v.push_back(re);
		}
		tmp += f[i];
		if(tmp-tar<=k){
			pair<ll,pll> re;
			re.fs = tmp;
			re.sc.fs = i;
			re.sc.sc = 1;
			if(tmp == f[i]*g[i])re.sc.sc = 0;
			v.push_back(re);
		}
	}
}

void solve(){
	cin>>n>>k;
	ll ans = n;
	for(int i = 1;i<=n;i++)cin>>f[i];
	for(int i = 1;i<=n;i++)cin>>g[i];
	for(int i = 1;i<=n;i++)ans = min(ans,calc(f[i]*g[i]));
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
