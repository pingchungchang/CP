#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	cin>>n;
	ll cnt[n+1] = {};
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		cnt[k]++;
	}
	ll ans = 0;
	for(int i = 0;i<=n;i++){
		ans += 1ll*cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
		if(i)ans += 1ll*cnt[i]*(cnt[i]-1)/2*cnt[i-1];
		if(i)cnt[i] += cnt[i-1];
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
