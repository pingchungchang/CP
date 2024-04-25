#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int cnt[2] = {};
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		cnt[abs(k)&1]++;
	}
	int m;
	cin>>m;
	ll ans = 0;
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		ans += cnt[abs(k)&1];
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
