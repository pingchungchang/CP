#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 50505;
int n;
vector<int> tree[mxn];
int ans[mxn];
int ppp = 0;
void dfs(int now){
	ans[now] = ++ppp;
	for(auto nxt:tree[now]){
		if(!ans[nxt])dfs(nxt);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		int s;
		cin>>s;
		while(s--){
			int k;
			cin>>k;
			tree[i].push_back(k);
		}
	}
	dfs(1);
	for(int i = 1;i<=n;i++)cout<<ans[i]<<'\n';
	return 0;
}
