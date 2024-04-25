#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
ll n,q,k;
vector<ll> v;
vector<ll> diff;
void solve(){
	ll s,e;
	cin>>s>>e;
	cout<<k+diff[e]-diff[s]-(e-s+1)<<'\n';
	return;
}
int main(){
	io
	cin>>n>>q>>k;
	v = vector<ll>(n+1,0);
	diff = vector<ll>(n+1,0);
	for(int i = 1;i<=n;i++)cin>>v[i];
	for(int i = 2;i<=n;i++)diff[i] = diff[i-1]+v[i]-v[i-1]-1;
//	for(int i = 0;i<=n;i++)cout<<diff[i]<<'.';cout<<'\n';
	while(q--)solve();
}

