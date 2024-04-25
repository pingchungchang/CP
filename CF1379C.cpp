#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


const ll inf = 1e9+10;
void solve(){
	ll n,m;
	cin>>m>>n;
	pll arr[n];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	sort(arr,arr+n,greater<pll>());
	ll pref = 0;
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
