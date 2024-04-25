#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
vector<int> paths[mxn];
int gcnt,gid[mxn];
int col[mxn];
int N,M;

void init(){
	for(int i = 0;i<=N;i++){
		gid[i] = col[i] = 0;
		paths[i].clear();
	}
	gcnt = 0;
	return;
}

namespace TARJAN{
	int low[mxn],idx[mxn],cnt;
	vector<int> st;

	void init(){
		st.clear();
		cnt = 0;
		for(int i = 0;i<=N;i++){
			idx[i] = low[i] = 0;
		}
	}

	void dfs(int now){
		idx[now] = low[now] = ++cnt;
		st.push_back(now);
		for(auto nxt:paths[now]){
			if(gid[nxt])continue;
			if(!idx[nxt]){
				dfs(nxt);
				low[now] = min(low[now],low[nxt]);
			}
			else low[now] = min(low[now],idx[nxt]);
		}
		if(low[now] == idx[now]){
			gcnt++;
			while(st.back() != now){
				gid[st.back()] = gcnt;
				st.pop_back();
			}
			gid[st.back()] = gcnt;
			st.pop_back();
		}
		return;
	}

	void GO(){
		cnt = gcnt = 0;
		for(int i = 1;i<=N;i++){
			if(!gid[i])dfs(i);
		}
	}
}

namespace DAG{
	vector<int> dag[mxn];
	queue<int> q;
	int deg[mxn],gcol[mxn],dp[mxn],dfn[mxn];
	bitset<mxn> vis;
	vector<int> eul;
	void init(){
		eul.clear();
		for(int i = 0;i<=N;i++){
			deg[i] = gcol[i] = dp[i] = dfn[i] = 0;
			dag[i].clear();
		}
		vis.reset();
		memset(gcol,-1,sizeof(gcol));
	}
	bool build(){
		for(int i = 1;i<=N;i++){
			int gg = gid[i];
			if(gcol[gg] != -1&&gcol[gg] != col[i])return false;
			gcol[gg] = col[i];
			for(auto nxt:paths[i]){
				if(gid[nxt] == gid[i])continue;
				deg[gid[nxt]]++;
				dag[gid[i]].push_back(gid[nxt]);
			}
		}
		return true;
	}
	int dfs(int now){
		vis[now] = true;
		int re = gcol[now];
		for(auto nxt:dag[now]){
			if(vis[nxt])continue;
			int tmp = dfs(nxt);
			if(!tmp)return false;
			re += tmp;
		}
		if(!gcol[now])return false;
		return re;
	}
	bool check_two(){
		for(int i = 1;i<=gcnt;i++){
			for(auto nxt:dag[i])deg[nxt]++;
		}
		for(int i = 1;i<=gcnt;i++){
			if(dag[i].size() != 1||deg[i] != 0)continue;
			int nxt = dag[i][0];
			if(deg[nxt] == 1&&dag[nxt].size() == 0&&gcol[i] == 1&&gcol[nxt] == 0)return true;
		}
		int iso = 0;
		for(int i = 1;i<=gcnt;i++){
			if(!deg[i]&&dag[i].empty()&&gcol[i])iso++;
		}
		if(iso == 2)return true;
		return false;
	}
	void GO(){
		if(!build()){
			cout<<"N";
			return;
		}
		int cnt = 0;
		for(int i = 1;i<=gcnt;i++){
			if(!deg[i])q.push(i);
		}
		while(!q.empty()){
			auto now = q.front();
			q.pop();
			eul.push_back(now);
			dfn[now] = eul.size();
			for(auto nxt:dag[now]){
				deg[nxt]--;
				if(!deg[nxt])q.push(nxt);
			}
		}
		for(auto it = eul.rbegin();it != eul.rend();it++){
			int now = *it;
			dp[now] = gcol[now];
			for(auto nxt:dag[now]){
				dp[now] &= dp[nxt];
			}
		}
		if(*max_element(col+1,col+N+1) == 0){
			cout<<"B";
			return;
		}
		int high = 0;
		/*
		for(int i = 1;i<=N;i++)cout<<gid[i]<<' ';cout<<endl;
		for(int i = 1;i<=N;i++)cout<<gcol[i]<<' ';cout<<endl;

	   */
		for(auto &i:eul)if(gcol[i]){high = i;break;}
		//cout<<high<<endl;
		int C = 0;
		for(int i = 1;i<=gcnt;i++)C += gcol[i];
		if(C == dfs(high))cout<<"A";
		else if(check_two())cout<<"B";
		else cout<<"N";
	}
}

void solve(){
	init();TARJAN::init();DAG::init();
	cin>>N>>M;
	for(int i = 1;i<=N;i++)cin>>col[i];
	for(int i = 0;i<M;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
	}
	TARJAN::GO();
	DAG::GO();
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
