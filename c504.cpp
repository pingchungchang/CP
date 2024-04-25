#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mod = 1e9+7;
inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-=mod:a;
}

vector<vector<ll>> mul(vector<vector<ll>> a,vector<vector<ll>> b){
	vector<vector<ll>> re(a.size(),vector<ll>(b[0].size(),0));
	for(int i = 0;i<a.size();i++){
		for(int j = 0;j<b.size();j++){
			for(int k = 0;k<b[0].size();k++)re[i][k] = mad(re[i][k],a[i][j]*b[j][k]%mod);
		}
	}
	return re;
}

void solve(){
	vector<vector<ll>> now = {{1,0},{0,1}};
	vector<vector<ll>> p = {{0LL,1LL},{4LL,4LL}};
	ll n;
	cin>>n;
	while(n){
		if(n&1)now = mul(now,p);
		/*
		for(int i = 0;i<2;i++){
			for(int j = 0;j<2;j++)cout<<now[i][j]<<' ';cout<<endl;
		}
	   */
		n>>=1;
		p = mul(p,p);
	}
	cout<<(now[0][1]+now[1][1])%mod<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
