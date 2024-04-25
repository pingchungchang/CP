#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll inf = 1e18;
const int mxn = 2e5+10;

vector<int> paths[mxn];
ll arr[mxn];
pll dp[mxn];
ll ans;
bitset<mxn> psyco;
int n,m,sz;
queue<int> q;
int deg[mxn];
int root = 0;
int ptr[mxn];
ll pref[mxn];
deque<ll> dq;

void dfs(int now,int par){
	dp[now] = {0ll,-inf};
	for(auto nxt:paths[now]){
		if(nxt == par)continue;
		dfs(nxt,now);
		if(dp[nxt].fs>dp[now].fs){
			swap(dp[now].fs,dp[now].sc);
			dp[now].fs = dp[nxt].fs;
		}
		else if(dp[nxt].fs>dp[now].sc)dp[now].sc = dp[nxt].fs;
	}
	ans = max({ans,dp[now].fs+dp[now].sc+arr[now],dp[now].fs+arr[now]});
	dp[now].fs += arr[now];
	dp[now].sc += arr[now];
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		deg[a]++,deg[b]++;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	if(m != n)deg[1]+=2,paths[1].push_back(1);
	for(int i = 1;i<=n;i++)cin>>arr[i],psyco[i] = 1;
	for(int i = 1;i<=n;i++){
		if(deg[i] == 1){
			deg[i] = 0;
			q.push(i);
		}
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		psyco[now] = false;
		for(auto nxt:paths[now]){
			deg[nxt]--;
			if(deg[nxt] == 1){
				deg[nxt] = 0;
				q.push(nxt);
			}
		}
	}
	for(int i = 1;i<=n;i++){
		if(psyco[i])root = i;
	}
	ans = -4e18;
	int now = root;
	vector<pll> v;
	v.push_back(make_pair(0ll,0ll));

	do{
		sz++;
		int np = 0;

		for(auto nxt:paths[now]){
			if(psyco[nxt]){
				if(nxt != ptr[now])np = nxt,ptr[nxt] = now;
				continue;
			}
			dfs(nxt,now);
		}
		dp[now] = {0ll,-inf};

		for(auto nxt:paths[now]){
			if(psyco[nxt])continue;
			if(dp[nxt].fs>dp[now].fs){
				swap(dp[now].fs,dp[now].sc);
				dp[now].fs = dp[nxt].fs;
			}
			else if(dp[nxt].fs>dp[now].sc)dp[now].sc = dp[nxt].fs;
		}
		ans = max({ans,dp[now].fs+arr[now]+dp[now].sc,dp[now].fs+arr[now]});
		v.push_back({arr[now],now});
		assert(np);
		now = np;
	}while(now != root);

	int ss = v.size();
	for(int i = 1;i<ss;i++)v.push_back(v[i]);
	for(int i = 1;i<ss;i++){
		pref[i] = pref[i-1]+v[i].fs;
		while(!dq.empty()&&dp[v[dq.back()].sc].fs-pref[dq.back()-1]<=dp[v[i].sc].fs-pref[i-1])dq.pop_back();
		dq.push_back(i);
	}
	for(int i = ss;i<v.size();i++)pref[i] = pref[i-1]+v[i].fs;

	for(int i = ss;i<v.size();i++){
		while(!dq.empty()&&i-dq.front()>=sz)dq.pop_front();
		if(!dq.empty())ans = max(ans,pref[i]-pref[dq.front()-1]+dp[v[dq.front()].sc].fs+dp[v[i].sc].fs);
		while(!dq.empty()&&dp[v[dq.back()].sc].fs-pref[dq.back()-1]<=dp[v[i].sc].fs-pref[i-1])dq.pop_back();
		dq.push_back(i);
	}
	cout<<ans;

}
