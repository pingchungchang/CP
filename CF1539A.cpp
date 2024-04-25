#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll n,x,t;
	cin>>n>>x>>t;
	ll tmp = t/x;
	tmp = min(tmp,n);
	cout<<max(0LL,(t/x)*(n-tmp))+tmp*(tmp-1)/2<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
