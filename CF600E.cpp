#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
int n;
vector<int> tree[mxn];
map<int,int> cnt[mxn];
map<int,ll> cntsum[mxn];
int arr[mxn];
ll ans[mxn];

void dfs(int now,int par){
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
		if(cnt[nxt].size()>cnt[now].size()){
			cnt[now].swap(cnt[nxt]);
			cntsum[now].swap(cntsum[nxt]);
		}
		for(auto &i:cnt[nxt]){
			cnt[now][i.fs] += i.sc;
			cntsum[now][cnt[now][i.fs]] += i.fs;
		}
	}
	ans[now] = cntsum[now].rbegin()->sc;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i],cntsum[i][1] = arr[i],cnt[i][arr[i]] = 1;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,1);
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}
