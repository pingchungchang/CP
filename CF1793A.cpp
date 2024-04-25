#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	ll a,b,n,m;
	cin>>a>>b>>n>>m;
	ll ans = 0;
	if(a*m<=b*(m+1))ans += n/(m+1)*m*a,n %= m+1;
	ans += n*(min(a,b));
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
