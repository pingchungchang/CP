#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e4+10;
int arr[mxn];
vector<pii> tree[mxn];
int sz[mxn],dp[mxn];
int range[mxn];
int pt = 1;

void dfs1(int l,int r,int now){
	sz[now] = 0;
	for(int i = l;i<=r;i++){
		if(arr[i]){
			int pl = i;
			int pr = i;
			int s = 0;
			for(int j = i;j<=r;j++){
				//cout<<j<<":"<<arr[j]<<',';
				if(arr[j])pr = j,sz[now]++;
				else break;
			}
			int small = *min_element(arr+pl,arr+pr+1);
			for(int j = pl;j<=pr;j++){
				arr[j] -= small;
			}
			tree[now].push_back({++pt,small});
			range[pt] = pr-pl+1;
			dfs1(pl,pr,pt);
			i = pr+1;
		}
	}
	return;
}

void dfs(int now){
	dp[now] = sz[now];
	for(auto nxt:tree[now]){
		dfs(nxt.fs);
		//cout<<now<<' '<<nxt.fs<<' '<<nxt.sc<<' '<<sz[nxt.fs]<<' '<<dp[nxt.fs]<<'\n';
		dp[now] = min(dp[now],dp[now]-range[nxt.fs]+dp[nxt.fs]+nxt.sc);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	int c = 0;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++)if(arr[i])c++;
	dfs1(1,n,1);
	sz[1] = c;
	range[1] = c;
	dfs(1);
	cout<<dp[1];
}
