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
const int mxn = 2e5+10;
vector<int> paths[mxn];
int par[mxn] = {};
int main(){
	io
	int n;
	cin>>n;
	int s,e;
	cin>>s>>e;
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	queue<int> q;
	par[s] = s;
	q.push(s);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			if(!par[nxt]){
				par[nxt] = now;
				q.push(nxt);
			}
		}
	}
	vector<int> ans;
	ans.push_back(e);
	while(ans.back() != s){
		e = par[e];
		ans.push_back(e);
	}
	reverse(_all(ans));
	for(auto &i:ans)cout<<i<<' ';
	
}

