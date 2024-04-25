#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

using mint = atcoder::modint998244353;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ll arr[n];
	ll pref[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	pref[0] = arr[0];
	for(int i = 1;i<n;i++)pref[i] = pref[i-1]+arr[i];
	mint ans = 0;
	for(int i = 1;i<n;i++){
		ll tans = 0;
		ll C = pref[i-1];
		tans += atcoder::floor_sum(arr[i]+1,n,n-i,pref[i-1]);
		tans -= atcoder::floor_sum(arr[i-1]+1,n,n-i,pref[i-1]);
		ans += tans;
	}
	ans += arr[n-1]+1;
	cout<<ans.val();
}
