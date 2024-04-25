#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	int cnt[101] = {};
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		cnt[k] = 1;
	}
	int ans =0;
	while(m--){
		int k;
		cin>>k;
		if(cnt[k])ans++;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
