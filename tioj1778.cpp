#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 110;
const ll mod = 1000000009;
ll mat[mxn][mxn];
ll now[mxn][mxn];
ll tmp[mxn][mxn];

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m,s,t,k;
	cin>>n>>m>>s>>t>>k;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		mat[a][b] = mad(mat[a][b],1);
		mat[b][a] = mad(mat[b][a],1);
	}
	for(int i = 1;i<=n;i++)now[i][i] = 1;
	while(k){
		if(k&1){
			memset(tmp,0,sizeof(tmp));
			for(int i = 1;i<=n;i++){
				for(int j= 1;j<=n;j++){
					for(int l = 1;l<=n;l++){
						tmp[i][j] = mad(tmp[i][j],mat[i][l]*now[l][j]%mod);
					}
				}
			}
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=n;j++)now[i][j] = tmp[i][j];
			}
		}
		memset(tmp,0,sizeof(tmp));
		for(int i = 1;i<=n;++i){
			for(int j = 1;j<=n;j++){
				for(int l = 1;l<=n;l++){
					tmp[i][j] = mad(tmp[i][j],mat[i][l]*mat[l][j]%mod);
				}
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++)mat[i][j] = tmp[i][j];
		}
		k>>=1;
	}
	/*
	for(int i= 1;i<=n;i++){
		for(int j = 1;j<=n;j++)cout<<now[i][j]<<' ';
		cout<<endl;
	}

   */
	cout<<now[s][t];
}
