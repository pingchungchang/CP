#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n,m;
	cin>>n>>m;
	vector<ll> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	vector<vector<int>> paths(n);
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	vector<bool> goneto(n,false);
	goneto[0] = true;
	int d;
	cin>>d;
	queue<pii> q;
	q.push(make_pair(0,0));
	while(!q.empty()){
		pii now = q.front();
		q.pop();
		if(now.sc>=d)break;
		for(auto nxt:paths[now.fs]){
			if(goneto[nxt] == false){
				goneto[nxt] = true;
				q.push(make_pair(nxt,now.sc+1));
			}
		}
	}
	ll ans = 0;
	for(int i = 0;i<n;i++){
		if(goneto[i])ans += v[i];
	}
	cout<<ans;
}

