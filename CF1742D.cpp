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

const int mxn = 2e5+10;
int n;
void solve(){
	cin>>n;
	map<int,int> mp;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		mp[k] = i;
	}
//	for(auto i:mp)cout<<i.fs<<','<<i.sc<<';';
	int ans = -1;
	for(int i = 0;i<=1000;i++){
		for(int j = 0;j<=i;j++){
			if(__gcd(i,j) != 1||mp[i] == 0||mp[j] == 0)continue;
			ans = max(ans,mp[i]+mp[j]);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

