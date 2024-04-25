#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double


void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> tree(n+1);
	queue<pii> q;
	vector<int> d1(n+1,-1),d2(n+1,-1);
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		d1[k] = 0;
		q.push(make_pair(k,0));
	}
	for(int i= 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:tree[now.fs]){
			if(d1[nxt] == -1){
				d1[nxt] = now.sc+1;
				q.push(make_pair(nxt,now.sc+1));
			}
		}
	}
	d2[1] = 0;
	q.push(make_pair(1,0));
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:tree[now.fs]){
			if(d2[nxt] == -1){
				d2[nxt] = now.sc+1;
				q.push(make_pair(nxt,now.sc+1));
			}
		}
	}
	for(int i = 2;i<=n;i++){
		if(tree[i].size() == 1&&d2[i]<d1[i]){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

