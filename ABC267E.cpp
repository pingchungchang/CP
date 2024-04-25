#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
vector<int> paths[mxn];
ll arr[mxn];
bitset<mxn> done;
int n,m;
ll dp[mxn];
priority_queue<pll,vector<pll>,greater<pll>> pq;

inline ll solve(){
	done.reset();
	for(int i = 1;i<=n;i++){
		dp[i] = 0;
		for(auto nxt:paths[i]){
			dp[i] += arr[nxt];
		}
		pq.push(make_pair(dp[i],i));
	}
	ll ans = 0;
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(done[now.sc])continue;
		ans = max(ans,now.fs);
		done[now.sc] = true;
		for(auto nxt:paths[now.sc]){
			if(done[nxt])continue;
			dp[nxt] -= arr[now.sc];
			pq.push(make_pair(dp[nxt],nxt));
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	cout<<solve();
}
