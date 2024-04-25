#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


const int inf = 1e9;

void solve(){
	int n;
	cin>>n;
	int tar[4] = {inf,inf,inf,inf};
	for(int i =0;i<n;i++){
		int x;
		string s;
		cin>>x>>s;
		int p = 0;
		if(s[0] == '1')p ^= 2;
		if(s[1] == '1')p ^= 1;
		tar[p] = min(tar[p],x);
	}
	int ans = 1e9;
	ans = min({ans,tar[3],tar[1]+tar[2]});
	if(ans+1>=1e9)cout<<"-1\n";
	else cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
