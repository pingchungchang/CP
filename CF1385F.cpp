#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> tree[mxn];
int leaf[mxn],del[mxn],deg[mxn];
int n,k;

void solve(){
	for(int i = 0;i<=n;i++){
		tree[i].clear();
		leaf[i] = del[i] = deg[i] = 0;
	}
	cin>>n>>k;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	for(int i = 1;i<=n;i++){
		if(tree[i].size() == 1&&!del[tree[i][0]]){
			del[i] = true;
			leaf[tree[i][0]]++;
		}
	}
	queue<int> q;
	for(int i = 1;i<=n;i++){
		if(leaf[i]>=k)q.push(i);
	}
	int ans = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		if(del[now])continue;
		if(leaf[now]<k)continue;
		ans++;
		leaf[now] -= k;
		deg[now] -= k;
		if(deg[now] == 1){
			for(auto nxt:tree[now]){
				if(del[nxt])continue;
				if(!del[nxt]){
					leaf[nxt] ++;
					del[now] = true;
					if(leaf[nxt]>=k)q.push(nxt);
				}
			}
		}
		if(!del[now]&&leaf[now]>=k)q.push(now);
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
