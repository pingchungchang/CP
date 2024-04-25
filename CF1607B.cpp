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
	ll x,n;
	cin>>x>>n;
	if(x&1){
		if(n%4 >= 1)x += n/4*4+1;
		if(n%4 >= 2)x -= n/4*4+2;
		if(n%4 >= 3)x -= n/4*4+3;
		cout<<x<<'\n';
	}
	else{
		if(n%4>=1)x -= n/4*4+1;
		if(n%4>=2)x += n/4*4+2;
		if(n%4>=3)x += n/4*4+3;
		cout<<x<<'\n';
	}
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

