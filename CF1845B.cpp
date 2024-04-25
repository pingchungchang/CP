#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	pii a,b,c;
	cin>>a.fs>>a.sc>>b.fs>>b.sc>>c.fs>>c.sc;
	b = {b.fs-a.fs,b.sc-a.sc};
	c = {c.fs-a.fs,c.sc-a.sc};
	int ans = 1;
	if(b.fs>0&&c.fs>0)ans += min(b.fs,c.fs);
	else if(b.fs<0&&c.fs<0)ans += min(-b.fs,-c.fs);
	if(b.sc>0&&c.sc>0)ans += min(b.sc,c.sc);
	else if(b.sc<0&&c.sc<0)ans += min(-b.sc,-c.sc);
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
