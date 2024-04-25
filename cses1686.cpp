#include <bits/stdc++.h>
using namespace std;

#define ll long long
constexpr int mx = 1e5+5;
int n,m,scc = 0,num = 0,low[mx] = {},idx[mx] = {},goneto[mx] = {},groups[mx] = {},in[mx] = {};
ll val1[mx],val2[mx];
ll buffer[mx];
vector<vector<int>> v1(mx),v2(mx);
stack<int> st;
queue<int> q;
void tarjan(int now){
	num++;
	low[now] = num;
	idx[now] = num;
	st.push(now);
	goneto[now] = 1;
	for(auto i: v1[now]){
		if(idx[i] == 0){
			tarjan(i);
			low[now] = min(low[now],low[i]);
		}
		else if(goneto[i] == 1){
			low[now] = min(low[now],idx[i]);
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
}
int main(){
	cin>>n>>m;
	memset(val1,0,(n+1)*sizeof(ll));
	memset(val2,0,(n+1)*sizeof(ll));
	memset(buffer,0,(n+1)*sizeof(ll));
	for(int i =1;i<=n;i++){
		cin>>val1[i];
	}
	for(int i =0;i<m;i++){
		int a,b;
		cin>>a>>b;
		v1[a].push_back(b);
	}
	for(int i =1;i<=n;i++){
		if(idx[i] == 0)tarjan(i);
	}
	for(int i = 1;i<=n;i++){
		int g = groups[i];
		val2[g]+= val1[i];
		for(auto j:v1[i]){
			if(g != groups[j]){
				v2[g].push_back(groups[j]);
				in[groups[j]]++;
			}
		}
	}
	for(int i = 1;i<=scc;i++){
		if(in[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int now = q.front();
		q.pop();
		val2[now]+= buffer[now];
		for(auto nxt:v2[now]){
			in[nxt]--;
			buffer[nxt] = max(buffer[nxt],val2[now]);
			if(in[nxt] == 0){
				q.push(nxt);
			}
		}
	}
	ll ans = 0;
	for(int i = 1;i<=scc;i++){
		ans = max(ans,val2[i]);
	}
	cout<<ans;
}
