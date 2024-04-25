#include <bits/stdc++.h>
using namespace std;

int paths[505][505] = {};
int p2[505][505] = {};
stack<int> st;
int n,m;
int former[505] = {};
void findpath(){
	memset(former,0,sizeof(former));
	queue<int> q;
	q.push(1);
	former[1] = 1;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i = 1;i<=n;i++){
			if(paths[now][i]!= 0&&former[i] == 0){
				former[i] = now;
				q.push(i);
			}
		}
	}
	if(former[n] == 0)return;
//	cout<<former[n];
	int x = n;
	st.push(x);
	while(x != former[x]){
		x = former[x];
		st.push(x);
	}
	return;
}
int main(){
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a][b]++;
		paths[b][a]++;
		p2[a][b]++;
		p2[b][a]++;
	}
	findpath();
	while(st.size()!=0){
		int minflow = INT_MAX;
		int x = st.top();
		queue<int> q;
		q.push(st.top());
		st.pop();
		while(!st.empty()){
			minflow = min(minflow,paths[x][st.top()]);
			x = st.top();
			q.push(x);
			st.pop();
		}
		q.push(n);
		while(!st.empty())st.pop();
		x = q.front();
		q.pop();
		while(!q.empty()){
			paths[x][q.front()] -= minflow;
			paths[q.front()][x] += minflow;
			x = q.front();
			q.pop();
		}
		while(!q.empty())q.pop();
		findpath();
	}
	vector<pair<int,int>> ans;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(former[i]!=0&& former[j] == 0&&p2[i][j]!= 0){
				ans.push_back(make_pair(i,j));
				p2[i][j] = 0;
				p2[j][i] = 0;
			}
		}
	}
	cout<<ans.size()<<'\n';
	for(int i =0;i<ans.size();i++){
		cout<<ans[i].first<<' '<<ans[i].second<<'\n';
	}
	
}
