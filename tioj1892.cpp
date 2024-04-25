#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#define ll int
//#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 110;
const ll mod = 1e9+7;


inline int mad(int a,int b){
	a += b;
	return a>=mod?a-mod:a;
}

int re[mxn][mxn],now[mxn][mxn],mat[32][mxn][mxn];
int arr[mxn];

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	int m;
	cin>>m;
	for(int i = 0;i<n;i++)mat[0][i][i] = 1;
	for(int i =0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(a != b)mat[0][b][a] = mad(mat[0][b][a],c);
	}
	for(int i = 1;i<31;i++){
		for(int j = 0;j<n;j++){
			for(int k = 0;k<n;k++){
				for(int l = 0;l<n;l++){
					mat[i][j][k] = mad(mat[i][j][k],1LL*mat[i-1][j][l]*mat[i-1][l][k]%mod);
				}
			}
		}
	}
	/*
	auto rr = mul(mat,arr);
	for(int i = 0;i<n;i++){
		for(auto &j:rr[i])cout<<j<<' ';cout<<endl;
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++)cout<<mat[i][j]<<' ';cout<<endl;
	}
	cout<<endl<<endl;

   */
	int q;
	cin>>q;
	while(q--){
		int k;
		cin>>k;
		memset(now,0,sizeof(now));
		for(int i = 0;i<n;i++)now[i][i] = 1;
		for(int c = 0;c<31;c++){
			if(k&(1<<c)){
				memset(re,0,sizeof(re));
				for(int i = 0;i<n;i++){
					for(int j = 0;j<n;j++){
						for(int l = 0;l<n;l++){
							re[i][j] = mad(re[i][j],1LL*mat[c][i][l]*now[l][j]%mod);
						}
					}
				}
				for(int i = 0;i<n;i++)for(int j = 0;j<n;j++)now[i][j] = re[i][j];
			}
		}
		/*
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++)cout<<now[i][j]<<' ';cout<<endl;
		}

	   */
		for(int i = 0;i<n;i++){
			ll tans = 0;
			for(int j = 0;j<n;j++){
				tans = mad(tans,1LL*now[i][j]*arr[j]%mod);
			}
			cout<<tans<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
