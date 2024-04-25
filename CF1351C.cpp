#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	string s;
	cin>>s;
	set<pair<pii,pii>> st;
	pii now = {0,0};
	ll ans = 0;
	for(auto &i:s){
		pii tmp = now;
		if(i == 'N')now.sc++;
		else if(i == 'S')now.sc--;
		else if(i == 'E')now.fs++;
		else now.fs--;
		if(st.find(make_pair(tmp,now)) != st.end())ans++;
		else ans += 5;
		st.insert(make_pair(tmp,now));
		st.insert(make_pair(now,tmp));
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
