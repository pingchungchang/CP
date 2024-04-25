#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mod = 998244353;

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll inv(ll k){
	return pw(k,mod-2);
}
inline ll mad(ll a,ll b){
	a += b;
	if(a>=mod)a -= mod;
	return a;
}
inline ll mub(ll a,ll b){
	if(!b)return a;
	return mad(a,mod-b);
}

vector<vector<ll>> mul(vector<vector<ll>> a,vector<vector<ll>> b){
	vector<vector<ll>> re(a.size(),vector<ll>(b[0].size(),0));
	for(int i = 0;i<a.size();i++){
		for(int j = 0;j<b.size();j++){
			for(int k = 0;k<b[0].size();k++){
				re[i][k] = mad(re[i][k],a[i][j]*b[j][k]%mod);
			}
		}
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll k,m;
	cin>>k>>m;
	ll C[k],arr[k];
	for(auto &i:C)cin>>i;
	for(auto &i:arr)cin>>i;
	vector<vector<ll>> now(k,vector<ll>(k));
	auto p = now;
	for(int i = 0;i<k;i++)now[i][i] = 1;
	for(int i = 0;i<k-1;i++)p[i+1][i] = 1;
	for(int i = 0;i<k;i++)p[0][i] = C[i];
	m--;
	while(m){
		if(m&1)now = mul(now,p);
		p = mul(p,p);
		m>>=1;
		//cout<<m<<endl;
	}
	reverse(arr,arr+k);
	for(int i = 0;i<k;i++)now[i].push_back(arr[i]);
	for(int i = 0;i<k;i++){
		if(now[i][i] == 0){
			for(int j = i;j<k;j++){
				if(now[j][i] != 0){
					swap(now[i],now[j]);
					break;
				}
			}
		}
		assert(now[i][i]);
		ll c = inv(now[i][i]);
		for(int j = 0;j<=k;j++)now[i][j] = c*now[i][j]%mod;
		for(int j = i+1;j<k;j++){
			ll kk = now[j][i];
			for(int l = 0;l<=k;l++){
				now[j][l] = mub(now[j][l],now[i][l]*kk%mod);
			}
		}
	}
	/*
	for(int i = 0;i<k;i++){
		for(int j = 0;j<=k;j++)cout<<now[i][j]<<' ';
		cout<<endl;
	}

   */
	ll ans[k];
	for(int i = k-1;i>=0;i--){
		ll kk = now[i][i];
		ll c = now[i][k];
		for(int j = k-1;j>i;j--){
			c = mub(c,ans[j]*now[i][j]%mod);
		}
		ans[i] = c*inv(kk)%mod;
		//cout<<i<<":"<<c<<' '<<kk<<endl;
	}
	reverse(ans,ans+k);
	for(auto &i:ans)cout<<i<<' ';
	return 0;
}
