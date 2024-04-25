#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


vector<ll> v = {1};
void solve(){
	ll n,k;
	cin>>n>>k;
	ll mx;
	if(k>32)mx = 2e9;
	else mx = 1LL<<k;
	mx--;
	//cout<<mx<<','<<n;
	if(mx>=n)cout<<n+1<<'\n';
	else cout<<mx+1<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 1;i<32;i++)v.push_back(v.back()<<1);
	int t;cin>>t;
	while(t--)solve();
}
