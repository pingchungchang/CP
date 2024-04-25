#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


const int mxn = 1e5+10;
vector<int> paths[mxn];
bitset<mxn> vis;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	for(int i = 1;i<=n;i++)sort(paths[i].begin(),paths[i].end());
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		if(vis[i])continue;
		cnt++;
		set<int> st;
		queue<int> q;
		q.push(i);
		vis[i] = true;
		for(int j = 1;j<=n;j++){
			if(!vis[j])st.insert(j);
		}
		while(!q.empty()){
			auto now = q.front();
			q.pop();
			vector<int> done;
			for(auto &j:st){
				auto it = lower_bound(paths[now].begin(),paths[now].end(),j);
				if(it == paths[now].end()||*it != j){
					vis[j] = true;
					done.push_back(j);
					q.push(j);
				}
			}
			for(auto &j:done)st.erase(j);
		}
	}
	cout<<cnt-1;
}
