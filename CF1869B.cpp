#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,k,a,b;
	cin>>n>>k>>a>>b;
	a--,b--;
	pll arr[n];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	ll toc = 1e18;
	for(int i = 0;i<k;i++){
		toc = min(toc,abs(arr[i].fs-arr[a].fs)+abs(arr[i].sc-arr[a].sc));
	}
	ll ans = abs(arr[a].fs-arr[b].fs)+abs(arr[a].sc-arr[b].sc);
	for(int i = 0;i<k;i++){
		ans = min(ans,toc+abs(arr[i].fs-arr[b].fs)+abs(arr[i].sc-arr[b].sc));
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
