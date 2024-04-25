#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> paths[n+1];
	int deg[n+1] = {};
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		deg[b]++;
	}
	queue<int> q;
	for(int i = 1;i<=n;i++)if(!deg[i])q.push(i);
	vector<int> ans;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		ans.push_back(now);
		for(auto nxt:paths[now]){
			deg[nxt]--;
			if(!deg[nxt])q.push(nxt);
		}
	}
	if(ans.size() != n)cout<<"NO";
	else{
		cout<<"YES\n";
		for(auto &i:ans)cout<<i<<'\n';
	}
	return 0;
}
