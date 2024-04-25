#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 5e5+10;
vector<int> tree[mxn];
int dfn[mxn],pt;
int N;
vector<pii> ans;

void dfs(int now,int par){
	dfn[now] = ++pt;
	for(auto nxt:tree[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
	}
	return;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 1;i<N;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,1);
	vector<pii> v;
	for(int i = 1;i<=N;i++){
		if(tree[i].size() == 1)v.push_back(pii(dfn[i],i));
	}
	sort(v.begin(),v.end());
	for(int i = 0;i<v.size()/2;i++){
		ans.push_back(pii(v[i].sc,v[i+v.size()/2].sc));
	}
	if(v.size()&1)ans.push_back(pii(v.back().sc,v[0].sc));
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return 0;
}
