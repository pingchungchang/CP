#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const int mxn = 1e5+10;
struct edge{
	int s,e;
	int id;
	edge(){
	}
	edge(int x,int y,int c){
		s = x;
		e = y;
		id = c;
	}
	const bool operator<(const edge &b)const{
		return id<b.id;
	}
};
vector<int> cols;
vector<vector<edge>> graph;
vector<int> ans; 
vector<int> dp;
bitset<mxn> goneto;
void dfs(int now){
	goneto[now] = true;
	if(cols[now] == 1)dp[now] = 1;
	for(auto nxt:graph[now]){
//		cout<<nxt.s<<' '<<nxt.e<<endl;
		if(goneto[nxt.e])continue;
		dfs(nxt.e);
		if(dp[nxt.e] != 0){
			ans.push_back(nxt.id);
		}
		dp[now] += dp[nxt.e];
	}
//	cout<<now<<' '<<dp[now]<<endl;
	dp[now] %= 2;
	return;
}
int main(){
	int n,m;
	cin>>n>>m;
	graph = vector<vector<edge>>(n+1);
	dp = vector<int>(n+1,0);
	cols = vector<int>(n+1,0);
	for(int i= 1;i<=n;i++){
		cin>>cols[i];
	}
	for(int i =1 ;i<=m;i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(edge(a,b,i));
		graph[b].push_back(edge(b,a,i));
	}
	for(int i = 1;i<=n;i++){
		if(!goneto[i]){
			dfs(i);
			if(dp[i] != 0){
				cout<<"No";
				return 0;
			}
		}
	}
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	cout<<"Yes\n";
	cout<<ans.size()<<'\n';
	for(auto i:ans)cout<<i<<' ';
}

