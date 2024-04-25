#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	int cnt[26] = {};
	map<string,ll> mp;
	for(auto &i:s){
		for(char j= 'a';j<='z';j++){
			string tmp = string(1,j)+i;
			mp[tmp] += cnt[j-'a'];
		}
		cnt[i-'a']++;
	}
	ll ans = 0;
	for(auto &i:mp)ans = max(ans,i.sc);
	for(auto &i:cnt)ans = max(ans,1LL*i);
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
