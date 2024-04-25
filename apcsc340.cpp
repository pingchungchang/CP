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
const int mxn =2e5+10;
bitset<mxn> goneto;
int main(){
	io
	int n,m;
	cin>>n>>m;
	ll ans = 0;
	vector<int> paths[n+1];
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	queue<pii> q;
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		q.push({k,0});
		goneto[k] = true;
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		ans += now.sc;
		for(auto nxt:paths[now.fs]){
			if(!goneto[nxt]){
				goneto[nxt] = true;
				q.push({nxt,now.sc+1});
			}
		}
	}
	cout<<ans;
}

