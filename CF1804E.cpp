#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 20;
int par[mxn];
int paths[mxn][mxn];
int n,m;
int ans[mxn];
int dp[mxn][1<<mxn];
pair<int,int> pre[mxn][1<<mxn];
bitset<mxn> vis;
int s;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		paths[a][b] = paths[b][a] = 1;
	}
	for(auto &i:pre)for(auto &j:i)j = {-1,-1};
	for(int i = 0;i<n;i++){
		dp[i][1<<i] = 1;
	}
	for(int i = 1;i<(1<<n);i++){
		int low = 0;
		while(!(i&(1<<low)))low++;
		for(int j = low;j<n;j++){
			for(int k = low+1;k<n;k++){
				if(!paths[j][k]||(i&(1<<k))||!(i&(1<<j))||!dp[j][i])continue;
				//cout<<j<<','<<k<<endl;
				dp[k][i^(1<<k)] = 1;
				pre[k][i^(1<<k)] = {j,i};
			}
		}
		//cout<<i<<":"<<low<<":";for(int j = 0;j<n;j++)cout<<dp[j][i]<<' ';cout<<'\n';
	}
	for(int i = (1<<n)-1;i>=1;i--){
		bool flag = true;
		vis.reset();
		int low = 0;
		while(!(i&(1<<low)))low++;
		for(int j = 0;j<n;j++){
			for(int k = 0;k<n;k++){
				if(paths[j][k]&&(i&(1<<k)))vis[j] = true,ans[j] = k;
			}
		}
		if(vis.count() != n)continue;
		pii now = {-1,-1};
		for(int j = 0;j<n;j++){
			if(dp[j][i]&&paths[j][low])now = {j,i};
		}
		if(now.fs == -1)continue;
		//cout<<i<<":"<<now.fs<<','<<now.sc<<endl;
		ans[now.fs] = low;
		while(now.fs != -1){
			//cout<<now.fs<<','<<now.sc<<endl;
			ans[pre[now.fs][now.sc].fs] = now.fs;
			now = pre[now.fs][now.sc];
		}
		cout<<"YES\n";
		for(int j = 0;j<n;j++)cout<<ans[j]+1<<' ';
		exit(0);
	}
	cout<<"NO\n";
	return 0;
}
