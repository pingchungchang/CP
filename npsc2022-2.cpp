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

const ll mod = 1e9+7;
set<pll> st;
pll ps = {29,31};
void solve(){
	string t;
	cin>>t;
	int ans = -1;
	pll h = {0,0};
	pll tmp = {1,1};
	for(int i = 0;i<t.size();i++){
		h.fs += tmp.fs*(t[i]-'a'+1)%mod;
		h.sc += tmp.sc*(t[i]-'a'+1)%mod;
		tmp.fs = tmp.fs*ps.fs%mod;
		tmp.sc = tmp.sc*ps.sc%mod;
		if(h.fs>=mod)h.fs -= mod;
		if(h.sc>=mod)h.sc -= mod;
		if(st.find(h) != st.end())ans = max(ans,min(i+1,(int)t.size()-i-1));
	} 
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	string s;
	cin>>s;
	pll h = {0,0};
	pll tmp = {1,1};
	for(int i = s.size()-1;i>=0;i--){
		h.fs += (s[i]-'a'+1);
		h.sc += (s[i]-'a'+1);
		if(h.fs>=mod)h.fs -= mod;
		if(h.sc>=mod)h.sc -= mod;
		st.insert(h);
		h.fs = h.fs*ps.fs%mod;
		h.sc = h.sc*ps.sc%mod;
	}
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

