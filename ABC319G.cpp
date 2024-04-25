#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mod = 998244353;
const ll mxn = 2e5+10;
vector<int> paths[mxn];
ll dp[mxn],dist[mxn];
set<int> st[2];
ll n,m;
set<int> undone;
set<pii> del;

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
inline ll mub(ll a,ll b){
	if(!b)return a;
	else return mad(a,mod-b);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
		del.insert({a,b});
		del.insert({b,a});
	}
	bool roll = false;
	ll sum[2] = {0,0};
	st[roll].insert(1);
	sum[roll^1] = 1;
	int d = 0;
	for(int i = 2;i<=n;i++)undone.insert(i);
	while(!st[roll].empty()){
		sum[roll] = 0;
		d++;
		for(auto &now:st[roll]){
			dp[now] = sum[roll^1];
			for(auto &j:paths[now]){
				if(dist[j] == dist[now]-1)dp[now] = mub(dp[now],dp[j]);
			}
			sum[roll] = mad(sum[roll],dp[now]);
			for(auto it = undone.begin();it != undone.end();){
				if(del.find({*it,now}) != del.end()){
					it++;
					continue;
				}
				dist[*it] = d;
				st[roll^1].insert(*it);
				int t = *it;
				undone.erase(*it);
				it = undone.lower_bound(t);
			}
		}
		st[roll].clear();
		roll ^= 1;
	}
	if(undone.find(n) != undone.end())cout<<"-1";
	else cout<<dp[n];
}
