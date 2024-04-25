#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int x,y;
	cin>>x>>y;
	if(x>y)swap(x,y);
	if(y-x<=1)cout<<x+y<<'\n';
	else{
		int ans = x*2;
		y -= x;
		if(y&1)ans += y*2-1;
		else ans += y*2-1;
		cout<<ans<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
