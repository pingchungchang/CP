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

const int mxn = 5e4+10;
bitset<mxn> dp[mxn],done;
int deg[mxn],cnt,gcnt,idx[mxn],low[mxn],group[mxn],ans[mxn];
vector<int> paths[mxn],dag[mxn],st;

void tarjan(int now){
	st.push_back(now);
	idx[now] = low[now] = ++cnt;
	for(auto nxt:paths[now]){
		if(done[nxt])continue;
		else if(idx[nxt])low[now] = min(low[now],idx[nxt]);
		else{
			tarjan(nxt);
			low[now] = min(low[now],low[nxt]);
		}
	}
	if(idx[now] == low[now]){
		gcnt++;
		while(st.back() != now){
			done[st.back()] = true;
			group[st.back()] = gcnt;
			st.pop_back();
		}
		done[st.back()] = true;
		group[st.back()] = gcnt;
		st.pop_back();
	}
	return;
}
int main(){
	io
	int n,m;
	cin>>n>>m;
	for(int i= 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
	}
	for(int i = 1;i<=n;i++){
		if(!idx[i])tarjan(i);
	}
	for(int i = 1;i<=n;i++){
		for(auto nxt:paths[i]){
			if(group[nxt] == group[i])continue;
			else{
				deg[group[i]]++;
				dag[group[nxt]].push_back(group[i]);
			}
		}
		dp[i][i] = true;
	}
	queue<int> q;
	for(int i = 1;i<=gcnt;i++){
		if(!deg[i])q.push(i);
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:dag[now]){
			dp[nxt]|=dp[now];
			deg[nxt]--;
			if(!deg[nxt])q.push(nxt);
		}
	}
	for(int i = 1;i<=n;i++)cout<<dp[group[i]].count()<<' ';
	return 0;
}

