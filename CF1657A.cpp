#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	ll x,y;
	cin>>x>>y;
	ll d = sqrt(x*x+y*y);
	if(x == 0&&y == 0)cout<<0<<'\n';
	else if(d*d == x*x+y*y){
		cout<<1<<'\n';
	}
	else cout<<2<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

