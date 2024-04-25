#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int x,k;
	cin>>x>>k;
	if(x%k != 0)cout<<1<<'\n'<<x<<'\n';
	else cout<<2<<'\n'<<1<<' '<<x-1<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
