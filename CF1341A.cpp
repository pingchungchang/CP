#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	ll ta = (a-b)*n,tb = (a+b)*n;
	if(ta>c+d||tb<c-d)cout<<"No\n";
	else cout<<"Yes\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
