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
int main(){
	io
	ll n,x;
	cin>>n;
	pll v[n];
	for(auto &i:v)cin>>i.fs>>i.sc;
	cin>>x;
	ll ans = 0;
	for(auto &i:v){
		ans = max(ans,i.fs*x+i.sc);
	}
	cout<<ans;
}

