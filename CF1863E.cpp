#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
const int inf = 1e9+10;
int arr[mxn];
pii dp[mxn];
int n,m,k;
vector<int> paths[mxn];
int deg[mxn];
map<int,vector<int>> mp;

void solve(){
	for(int i = 0;i<=n;i++){
		paths[i].clear();
		arr[i] = inf;
		deg[i] = 0;
		dp[i] = {0,-inf};
	}
	mp.clear();
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i = 1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		deg[b]++;
	}
	queue<int> q;
	for(int i = 1;i<=n;i++){
		if(!deg[i]){
			dp[i] = {0,-arr[i]};
			q.push(i);
		}
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			deg[nxt]--;
			if(arr[nxt]>=arr[now])dp[nxt] = max(dp[nxt],make_pair(dp[now].fs,dp[now].sc));
			else dp[nxt] = max(dp[nxt],make_pair(dp[now].fs+1,dp[now].sc));
			if(!deg[nxt])q.push(nxt);
		}
	}
	multiset<ll> st;
	for(int i = 1;i<=n;i++){
		st.insert(1LL*dp[i].fs*k+arr[i]);
		mp[-dp[i].sc].push_back(i);
	}
	ll ans = *st.rbegin()-mp.begin()->fs;
	/*
	for(auto &i:st)cout<<i<<' ';cout<<'\n';
	for(auto &j:mp){
		cout<<j.fs<<":";
		for(auto &i:j.sc)cout<<i<<' ';cout<<'\n';
	}cout<<'\n';
	return;

   */
	for(auto &i:mp){
		ans = min(ans,*st.rbegin()-i.fs);
		for(auto &j:i.sc){
			st.erase(st.find(1LL*dp[j].fs*k+arr[j]));
			st.insert(1LL*dp[j].fs*k+arr[j]+k);
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(auto &i:arr)i = inf;
	for(auto &i:dp)i = {0,-inf};
	int t;cin>>t;
	while(t--)solve();
}
