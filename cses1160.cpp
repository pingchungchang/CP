#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
vector<int> paths[mxn];
vector<pii> req[mxn];
bitset<mxn> vis;
int n,q;
int ans[mxn];
int dep[mxn],cid[mxn];
int arr[mxn];
int C;

void dfs(int now,int head){
	vis[now] = true;
	for(auto &i:req[now]){
		if(cid[i.fs]){
			int d = (cid[i.fs]-cid[head]+C)%C;
			ans[i.sc] = d+dep[now];
		}
		else if(dep[i.fs]){
			ans[i.sc] = dep[now]-dep[i.fs];
		}
	}
	for(auto &i:paths[now]){
		dep[i] = dep[now]+1;
		dfs(i,head);
	}
	dep[now] = 0;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		arr[i] = k;
		paths[k].push_back(i);
	}
	memset(ans,-1,sizeof(ans));
	for(int i = 0;i<q;i++){
		int a,b;
		cin>>a>>b;
		req[a].push_back({b,i});
	}
	for(int i = 1;i<=n;i++){
		if(vis[i])continue;
		C = 0;
		int now = i;
		do{
			vis[now] = true;
			now = arr[now];
		}while(!vis[now]);
		int s = now;
		do{
			cid[now] = ++C;
			now = arr[now];
		}while(now != s);
		do{
			for(auto nxt:paths[now]){
				if(!cid[nxt])dep[nxt] = 1,dfs(nxt,now);
			}
			for(auto &i:req[now]){
				if(cid[i.fs])ans[i.sc] = (cid[i.fs]+C-cid[now])%C;
			}
			now = arr[now];
		}while(now != s);
		do{
			cid[now] = 0;
			now = arr[now];
		}while(now != s);
	}
	for(int i = 0;i<q;i++)cout<<ans[i]<<'\n';
	return 0;
}
