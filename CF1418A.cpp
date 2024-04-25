#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll x,y,k;
	cin>>x>>y>>k;
	ll tar = k+k*y;
	cout<<(tar-1+x-2)/(x-1)+k<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
