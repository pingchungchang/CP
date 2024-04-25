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
	ll n,m,x,y,dist;
	cin>>n>>m>>x>>y>>dist;
	bool l = 0,u = 0,r = 0,d = 0;
	if(x+dist>=n)d = true;
	if(x-dist<=1)u = true;
	if(y+dist>=m)r = true;
	if(y-dist<=1)l = true;
	if((l&&u)||(l&&r)||(u&&d)||(d&&r))cout<<"-1\n";
	else cout<<(n+m-2)<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

