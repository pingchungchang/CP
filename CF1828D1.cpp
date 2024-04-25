#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	ll ans = 0;
	for(ll i = 1;i<=n;i++)ans += (i-1)*(n-i+1);
	//cout<<ans<<":\n";
	int arr[n];
	for(auto &i:arr)cin>>i;
	ll sh = 0;
	for(int i = 1;i<n;i++){
		if(arr[i]<arr[i-1])continue;
		ll l = i-1,r = i;
		for(;l>=0&&arr[l]<=max(arr[i],arr[i-1]);l--);
		for(;r<n&&arr[r]>=min(arr[i],arr[i-1]);r++);
		vector<int> pref;
		pref.push_back(arr[i]);
		for(int j = i+1;j<r;j++)pref.push_back(arr[j]),pref.back() = min(pref.back(),pref[pref.size()-2]);
		//cout<<i<<":";
		//for(auto &ii:pref)cout<<ii<<' ';cout<<'\n';
		int sm = arr[i-1];
		int pt = pref.size()-1;
		for(int j = i-1;j>l;j--){
			sm = max(sm,arr[j]);
			while(pt>0&&sm>=pref[pt])pt--;
			ans -= pt+1;
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
