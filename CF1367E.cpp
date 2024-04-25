#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int cnt[26] = {};
	for(auto &i:s)cnt[i-'a']++;
	int ans = 0;
	for(auto &i:cnt)ans = max(ans,i);
	for(int i = 1;i<=k;i++){
		if(k%i != 0)continue;
		if(n>=i)ans = max(ans,i);
	}
	for(int i = 1;i<=n;i++){
		if(k%i != 0)continue;
		for(int j = 1;j<=n;j++){
			int tans = 0;
			for(auto &kk:cnt)tans += kk/j;
			if(tans>=i)ans = max(ans,j*i);
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
