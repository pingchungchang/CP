#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int cnt[32] = {};
	ll ans = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		for(int j = 30;i>=0;j--){
			if((1<<j)&k){
				ans += cnt[j];
				cnt[j]++;
				break;
			}
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
