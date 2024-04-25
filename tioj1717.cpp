#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1010;
int dist[mxn];
vector<int> paths[mxn];
int deg[mxn],arr[mxn];
int n;

void solve(){
	for(int i = 0;i<=n;i++){
		arr[i] = dist[i] = deg[i] = 0;
		paths[i].clear();
	}
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		int m;
		cin>>m;
		while(m--){
			int k;
			cin>>k;
			paths[i].push_back(k);
			deg[k]++;
		}
	}
	queue<int> q;
	for(int i = 1;i<=n;i++){
		if(!deg[i])q.push(i);
	}
	int ans = 0;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		dist[now] += arr[now];
		ans = max(ans,dist[now]);
		for(auto nxt:paths[now]){
			deg[nxt]--;
			dist[nxt] = max(dist[nxt],dist[now]);
			if(!deg[nxt]){
				q.push(nxt);
			}
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
