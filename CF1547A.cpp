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
	if(a.fs == b.fs&&a.fs == c.fs&&min(a.sc,b.sc)<c.sc&&max(a.sc,b.sc)>c.sc)cout<<abs(a.sc-b.sc)+2<<'\n';
	else if(a.sc == b.sc&&a.sc == c.sc&&min(a.fs,b.fs)<c.fs&&max(a.fs,b.fs)>c.fs)cout<<abs(a.fs-b.fs)+2<<'\n';
	else cout<<abs(a.fs-b.fs)+abs(a.sc-b.sc)<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
