#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct node{
	int par;
	vector<pair<int,int>> childs;
	int dp[2];
	node(){
		par = -1;
		memset(dp,0,sizeof(dp));
	}
};
vector<node> v;
pair<int,int> ans = make_pair(0,0);
void dfs(int now){
	for(auto nxt:v[now].childs){
		if(nxt.fs == v[now].par)continue;
		v[nxt.fs].par = now;
		dfs(nxt.fs);
	}
	return;
}

void dfs1(int now){
	pair<int,int> ls = make_pair(0,0);
	for(auto p:v[now].childs){
		int nxt = p.fs;
		if(nxt == v[now].par)continue;
		dfs1(nxt);
		for(auto j:v[nxt].dp){
			if(j+p.sc+ls.fs>ans.fs){
				swap(ans.fs,ans.sc);
				ans.fs = j+p.sc+ls.fs;
			}
			else if(j+p.sc+ls.fs<ans.fs&&ans.sc<j+p.sc+ls.fs){
				ans.sc = j+p.sc+ls.fs;
			}
			if(j+p.sc+ls.sc <ans.fs&&ans.sc<j+p.sc+ls.sc)ans.sc = j+p.sc+ls.sc;
			
			
		}
		for(auto j:v[nxt].dp){
			if(j+p.sc>ls.fs){
				swap(ls.fs,ls.sc);
				ls.fs = j+p.sc;
			}
			else if(j+p.sc>ls.sc&&j+p.sc<ls.fs){
				ls.sc = j+p.sc;
			}			
		}

		v[now].dp[0] = ls.fs;
		v[now].dp[1] = ls.sc;
	}
	return;
}
int main(){
	int n;
	cin>>n;
	v = vector<node> (n);
	for(int i = 0;i<n-1;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].childs.push_back(make_pair(b,c));
		v[b].childs.push_back(make_pair(a,c));
	}
	dfs(0);
	dfs1(0);
	cout<<ans.sc;
}
