#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
vector<int> paths[mxn];
int deg[mxn],arr[mxn],val[mxn],pre[mxn];
int n;
vector<int> ans;

inline void calc(int s){
	pii small = {val[s],s};
	int now = s;
	do{
		small = min(small,make_pair(val[now],now));
		for(auto nxt:paths[now]){
			if(deg[nxt]){
				now = nxt;
				break;
			}
		}
	}while(now != s);
	vector<int> tmp;
	now = small.sc;
	do{
		for(auto nxt:paths[now]){
			if(deg[nxt]){
				deg[nxt] = 0;
				now = nxt;
				break;
			}
		}
		ans.push_back(now);
	}while(now != small.sc);
	return;
}

void solve(){
	ans.clear();
	for(int i = 0;i<=n;i++){
		paths[i].clear();
		deg[i] = 0;
	}
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i],deg[arr[i]]++,paths[i].push_back(arr[i]);
	for(int i = 1;i<=n;i++)cin>>val[i];
	queue<int> q;
	for(int i = 1;i<=n;i++)if(!deg[i])q.push(i);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		ans.push_back(now);
		for(auto nxt:paths[now]){
			deg[nxt]--;
			if(!deg[nxt])q.push(nxt);
		}
	}
	for(int i = 1;i<=n;i++){
		if(deg[i]){
			calc(i);
		}
	}
	//assert(ans.size() == n);
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
