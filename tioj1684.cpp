#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1010;
int n,m,cnt,gcnt;
vector<int> bcc[mxn],groups[mxn],st;
int paths[mxn][mxn],idx[mxn],low[mxn],col[mxn],active[mxn],odd[mxn];


void init(){
	st.clear();
	for(int i = 0;i<=n;i++){
		groups[i].clear();
		idx[i] = low[i] = col[i] = active[i] = 0;
		for(int j = 0;j<=n;j++)paths[i][j] = 0;
	}
	for(int i = 0;i<=gcnt;i++){
		odd[i] = 0;
		bcc[i].clear();
	}
	gcnt = cnt = 0;
}

void tarjan(int now){
	idx[now] = low[now] = ++cnt;
	st.push_back(now);
	for(int nxt = 1;nxt<=n;nxt++){
		if(!paths[now][nxt])continue;
		if(!idx[nxt]){
			tarjan(nxt);
			low[now] = min(low[now],low[nxt]);
			if(low[nxt] == idx[now]){
				gcnt++;
				bcc[gcnt].push_back(now);
				groups[now].push_back(gcnt);
				while(st.back() != nxt){
					bcc[gcnt].push_back(st.back());
					groups[st.back()].push_back(gcnt);
					st.pop_back();
				}
				bcc[gcnt].push_back(st.back());
				groups[st.back()].push_back(gcnt);
				st.pop_back();
			}
		}
		else low[now] = min(low[now],idx[nxt]);
	}
	return;
}

bool dfs(int now,int c){
	assert(active[now]);
	col[now] = c;
	bool flag = true;
	for(int nxt = 1;nxt<=n;nxt++){
		if(!paths[now][nxt])continue;
		if(active[nxt]&&col[nxt] == 0)flag = flag&&dfs(nxt,-c);
		else if(active[nxt]&&col[nxt] == col[now])flag = false;
	}
	return flag;
}

void solve(){
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i == j)continue;
			paths[i][j] = 1;
		}
	}
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a][b] = paths[b][a] = 0;
	}
	for(int i = 1;i<=n;i++){
		if(groups[i].empty())tarjan(i);
		st.clear();
	}
	for(int i = 1;i<=gcnt;i++){
		for(auto &j:bcc[i])active[j] = true;
		bool flag = dfs(bcc[i][0],1);
		if(!flag)odd[i] = true;
		for(auto &j:bcc[i]){
			active[j] = false;
			col[j] = 0;
		}
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		bool flag = true;
		for(auto &j:groups[i]){
			if(odd[j])flag = false;
		}
		ans += flag;
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n>>m){
		if(n == 0&&m == 0)return 0;
		solve();
		init();
	}
}
