#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

int n,k;
const int mxn = 1e6+10;
vector<int> paths[mxn];
int dp[mxn];
int fa[mxn];
int dep[mxn];
int cnt = 0;
int tar;
void dfs(int now){
	dep[now] = 1;
	for(auto nxt:paths[now]){
		if(nxt == fa[now])continue;
		if(!fa[nxt])fa[nxt] = now;
		dfs(nxt);
		dep[now] = max(dep[now],dep[nxt]+1);
	}
	if(dep[now]>tar){
		cnt++;
		dep[now] = 0;
	}
	return;
}
int main(){
	io
	int tttttt;
	cin>>n>>tttttt>>k;
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	int l = 0,r = n;
	while(l != r){
		int mid = (l+r)>>1;
		tar = mid;
		cnt = 0;
		dfs(1);
		if(dep[1] != 0){
			pii big = {dep[1],dep[1]};
			for(auto nxt:paths[1]){
				big.fs = max(big.fs,dep[nxt]+1);
				big.sc = min(big.sc,dep[nxt]);
			}
			if(big.fs+big.sc>mid)cnt++;
		}
		if(cnt<=k)r = mid;
		else l = mid+1;
	}
	cout<<l;
}

