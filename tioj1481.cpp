#include <bits/stdc++.h>
#include "lib1481.h"
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


const int mxn = 1e6+10;
vector<pii> paths[5050];
int ans[mxn];
int C = 1;

/*
void Init(){}
void Possible(){}
void Number(int k){cout<<"NUMBER:"<<k<<endl;}
void Finish(){exit(0);}

*/

void dfs(int now){
	for(auto nxt:paths[now]){
		if(ans[nxt.sc])continue;
		ans[nxt.sc] = C++;
		dfs(nxt.fs);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	Init();
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back({b,i});
		paths[b].push_back({a,i});
	}
	Possible();
	dfs(1);
	set<int> st;
	vector<pii> v;
	for(int i = 1;i<=m;i++)if(!ans[i])ans[i] = C++;
	for(int i = 1;i<=m;i++)st.insert(ans[i]),assert(ans[i]<=m&&ans[i]>0);
	assert(st.size() == m);
	for(int i = 1;i<=m;i++)Number(ans[i]);
	Finish();
}

