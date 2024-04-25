#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 303;
ll ans= 0;
vector<pii> pos[mxn];
int arr[mxn][mxn],pref[mxn][mxn],sum[mxn][mxn];
int n,m;

ll calc(){
	memset(pref,0,sizeof(pref));
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(!arr[i][j])pref[i][j] =0;
			else pref[i][j] = pref[i-1][j]+1;
		}
	}
	/*
	for(int i = 1;i<=n;i++){
		for(int j= 1;j<=m;j++)cout<<pref[i][j]<<' ';cout<<'\n';
	}

   */
	ll re = 0;
	for(int i = 1;i<=n;i++){
		deque<int> dq = {0};
		int pre[m+1] = {};
		ll ans[m+1];
		memset(ans,0,sizeof(ans));
		for(int j = 1;j<=m;j++){
			while(!dq.empty()&&pref[i][dq.back()]>=pref[i][j]){
				dq.pop_back();
			}
			if(dq.empty())dq.push_back(0);
			pre[j] = dq.back();
			dq.push_back(j);
		}
		for(int j = 1;j<=m;j++){
			ans[j] = sum[i][j]-sum[i][pre[j]]-sum[i-pref[i][j]][j]+sum[i-pref[i][j]][pre[j]];
		}
		dq = {m+1};
		for(int j = m;j>=1;j--){
			while(!dq.empty()&&pref[i][dq.back()]>=pref[i][j])dq.pop_back();
			if(dq.empty())dq.push_back(n+1);
			pre[j] = dq.back()-1;
			dq.push_back(j);
		}
		for(int j = 1;j<=m;j++){
			int p = pre[j];
			ans[j] += sum[i][p]-sum[i-pref[i][j]][p]-sum[i][j]+sum[i-pref[i][j]][j];
			re = max(re,ans[j]);
		}
		//for(int j = 1;j<=m;j++)cout<<ans[j]<<' ';cout<<'\n';
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			int k;
			cin>>k;
			pos[k].push_back({i,j});
		}
	}
	for(int i= mxn-1;i>=0;i--){
		for(auto &j:pos[i])arr[j.fs][j.sc] = i;
		for(int j = 1;j<=n+1;j++)for(int k = 1;k<=m+1;k++)
			sum[j][k] = arr[j][k]+sum[j][k-1]+sum[j-1][k]-sum[j-1][k-1];
		//cout<<i<<":"<<'\n';
		ans = max(ans,1LL*i*calc());
	}
	cout<<ans;
}
