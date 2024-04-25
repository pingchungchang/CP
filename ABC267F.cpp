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

const int mxn = 2e5+10;
vector<int> graph[mxn];
int dep[2][mxn];
int par[2][mxn][31];
pii longest;
void dfs(vector<int> g[],int d[],int p[][31],int now){
	for(int i = 1;i<30;i++)p[now][i] = p[p[now][i-1]][i-1];
	for(auto nxt:g[now]){
		if(nxt == p[now][0])continue;
		d[nxt] = d[now]+1;
		p[nxt][0] = now;
		dfs(g,d,p,nxt);
//		cout<<now<<' '<<nxt<<' '<<d[nxt]<<'\n';
	}
	longest = max(longest,{d[now],now});
	return;
}
int anc(int p[][31],int now,int k){
	for(int i = 0;i<30;i++){
		if(k&(1LL<<i))now = p[now][i];
	}
	return now;
}
int main(){
	io
	int n;
	cin>>n;
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	longest = {0,1};
	dfs(graph,dep[0],par[0],1);
//	cout<<endl;
	dep[0][longest.sc] = 0;
	for(int i= 0;i<30;i++)par[0][longest.sc][i] = 0;
	int tmp = longest.sc;
	longest = {0,tmp};
	dfs(graph,dep[0],par[0],tmp);
//	cout<<endl;
	tmp = longest.sc;
	longest = {0,tmp};
	dfs(graph,dep[1],par[1],tmp);
//	cout<<endl;
	int q;
	cin>>q;
	while(q--){
		int s,k;
		cin>>s>>k;
		int p1 = anc(par[0],s,k);
		int p2 = anc(par[1],s,k);
		if(p1 == 0&&p2 == 0)cout<<"-1\n";
		else cout<<max(p1,p2)<<'\n';
	}
}

