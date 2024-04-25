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
	ll n,k;
	cin>>n>>k;
	vector<pll> v(n);
	for(auto &i:v)cin>>i.fs;
	for(auto &i:v)cin>>i.sc;
	ll ans = 0;
	for(int i = n-1;i>=0;i--){
		if(v[i].fs*v[i].sc>=k){
			ans += k/v[i].fs;
			k %= v[i].fs;
		}
		else{
			ans += v[i].sc;
			k -= v[i].fs*v[i].sc;
		}
	}
	cout<<ans;
}

