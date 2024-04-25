#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll big = 1e12;

void solve(){
	string s;
	cin>>s;
	int n = s.size();
	int suf[n] = {},pref[n] = {};
	if(s[0] == '1')pref[0] = 1;
	if(s.back() == '0')suf[n-1] = 1;
	for(int i = 1;i<n;i++){
		pref[i] = pref[i-1];
		if(s[i] == '1')pref[i]++;
	}
	for(int i = n-2;i>=0;i--){
		suf[i] = suf[i+1];
		if(s[i] == '0')suf[i]++;
	}
	ll ans = (big+1)*min(pref[n-1],suf[0]);
	//for(auto &i:pref)cout<<i<<' ';cout<<'\n';
	//for(auto &i:suf)cout<<i<<' ';cout<<'\n';
	for(int i = 1;i<n;i++){
		ans = min(ans,(big+1)*(pref[i-1]+suf[i]));
		if(s[i-1] == '1'&&s[i] == '0'){
			ans = min(ans,(big+1)*(pref[i-1]+suf[i]-2)+big);
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
