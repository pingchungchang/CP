#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct node{
	int pos;
	int sp;
	int times;
	node(){
		pos = 0;
		sp = 0;
		times = 0;
	}
	node(int a,int b,int c){
		pos = a;
		sp = b;
		times = c;
	}
};
const ll mod = 998244353;
int main(){
	int n,m,k,s,t,x;
	cin>>n>>m>>k>>s>>t>>x;
	vector<vector<int>> v(n+1);
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	ll dp[2][2][n+1];
	memset(dp,0,sizeof(dp));
	dp[0][0][s] = 1;
	int a = 1;
	for(int i = 0;i<=k;i++){
		memset(dp[a],0,sizeof(dp[a]));
//		for(int j = 0;j<2;j++){
//			for(int l = 1;l<=n;l++)cout<<dp[1-a][j][l]<<' ';
//			cout<<endl;
//		}
//		cout<<endl;
		for(int j = 0;j<2;j++){
			for(int now = 1;now<=n;now++){
				for(auto nxt:v[now]){
					int kk = j;
					if(nxt == x)kk = 1-kk;
					dp[a][kk][nxt] = (dp[a][kk][nxt]+dp[1-a][j][now])%mod;
				}
			}
		}
		a = 1-a;
	}
	cout<<dp[a][0][t];
}

