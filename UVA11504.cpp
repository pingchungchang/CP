#include <bits/stdc++.h>
using namespace std;

int n,m;
const int ma = 1e6+5;
int idx[ma] = {};
int low[ma] = {};
stack<int> st;
vector<vector<int>> paths;
int cnt = 0,gcnt = 0;
int group[ma] = {};
int goneto[ma] = {};
void tarjan(int now){
	cnt++;
	st.push(now);
	idx[now] = cnt;
	low[now] = cnt;
	for(int nxt:paths[now]){
		if(goneto[nxt] == 1)continue;
		if(idx[nxt] != 0)low[now] = min(low[now],idx[nxt]);
		else{
			tarjan(nxt);
			low[now] = min(low[now],low[nxt]);
		}
	}
	if(low[now] == idx[now]){
		gcnt++;
		while(st.top() != now){
			group[st.top()] = gcnt;
			goneto[st.top()] = 1;
			st.pop();
		}
		group[st.top()] = gcnt;
		goneto[st.top()] = 1;
		st.pop();
	}
	return;
	
}
void init(){
	memset(idx,0,sizeof(idx));
	cnt = 0,gcnt = 0;
	memset(group,0,sizeof(group));
	memset(low,0,sizeof(low));
	memset(goneto,0,sizeof(goneto));
}
void solve(){
	init();
	cin>>n>>m;
	paths = vector<vector<int>>(n);
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a-1].push_back(b-1);
	}
	for(int i = 0;i<n;++i){
		if(goneto[i] == 0)tarjan(i);
	}
	int deg[1+gcnt] = {};
	for(int i = 0;i<n;i++){
		for(int nxt:paths[i]){
			if(group[nxt] == group[i])continue;
			deg[group[nxt]]++;
		}
	}
	int ans = 0;
	for(int i = 1;i<=gcnt;i++){
//		cout<<deg[i]<<' ';
		if(deg[i] == 0)ans++;
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
