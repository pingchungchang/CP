#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

set<int> v[26];
bool done[26];
string ans;

void dfs(int now){
	ans += 'a'+now;
	done[now] = true;
	for(auto &i:v[now]){
		if(done[i])continue;
		dfs(i);
	}
	return;
}

void solve(){
	memset(done,0,sizeof(done));
	for(auto &i:v)i.clear();
	ans.clear();
	string s;
	cin>>s;
	for(int i = 1;i<s.size();i++){
		v[s[i-1]-'a'].insert(s[i]-'a');
		v[s[i]-'a'].insert(s[i-1]-'a');
	}
	for(int i = 0;i<26;i++){
		if(v[i].size()>2){
			cout<<"NO\n";
			return;
		}
	}
	for(int i = 0;i<26;i++){
		if(v[i].size() <= 1&&!done[i])dfs(i);
	}
	if(ans.size() != 26)cout<<"NO\n";
	else cout<<"YES\n"<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
