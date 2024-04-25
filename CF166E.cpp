#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mod = 1e9+7;

struct mat{
	ll val[4][4];
	mat(vector<vector<ll>> v){
		for(int i = 0;i<4;i++)for(int j = 0;j<4;j++)val[i][j] = v[i][j];
	}
	mat(){
		for(auto &i:val)for(auto &j:i)j = 0;
		return;
	}
	ll* operator[](int k){
		return val[k];
	}
	mat operator*(mat b){
		mat re = mat();
		for(int i = 0;i<4;i++){
			for(int j = 0;j<4;j++){
				for(int k = 0;k<4;k++){
					re[i][j] += val[i][k]*b[k][j]%mod;
				}
			}
		}
		for(int i = 0;i<4;i++)for(int j= 0;j<4;j++)re[i][j] %= mod;
		return re;
	}
};

void solve(){
	mat now = mat({{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}});
	mat p = mat();
	for(int i = 0;i<4;i++)for(int j = 0;j<4;j++)if(i != j)p[i][j] = 1;
	ll n;
	cin>>n;
	while(n){
		if(n&1)now = now*p;
		p = p*p;
		n>>=1;
	}
	cout<<now[0][0];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
