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
const ll mod = 1e9+7;

ll c[2][2];
void mult(ll a[2][2],ll b[2][2]){
	for(int i = 0;i<2;i++)for(int j = 0;j<2;j++)c[i][j] = 0;
	for(int i = 0;i<2;i++){
		for(int j = 0;j<2;j++){
			for(int k = 0;k<2;k++){
				c[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	for(int i = 0;i<2;i++)for(int j = 0;j<2;j++)c[i][j] %= mod;
	return;
}
int main(){
	io
	ll n;
	cin>>n;
	ll now[2][2] = {{1,0},{0,1}};
	ll p[2][2] = {{1,1},{1,0}};
	mult(now,p);
	n--;
	while(n != 0){
		if(n&1){
			mult(p,now);
			for(int i = 0;i<2;i++)for(int j= 0;j<2;j++)now[i][j] = c[i][j];
		}
		mult(p,p);
		for(int i = 0;i<2;i++)for(int j= 0;j<2;j++)p[i][j] = c[i][j];
		n>>=1;
	}
	cout<<(now[0][0]+now[0][1])%mod;
}

