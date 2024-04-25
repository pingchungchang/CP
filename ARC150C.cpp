#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 1e5+10;
vector<int> paths[mxn];
int d1[mxn],d2[mxn];
int dp[mxn],deg[mxn];
int a[mxn],b[mxn];
bitset<mxn> done;


void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	for(int i = 1;i<=n;i++)cin>>a[i];
	for(int i = 0;i<k;i++)cin>>b[i];
	deque<int> dq;
	fill(dp,dp+mxn,mxn);
	if(a[1] == b[0])dp[1] = 1;
	else dp[1] = 0;
	dq.push_back(1);
	while(!dq.empty()){
		auto now = dq.front();
		dq.pop_front();
		//cout<<now<<":"<<dp[now]<<endl;
		if(done[now])continue;
		done[now] = true;
		bool flag = false;
		if(dp[now] != k&&a[now] == b[dp[now]])dp[now]++,flag = true;
		for(auto nxt:paths[now]){
			if(done[nxt]||dp[nxt]<dp[now])continue;
			dp[nxt] = dp[now];
			if(flag)dq.push_back(nxt);
			else dq.push_front(nxt);
		}
	}
	cout<<(dp[n] ==k?"Yes":"No");
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
