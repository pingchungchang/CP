#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e4+10;
vector<int> groups[mxn];
int n,m;
vector<int> paths[mxn];
int idx[mxn],low[mxn];
int cnt = 0,gcnt = 0;
vector<int> st;

void tarjan(int now){
	idx[now] = low[now] = ++cnt;
	st.push_back(now);
	for(auto nxt:paths[now]){
		if(!idx[nxt]){
			tarjan(nxt);
			low[now] = min(low[now],low[nxt]);
			if(low[nxt] == now){
				gcnt++;
				groups[now].push_back(gcnt);
				while(st.back() != nxt){
					groups[st.back()].push_back(gcnt);
					st.pop_back();
				}
				groups[st.back()].push_back(gcnt);
				st.pop_back();
			}
		}
		else low[now] = min(low[now],idx[nxt]);
	}
	return;
}

void solve(int tid){
	if(!n&&!m)exit(0);
	cout<<"Case #"<<tid<<":";
	for(int i = 0;i<=n*2;i++){
		paths[i].clear();
		groups[i].clear();
		idx[i] = low[i] = cnt = gcnt = 0;
	}
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	tarjan(1);
	for(int i = 1;i<=n;i++){
		assert(idx[i]);
	}
	vector<int> ans;
	for(int i = 1;i<=n;i++){
		if(groups[i].size()>1)ans.push_back(i);
	}
	if(ans.empty())cout<<"0 0\n";
	else{
		cout<<ans.size()<<' ';for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int C = 0;
	while(cin>>n>>m)solve(++C);
}
