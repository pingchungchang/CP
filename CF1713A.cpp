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
	ll n;
	cin>>n;
	pll x,y;x = y = make_pair(0,0);
	for(int i = 0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		if(a == 0){
			y.fs = max(y.fs,b);
			y.sc = min(y.sc,b);
		}
		else{
			x.fs = max(x.fs,a);
			x.sc = min(x.sc,a);
		}
	}
	cout<<(y.fs-y.sc+x.fs-x.sc)*2<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

