#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll mod = 1e9+7;
vector<vector<ll>> mat;
vector<vector<ll>> mult(vector<vector<ll>> a,vector<vector<ll>> b){
	vector<vector<ll>> returns(2,vector<ll>(2,0));
	for(ll i = 0;i<2;i++){
		for(ll j =0;j<2;j++){
			for(ll k = 0;k<2;k++){
				returns[i][j] += a[i][k]%mod*b[k][j]%mod;
			}
			returns[i][j]%= mod;
		}
	}
	return returns;
}
ll f(ll x1,ll x2,ll n){
	vector<vector<ll>> now = {{1,0},{0,1}};
	while(n != 0){
		if((n&1)){
			now = mult(mat,now);
		}
		n>>=1;
		mat = mult(mat,mat);
	}
	return (now[1][1]*x1+now[1][0]*x2)%mod;
}
int main(){
	ll x1,x2,a,b,n;
	cin>>x1>>x2>>a>>b>>n;
	n--;
	mat = {{b,a},{1LL,0LL}};
	cout<<f(x1,x2,n);
}

