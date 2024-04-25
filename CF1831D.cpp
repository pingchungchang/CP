#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

const int mxn = 4e5+10;

void solve(){
	int n;
	cin>>n;
	map<int,vector<int>> mp;
	ll ans = 0;
	pii arr[n];
	for(auto &i:arr)cin>>i.fs;
	for(auto &i:arr)cin>>i.sc;
	for(auto &i:arr)mp[i.fs].push_back(i.sc);
	for(auto &i:mp)sort(i.sc.begin(),i.sc.end());
	for(auto it = mp.begin();it != mp.end();it++){
		for(auto rit = next(it);1LL*rit->fs*it->fs<mxn&&rit != mp.end();rit++){
			int pp = rit->fs*it->fs;
			for(auto &j:rit->sc){
				auto pl = lower_bound(it->sc.begin(),it->sc.end(),pp-j);
				auto pr = upper_bound(it->sc.begin(),it->sc.end(),pp-j);
				ans += pr-pl;
			}
		}
	}
	for(auto &i:mp){
		if(i.fs == 1)continue;
		if(1LL*i.fs*i.fs>=mxn)continue;
		int p = i.fs*i.fs;
		ll ta = 0;
		for(auto &j:i.sc){
			auto lit = lower_bound(i.sc.begin(),i.sc.end(),p-j);
			auto rit = upper_bound(i.sc.begin(),i.sc.end(),p-j);
			ta += rit-lit;
			if(p-j == j)ta--;
		}
		assert(!(ta&1));
		ans += ta>>1;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
