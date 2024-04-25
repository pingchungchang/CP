#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll path[505][505];
stack<int> st;
int goneto[505] = {};
ll tmpflow;
ll ans = 0;
int n,m;
void findpath(){
	tmpflow = LONG_LONG_MAX;
	memset(goneto,0,sizeof(goneto));
	queue<pair<int,int>> q;
	q.push(make_pair(1,1));
	goneto[1] = 1;
	while(!q.empty()){
		int now = q.front().first;
		int t = q.front().second;
		q.pop();
		if(goneto[now]<t&&goneto[now]!=0)continue;
		for(int i = 1;i<=n;i++){
			if(path[now][i]!=0){
				if(goneto[i] == 0){
					goneto[i] = t+1;
					q.push(make_pair(i,t+1));
				}
			}
		}
	}
//	for(int i = 1;i<=n;i++)cout<<goneto[i]<<' ';
//	cout<<endl;
	int x = n;
	if(goneto[x] == 0)return;
	st.push(x);
	while(x != 1){
		for(int i = 1;i<=n;i++){
			if(goneto[i] == goneto[x]-1&&path[i][x]!= 0){
//				cout<<x<<i<<path[i][x]<<endl;
				tmpflow = min(tmpflow,path[i][x]);
				st.push(i);
				x = i;
				break;
			}
		}
	}
	return;
}


int main(){
	memset(path,0,sizeof(path));
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		path[a][b]+= c;
	}
	findpath();
	while(st.size()!=0){
		ans += tmpflow;
		while(st.size()>1){
			int now = st.top();
			st.pop();
			path[now][st.top()] -= tmpflow;
			path[st.top()][now] += tmpflow;
		}
		while(!st.empty())st.pop();
		findpath();
	}
	cout<<ans;
}
