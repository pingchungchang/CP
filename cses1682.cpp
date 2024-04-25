#include <bits/stdc++.h>
using namespace std;

constexpr int mxn = 1e5+5;
vector<vector<int>> paths(mxn);
bool goneto[mxn] = {};
int idx[mxn] = {};
int scc = 0;
int t = 1;
int low[mxn] = {};
stack<int> st;
int groups[mxn] = {};
void tarjan(int now){
	idx[now] = t;
	st.push(now);
	low[now] = t;
	goneto[now] = true;
	t++;
	for(int i =0;i<paths[now].size();i++){
		int nxt = paths[now][i];
		if(idx[nxt] ==0){
			tarjan(nxt);
			low[now] = min(low[now],low[nxt]);
		}
		else if(goneto[nxt] == true){
			low[now] = min(low[now],idx[nxt]);
		}
	}
	if(low[now] == idx[now]){
		scc++;
		while(st.top()!= now){
			groups[st.top()] = scc;
			goneto[st.top()] = false;
			st.pop();
		}
		goneto[now] = false;
		groups[now] = scc;
		st.pop();
	}
	return;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i =0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		paths[a].push_back(b);
	}
	for(int i =0;i<n;i++){
		if(idx[i] ==0)tarjan(i);
	}
	if(scc == 1){
		cout<<"YES";
		return 0;
	}
	for(int i =0;i<n;i++){
		for(int j = 0;j<paths[i].size();j++){
			if(groups[i]!= groups[paths[i][j]]){
				cout<<"NO\n"<<1+paths[i][j]<<' '<<1+i;
				return 0;
			}
		}
	}
	for(int i =0;i<n;i++){
		for(int j =0;j<n;j++)if(groups[i]!= groups[j]){
			cout<<"NO\n"<<1+i<<' '<<j+1;
			return 0;
		}
	}
}
