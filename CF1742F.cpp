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
#define int ll
void solve(){
	int n;
	cin>>n;
	map<char,int> mp[2];
	mp[0]['a'] = mp[1]['a'] = 1;
	while(n--){
		int t,k;
		cin>>t>>k;
		string s;
		cin>>s;
		for(auto &i:s){
			mp[t-1][i] += k;
		}
		auto mp2 = mp;
		auto lit = mp2[0].begin();
		auto rit = mp2[1].rbegin();
		bool flag = true;
		while(lit != mp2[0].end()&&rit != mp2[1].rend()){
			if(lit->fs != rit->fs){
				if(lit->fs<rit->fs)cout<<"YES\n";
				else cout<<"NO\n";
				flag = false;
				break;
			}
			int d = min(lit->sc,rit->sc);
			lit->sc -= d;
			rit->sc -= d;
			if(lit->sc == 0)lit++;
			if(rit->sc == 0)rit++;
		}
		if(flag&&rit == mp2[1].rend())cout<<"NO\n";
		else if(flag)cout<<"YES\n";
	}
	return;
}
main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

