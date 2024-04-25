#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	string s;
	cin>>n>>s;
	s = "#"+s;
	pii pref[n+1];
	pref[0] = {0,0};
	for(int i = 1;i<=n;i++){
		pref[i] = pref[i-1];
		if(s[i] == 'L')pref[i].fs--;
		else if(s[i] == 'R')pref[i].fs++;
		else if(s[i] == 'U')pref[i].sc--;
		else pref[i].sc++;
	}
	map<pii,int> mp;
	pii ans = {1e9,0};
	for(int i = 0;i<=n;i++){
		if(mp.find(pref[i]) != mp.end()){
			pii tmp = make_pair(i-mp[pref[i]],i);
			ans = min(ans,tmp);
		}
		mp[pref[i]] = i;
	}
	if(ans.fs>n)cout<<"-1\n";
	else cout<<ans.sc-ans.fs+1<<' '<<ans.sc<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
