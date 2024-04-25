#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 4e5+10;
vector<int> paths[mxn],tree[mxn],groups[mxn],st;
int tag[mxn],pre[mxn],idx[mxn],low[mxn];
int n,m,A,B,C,gcnt,cnt;

void tarjan(int now){
	idx[now] = low[now] = ++cnt;
	st.push_back(now);
	for(auto nxt:paths[now]){
		if(!idx[nxt]){
			tarjan(nxt);
			low[now] = min(low[now],low[nxt]);
			if(low[nxt] == idx[now]){
				gcnt++;
				groups[now].push_back(gcnt);
				tree[now].push_back(gcnt);
				tree[gcnt].push_back(now);
				while(st.back() != nxt){
					groups[st.back()].push_back(gcnt);
					tree[st.back()].push_back(gcnt);
					tree[gcnt].push_back(st.back());
					st.pop_back();
				}
				groups[st.back()].push_back(gcnt);
				tree[st.back()].push_back(gcnt);
				tree[gcnt].push_back(st.back());
				st.pop_back();
			}
		}
		else low[now] = min(low[now],idx[nxt]);
	}
	return;
}

void BFS(int now){
	memset(pre,0,sizeof(pre));
	queue<int> q;
	pre[now] = now;
	q.push(now);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:tree[now]){
			if(!pre[nxt]){
				q.push(nxt);
				pre[nxt] = now;
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>A>>B>>C;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	gcnt = n;
	tarjan(1);
	tag[B] = 1;
	for(auto &i:groups[B])tag[i] = 1;
	BFS(A);
	int flag = 0;
	int now = C;
	while(now != A){
		flag += tag[now];
		now = pre[now];
	}
	cout<<(flag?"Yes":"No");
	return 0;
}
