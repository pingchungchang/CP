#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,p,k;
	cin>>n>>p>>k;
	vector<ll> sum[k];
	ll arr[n+1];
	arr[0] = 0;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	sort(arr+1,arr+n+1);
	for(int i = 0;i<k;i++){
		sum[i].push_back(0LL);
		for(int j = i+k;j<=n;j+=k)if(j)sum[i].push_back(sum[i].back()+arr[j]);
	}
	ll pref[n+1];
	pref[0] = arr[0];
	for(int i = 1;i<=n;i++)pref[i] = pref[i-1]+arr[i];
	ll ans = 0;
	/*
	for(int i = 0;i<k;i++){
		cout<<i<<":";for(auto &j:sum[i])cout<<j<<',';cout<<'\n';
	}

   */
	for(int i = 0;i<k;i++){
		auto it = upper_bound(sum[i].begin(),sum[i].end(),p-pref[i]);
		if(it != sum[i].begin())it--;
		else continue;
		//cout<<p-pref[i]<<":"<<*it<<' '<<'\n';
		ans = max(ans,k*(it-sum[i].begin())+i);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
