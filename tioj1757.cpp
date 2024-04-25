#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 1e9+7;

inline ll mad(ll a,ll b){
	a+=b;
	return a>=mod?a-mod:a;
}

void solve(){
	ll k1,k2;
	cin>>k1>>k2;
	k1 %= mod,k2 %= mod;
	ll n;
	cin>>n;
	n-= 2;
	ll mat[2][2] = {{1,0},{0,1}};
	ll fib[2][2] = {{1,1},{1,0}};
	ll tmp[2][2];
	while(n){
		if(n&1){
			memset(tmp,0,sizeof(tmp));
			for(int i = 0;i<2;i++)for(int j = 0;j<2;j++)for(int k = 0;k<2;k++)tmp[i][j] = mad(tmp[i][j],fib[i][k]*mat[k][j]%mod);
			for(int i = 0;i<2;i++)for(int j = 0;j<2;j++)mat[i][j] = tmp[i][j];
		}
		memset(tmp,0,sizeof(tmp));
		for(int i = 0;i<2;i++)for(int j = 0;j<2;j++)for(int k = 0;k<2;k++)tmp[i][j] = mad(tmp[i][j],fib[i][k]*fib[k][j]%mod);
		for(int i = 0;i<2;i++)for(int j = 0;j<2;j++)fib[i][j] = tmp[i][j];
		n>>=1;
	}
	cout<<mad(mat[0][0]*k2%mod,mat[0][1]*k1%mod)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
