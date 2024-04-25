#include <bits/stdc++.h>
using namespace std;

constexpr int mxn = 1e5+5;
bool goneto[mxn] = {};
int idx[mxn] = {};
int low[mxn] = {};
stack<int> st;
int t=0,scc = 0;
int group[mxn] = {};
vector<vector<int>> paths(mxn);
int n,m;
void tarjan(int now){
	t++;
	goneto[now] = true;
	idx[now] = t;
	low[now] = t;
	st.push(now);
	for(int i:paths[now]){
		if(idx[i] == 0){
			tarjan(i);
			low[now] = min(low[i],low[now]);
		}
		else if(goneto[i] == true){
			low[now] = min(idx[i],low[now]);
		}
	}
	if(idx[now] == low[now]){
		scc++;
		while(st.top()!=now){
			group[st.top()] = scc;
			goneto[st.top()] =false;
			st.pop();
		}
		goneto[now] = false;
		group[now] = scc;
		st.pop();
	}
}
int main(){
	cin>>n>>m;
	for(int i =0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
	}
	for(int i =1;i<=n;i++){
		if(idx[i] == 0)tarjan(i);
	}
	cout<<scc<<'\n';
	for(int i =1;i<=n;i++){
		cout<<group[i]<<' ';
	}
}
