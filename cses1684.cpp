#include <bits/stdc++.h>
using namespace std;

constexpr int mid = 1e5+5;
int n,m;
int scc = 0;
vector<vector<int>> paths(mid*2);
int groups[mid*2] = {};
stack<int> st;
int goneto[mid*2] = {};
int idx[mid*2] = {};
int num = 0;
int low[mid*2] = {};
int in[mid*2] = {};
int opp[mid*2] = {};
vector<vector<int>> newgraph(mid*2);
int pick[mid*2] = {};
void tarjan(int now){
	num++;
	low[now] = num;
	idx[now] = num;
	st.push(now);
	goneto[now] = 1;
	for(int i =0;i<paths[now].size();i++){
		int nxt = paths[now][i];
		if(idx[nxt] == 0){
			tarjan(nxt);
			low[now] = min(low[now],low[nxt]);
		}
		else if(goneto[nxt] ==1){
			low[now] = min(low[now],idx[nxt]);
		}
	}
	if(idx[now] == low[now]){
		scc++;
		while(st.top()!= now){
			groups[st.top()] = scc;
			goneto[st.top()] = 0;
			st.pop();
		}
		groups[now] = scc;
		goneto[now] = 0;
		st.pop();
	}
	return;
}
void toposort(){
	queue<int> q;
	for(int i =1;i<=scc;i++){
		if(in[i] == 0)q.push(i);
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(pick[now] == 0){
			pick[now] = 1;
			pick[opp[now]] = 2;
		}
		for(int i:newgraph[now]){
			in[i]--;
			if(in[i] == 0){
				q.push(i);
			}
		}
	}
	for(int i = 1;i<=n;i++){
		if(pick[groups[mid+i]] == 1){
			cout<<'-';
		}
		else cout<<'+';
	}
}
int main(){
	cin>>m>>n;
	for(int i =0;i<m;i++){
		char a,c;
		int b,d;
		cin>>a>>b>>c>>d;
		if(a == '-')b = -b;
		if(c == '-')d = -d;
		paths[mid-b].push_back(mid+d);
		paths[mid-d].push_back(mid+b);
	}
	for(int i =-n;i<=n;i++){
		if(i == 0)continue;
		if(idx[mid+i] == 0){
			tarjan(mid+i);
		}
	}
	for(int i =1;i<=n;i++){
		if(groups[mid+i] == groups[mid-i]){
			cout<<"IMPOSSIBLE";
			return 0;
		}
		else{
			opp[groups[mid+i]] = groups[mid-i];
			opp[groups[mid-i]] = groups[mid+i];
		}
	}
	for(int i = -n;i<=n;i++){
		if(i == 0)continue;
		for(int j:paths[i+mid]){
			if(groups[mid+i]!=groups[j]){
				newgraph[groups[mid+i]].push_back(groups[j]);
				in[groups[j]]++;
			}
		}
	}
	toposort();
}
/*
error:
5 5
+ 1 + 2
+ 2 + 3
+ 3 + 4
+ 4 + 5
+ 5 + 1
3 2
+ 1 + 2
- 1 + 2
- 1 - 2
*/
