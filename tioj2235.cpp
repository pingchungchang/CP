#include <bits/stdc++.h>
using namespace std;


const int mxn = 1e6+10;
vector<int> paths[mxn];
int deg[mxn];
int n,m;
queue<int> q;
vector<int> ans;
bool flag;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		deg[b]++;
	}
	flag = true;
	for(int i = 1;i<=n;i++){
		if(!deg[i])q.push(i);
	}
	while(!q.empty()){
		if(q.size() != 1)flag = false;
		auto now = q.front();
		q.pop();
		ans.push_back(now);
		for(auto nxt:paths[now]){
			deg[nxt]--;
			if(!deg[nxt])q.push(nxt);
		}
	}
	if(!flag)cout<<-1;
	else for(auto &i:ans)cout<<i<<' ';
	return 0;
}
