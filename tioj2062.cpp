#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e6+10;
vector<int> paths[mxn];
int col[mxn];
int n,m;
vector<int> shiro,kuro;

bool dfs(int now,int c){
	if(col[now]){
		if(col[now] != c)return false;
		else return true;
	}
	bool flag = true;
	col[now] = c;
	for(auto nxt:paths[now]){
		flag = flag&&dfs(nxt,-c);
	}
	return flag;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		if(!col[i]&&!dfs(i,1)){
			cout<<"-1\n";
			return 0;
		}
	}
	for(int i = 1;i<=n;i++){
		if(col[i] == 1)shiro.push_back(i);
		else kuro.push_back(i);
	}
	cout<<shiro.size()<<' '<<kuro.size()<<'\n';
	for(auto &i:shiro)cout<<i<<' ';cout<<'\n';
	for(auto &i:kuro)cout<<i<<' ';cout<<'\n';
	return 0;
}
