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
const ll mxn = 5e6+10;
int main(){
	ll n;
	cin>>n;
	vector<ll> lpf(mxn,0LL);
	for(ll i = 2;i<mxn;i++){
		if(lpf[i] == 0){
			lpf[i] = 1;
			for(ll j = i*2;j<mxn;j+= i){
				if(lpf[i] == 0)lpf[i] = i;
			}
		}
	}
	
}

