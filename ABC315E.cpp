#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> paths[mxn];
int deg[mxn],dp[mxn];
vector<int> v;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int p;
			cin>>p;
			paths[i].push_back(p);
			deg[p]++;
		}
	}
	queue<int> q;
	dp[1] = 1;
	for(int i = 1;i<=n;i++){
		if(!deg[i])q.push(i);
	}
	while(!q.empty()){
		auto now = q.front();
		if(dp[now])v.push_back(now);
		q.pop();
		for(auto nxt:paths[now]){
			dp[nxt]|=dp[now];
			deg[nxt]--;
			if(!deg[nxt])q.push(nxt);
		}
	}
	reverse(v.begin(),v.end());
	v.pop_back();
	for(int i = 0;i<v.size();i++)cout<<v[i]<<' ';
}
