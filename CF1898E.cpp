#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

set<int> st[26];
string s,t;
int n,m;

void solve(){
	for(auto &i:st)i.clear();
	cin>>n>>m;
	cin>>s>>t;
	for(int i = 0;i<n;i++){
		st[s[i]-'a'].insert(i);
	}
	for(int i = 0;i<m;i++){
		char tar = t[i]-'a';
		if(st[tar].empty()){
			cout<<"NO\n";
			return;
		}
		auto pos = *st[tar].begin();
		for(int j = 0;j<=tar;j++){
			st[j].erase(st[j].begin(),st[j].upper_bound(pos));
		}
	}
	cout<<"YES\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
