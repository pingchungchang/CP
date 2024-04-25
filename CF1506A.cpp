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
#define int ll
void solve(){
	int n,m,x;
	cin>>n>>m>>x;
//	x--;
	swap(n,m);
	int r = (x-1)/m+1;
	int c = x%m;
	if(c == 0)c = m;
//	cout<<r<<' '<<c<<',';
	cout<<(c-1)*n+r<<'\n';
}
main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

