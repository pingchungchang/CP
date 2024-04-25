#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

void solve(){
	ll a,b,c,p;
	cin>>p>>a>>b>>c;
	cout<<min({(p+a-1)/a*a,(p+b-1)/b*b,(p+c-1)/c*c})-p<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

