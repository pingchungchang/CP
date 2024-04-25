#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll x,x1,x2,y1,y2,y;
	cin>>x>>y>>x1>>y1>>x2>>y2;
	ll dx = b-a,dy = d-c;
	if(x1 == x2&&a+b != 0)cout<<"NO\n";
	else if(y1 == y2&&c+d != 0)cout<<"NO\n";
	else if(x+dx<=x2&&x+dx>=x1&&y+dy<=y2&&y+dy>=y1)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
