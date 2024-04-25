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

void solve(){
	string s;
	cin>>s;
	int pos[26] = {};
	for(int i = 0;i<26;i++){
		pos[s[i]-'a'] = i;
	}
	cin>>s;
	ll ans = 0;
	for(int i = 1;i<s.size();i++){
		ans += abs(pos[s[i-1]-'a']-pos[s[i]-'a']);
	}
	cout<<ans<<"\n";
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

