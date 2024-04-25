#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double


void solve(){
	int n,q;
	cin>>n>>q;
	map<int,pii> mp;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		if(mp.count(k) == 0)mp[k] = make_pair(i,i);
		else mp[k].sc = i;
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		if(mp.count(s) == 0||mp.count(e) == 0)cout<<"NO\n";
		else if(mp[s].fs<mp[e].sc)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return;
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

