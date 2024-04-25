#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll n,m,k;
	cin>>n>>m>>k;
	ll arr[n],brr[m];
	for(auto &i:arr)cin>>i;
	for(auto &i:brr)cin>>i;
	sort(arr,arr+n);
	sort(brr,brr+m);
	if(arr[0]<brr[m-1]){
		swap(arr[0],brr[m-1]);
		sort(arr,arr+n);
		sort(brr,brr+m);
	}
	k--;
	if(k&1)swap(brr[0],arr[n-1]);
	ll ans = 0;
	for(auto &i:arr)ans += i;
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
