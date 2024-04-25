#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,a,b,h;
	cin>>n>>a>>b>>h;
	string s;
	cin>>s;
	ll ans = 0;
	for(auto &i:s){
		if(i == '0')ans += min(a,b+h);
		else ans += min(b,a+h);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
