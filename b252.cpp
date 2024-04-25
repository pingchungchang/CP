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
#define vi vector<ll>
#define vvi vector<vi>
const ll mod = 100000007;

ll buf[2][2];

vector<vector<ll>> mult(vector<vector<ll>>&a,vector<vector<ll>> &b){
	vvi re(2,vi(2,0));
	for(int i = 0;i<2;i++){
		for(int j= 0;j<2;j++){
			for(int k = 0;k<2;k++){
				re[i][j] += a[i][k]*b[k][j];
				re[i][j] %= mod;
			}
		}
	}
	return re;
}
ll a,b,c;
void solve(){
	vvi now = {{1,0},{0,1}};
	vvi pw = {{0,1},{1,1}};
	while(c>0){
		if(c&1){
			now = mult(now,pw);
		}
		pw = mult(pw,pw);
		c>>=1;
	}
	ll ans= (a*(now[0][0]+now[0][1])+b*(now[1][0]+now[1][1]))%mod;
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	while(cin>>a>>b>>c)solve();
}

