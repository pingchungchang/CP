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
const ll mod = 998244353;

int main(){
	io
	ll n;
	cin>>n;
	if(n>0)cout<<n%mod;
	else cout<<(mod-abs(n%mod))%mod;
}

