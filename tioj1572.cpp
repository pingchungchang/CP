#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	io
	int n,m,s,e;
	cin>>n>>m>>s>>e;
	vector<int> paths[n+1];
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	for(int i = 1;i<=n;i++)sort(_all(paths[i]));
	int pre[n+1] = {};
	pre[s] = s;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		if(pre[e] != 0)break;
		int now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(pre[nxt] == 0){
				q.push(nxt);
				pre[nxt] = now;
			}
		}
	}
	int now = e;
	vector<int> ans = {e};
	while(now != s){
		ans.push_back(pre[now]);
		now = pre[now];
	}
	cout<<ans.size()-2<<'\n';
	reverse(_all(ans));
	for(int i = 0;i<ans.size()-1;i++)cout<<ans[i]<<'-';
	cout<<ans.back();
}

