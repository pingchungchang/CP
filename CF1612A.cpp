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
	ll n,m;
	cin>>n>>m;
	if((n+m)&1){
		cout<<"-1 -1\n";
	}
	else if(n>m){
		cout<<(n+m)/2<<' '<<0<<'\n';
	}
	else{
		cout<<0<<' '<<(n+m)/2<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

