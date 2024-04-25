#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,k,x;
	cin>>n>>k>>x;
	ll small = k*(k+1)/2,big = (n+n-k+1)*k/2;
	if(big>=x&&small<=x)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
