#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
int ans[mxn];
set<pii> no;
set<int> unvis;
ll sz[4];
ll cnt[4][4];

void BFS(int s,int col){
	queue<int> q;
	ans[s] = col;
	q.push(s);
	unvis.erase(s);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		vector<int> del;
		for(auto &nxt:unvis){
			if(no.find({min(now,nxt),max(now,nxt)}) != no.end())continue;
			del.push_back(nxt);
			q.push(nxt);
			ans[nxt] = col;
		}
		for(auto &i:del)unvis.erase(i);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		if(a>b)swap(a,b);
		no.insert({a,b});
	}
	for(int i = 1;i<=n;i++)unvis.insert(i);
	for(int C = 1;C<=3;C++){
		for(int i = 1;i<=n;i++){
			if(!ans[i]){
				BFS(i,C);
				break;
			}
		}
	}
	int re = 0;
	for(int i = 1;i<=n;i++)re |= 1<<ans[i];
	//for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;
	if(re != 14){
		cout<<-1;
		return 0;
	}
	for(int i = 1;i<=n;i++)sz[ans[i]]++;
	for(auto &i:no){
		auto ta = i.fs,tb = i.sc;
		if(ans[ta] == ans[tb]){
			cout<<-1;
			return 0;
		}
		cnt[ans[ta]][ans[tb]]++;
	}
	for(int i = 1;i<=3;i++){
		for(int j = i+1;j<=3;j++){
			if((cnt[i][j]+cnt[j][i]) != sz[i]*sz[j]){
				cout<<-1;
			}
		}
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}
