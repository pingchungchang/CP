#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
int main(){
	ll n,m;
	cin>>n>>m;
	vector<ll> v(m,1);
	vector<ll> v2 = v;
	ll x;
	cin>>x;
	x--;
	if(x != -1){
		v = vector<ll>(m,0);
		v[x] = 1;
		v2 = v;
	}
	for(ll i =1;i<n;i++){
		ll k;
		cin>>k;
		k--;
		if(k == -1){
			v[0] = v2[1]+v2[0];
			v[0]%=mod;
			for(ll j =1;j<m-1;j++){
				v[j]=v2[j]+v2[j-1]+v2[j+1];
				v[j]%= mod;
			}
			v[m-1] =v2[m-1]+v2[m-2];
			v[m-1]%=mod;
			v2 = v;
		}
		else{
			v = vector<ll>(m,0);
			if(k==0)v[k] = v2[k]+v2[k+1];
			else if(k == m-1)v[k] = v2[k]+v2[k-1];
			else{
				v[k] = v2[k]+v2[k+1]+v2[k-1];
			}
			v[k]%=mod;
			v2 = v;
		}
	}
	ll ans =0;
	for(ll i =0;i<m;i++){
		ans += v[i];
		ans %=mod;
	}
	cout<<ans;
}
