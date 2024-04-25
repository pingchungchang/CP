#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
int N,M;
vector<int> paths[mxn],g[mxn];
int dp[mxn],arr[mxn];
priority_queue<pii,vector<pii>,greater<pii>> pq;
bitset<mxn> vis;
int dsu[mxn];

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	for(int i = 1;i<=N;i++)cin>>arr[i],dsu[i] = i;
	for(int i = 1;i<=M;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	for(int i = 1;i<=N;i++){
		for(auto nxt:paths[i]){
			if(arr[nxt] == arr[i]){
				dsu[root(nxt)] = root(i);
			}
		}
	}
	for(int i = 1;i<=N;i++){
		for(auto nxt:paths[i]){
			if(root(nxt) != root(i)){
				g[root(i)].push_back(root(nxt));
			}
		}
	}
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	dp[root(1)] = 1;
	for(int i = 1;i<=N;i++){
		if(dsu[i] == i)pq.push(make_pair(arr[i],i));
	}
	while(!pq.empty()){
		auto now = pq.top().sc;
		pq.pop();
		for(auto nxt:g[now]){
			if(arr[nxt]>arr[now]&&dp[now]){
				dp[nxt] = max(dp[nxt],dp[now]+1);
			}
		}
	}
	cout<<dp[root(N)];
}
