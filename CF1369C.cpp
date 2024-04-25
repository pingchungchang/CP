#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,k;
	cin>>n>>k;
	ll arr[n],brr[k];
	for(auto &i:arr)cin>>i;
	for(auto &i:brr){
		cin>>i;
	}
	sort(brr,brr+k);
	sort(arr,arr+n);
	ll ans = 0;
	for(int i = 0;i<k;i++){
		ans += arr[n-1-i];
		if(brr[i] == 1)ans += arr[n-1-i];
	}
	int pt = 0;
	for(int i = k-1;i>=0;i--){
		if(brr[i] == 1)continue;
		ans += arr[pt];
		brr[i]--;
		while(brr[i]--)pt++;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
