#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	int deltime[n] = {};
	vector<vector<int>> tree(n);
	int deg[n] = {};
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	queue<pair<int,int>> q;
	for(int i = 0;i<n;i++){
		if(tree[i].size()==1){
			q.push(make_pair(i,1));
			deltime[i] = 1;
		}
	}
	while(!q.empty()){
		int now = q.front().first;
		int val = q.front().second;
		q.pop();
		for(auto nxt:tree[now]){
			deg[nxt]--;
			if(deg[nxt]<=1&&deltime[nxt] == 0){
				deltime[nxt] = val+1;
				q.push(make_pair(nxt,val+1));
			}
		}
	}
	int ans =0;
	for(int i =0;i<n;i++){
		if(deltime[i]>k)ans++;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
