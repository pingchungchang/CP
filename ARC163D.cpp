#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define fs first
#define sc second
const ll mod = 998244353;

const int mxn = 31;
ll dp[2][mxn][mxn][mxn][2];

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
inline ll mub(ll a,ll b){
	if(!b)return a;
	return mad(a,mod-b);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	bool roll = 0;
	for(int i = 1;i<=n;i++)dp[roll][0][i][i][0] = dp[roll][0][i][i][1] = 1;
	for(int a = 1;a<=n;a++){
		for(int b = i+1;b<=n;b++){
			roll ^= 1;
			memset(dp[roll],0,sizeof(dp[roll]));
			for(int cnt = 0;cnt<=m;cnt++){
				for(int ta = 1;ta<=n;ta++){
					for(int tb = 1;tb<=n;tb++){
						dp[roll][cnt][ta][tb][1] = mad(dp[roll^1][cnt][ta][tb][1],);
					}
				}
			}
		}
	}
}
