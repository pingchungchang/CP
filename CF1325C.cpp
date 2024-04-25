#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
pii edge[mxn];
vector<pii> tree[mxn];
int deg[mxn];
int ans[mxn];
int n;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(ans,-1,sizeof(ans));
	cin>>n;
	for(int i = 1;i<n;i++){
		cin>>edge[i].fs>>edge[i].sc;
		tree[edge[i].fs].push_back({edge[i].sc,i});
		tree[edge[i].sc].push_back({edge[i].fs,i});
		deg[edge[i].fs]++;deg[edge[i].sc]++;
	}
	vector<int> leaf;
	queue<int> q;
	int C = 0;
	for(int i = 1;i<=n;i++){
		if(tree[i].size() == 1&&ans[tree[i][0].sc] == -1){
			q.push(i);
		}
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:tree[now]){
			if(ans[nxt.sc] != -1)continue;
			deg[nxt.fs]--;
			ans[nxt.sc] = C++;
			if(deg[nxt.fs] == 1){
				q.push(nxt.fs);
			}
		}
	}
	for(int i = 1;i<n;i++)cout<<ans[i]<<'\n';
}
