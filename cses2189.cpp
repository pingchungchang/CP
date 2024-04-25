#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll cross(pll x,pll y){
	return x.fs*y.sc-y.fs*x.sc;
}
void solve(){
	pll a,b,c;
	cin>>a.fs>>a.sc>>b.fs>>b.sc>>c.fs>>c.sc;
	pll v1 = make_pair(b.fs-a.fs,b.sc-a.sc);
	pll v2 = make_pair(c.fs-a.fs,c.sc-a.sc);
	ll cr = cross(v1,v2);
	if(cr == 0)cout<<"TOUCH\n";
	else if(cr<0)cout<<"RIGHT\n";
	else cout<<"LEFT\n";
	return;
}

int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

