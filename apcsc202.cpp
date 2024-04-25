#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double


const ll mxn= 10+1e6;
set<ll> primes;
bitset<mxn> all;
void solve(){
	ll k;
	cin>>k;
	if(primes.find(k) != primes.end())cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	io
	for(int i = 2;i<mxn;i++){
		if(!all[i]){
			primes.insert(i);
			for(ll j = 2;j*i<mxn;j++)all[j*i] = true;
		}
	}
	int t;
	cin>>t;
	while(t--)solve();
}

