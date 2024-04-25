#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 1e6+10;
const ll mod = 1e9+7;
int lpf[mxn];

vector<vector<int>> mat;

int mad(int a,int b){
	a += b;
	if(a>=mod)a -= mod;
	return a;
}

vector<vector<int>> I(int s){
	vector<vector<int>> re(s,vector<int>(s,0));
	for(int i = 0;i<s;i++){
		re[i][i] = 1;
	}
	return re;
}

inline void mul(vector<vector<int>> &a,vector<vector<int>> b){
	vector<vector<int>> re(a.size(),vector<int>(b[0].size()));
	int s1 = a.size(),s2 = b[0].size(),s3 = b.size();
	for(int i = 0;i<s1;i++){
		for(int j = 0;j<s2;j++){
			for(int k = 0;k<s3;k++){
				re[i][j] = mad(re[i][j],1LL*a[i][k]*b[k][j]%mod);
			}
		}
	}
	a = re;
}

int solve(){
	int k;
	cin>>k;
	auto kk = k;
	unordered_map<int,int> mp;
	while(k!= 1){
		mp[lpf[k]]++;
		k/=lpf[k];
	}
	int re = 1;
	for(auto &i:mp){
		int now = 1;
		int tmp = 0;
		for(int j = 0;j<=i.sc;j++){
			tmp = mad(tmp,1LL*now*mat[i.sc][j]%mod);
			now = 1LL*now*i.fs%mod;
		}
		re = 1LL*re*tmp%mod;
	}
	//cout<<kk<<":"<<re<<'\n';
	return re;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,t;
	cin>>t>>n;
	lpf[0] = lpf[1] = 1;
	for(int i = 2;i<mxn;i++){
		if(!lpf[i]){
			for(int j = i;j<mxn;j+=i)lpf[j] = i;
		}
	}
	mat = I(22);
	auto tmp = mat;
	for(int i = 0;i<22;i++){
		for(int j = 0;j<i;j++){
			tmp[i][j] = 1;
		}
	}
	while(n){
		if(n&1)mul(mat,tmp);
		mul(tmp,tmp);
		n>>=1;
	}
	/*
	for(int i = 0;i<=10;i++){
		for(int j = 0;j<=10;j++)cout<<mat[i][j]<<' ';cout<<endl;
	}

   */
	int ans = 0;
	while(t--)ans = mad(ans,solve());
	cout<<ans;
}
