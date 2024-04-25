#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int cnt[26] = {};
	string s;
	cin>>s;
	for(auto &i:s)cnt[i-'a']++;
	int c = 0;
	int odd =0 ;
	for(auto &i:cnt){
		if(i>1)c++;
	}
	if(c>1)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
