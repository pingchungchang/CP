#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<pii> paths[mxn];
ll pos[mxn];
bool done[mxn];
ll n,m;

void dfs(int now){
	done[now] = true;
	for(auto nxt:paths[now]){
		if(done[nxt.fs])continue;
		pos[nxt.fs] = pos[now]+nxt.sc;
		dfs(nxt.fs);
	}
	return;
}

void solve(){
	for(int i = 0;i<=n;i++){
		paths[i].clear();
		done[i] = pos[i] = 0;
	}
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		paths[a].push_back({b,c});
		paths[b].push_back({a,-c});
	}
	for(int i = 1;i<=n;i++){
		if(!done[i])dfs(i);
	}
	//for(int i = 1;i<=n;i++)cout<<pos[i]<<' ';cout<<'\n';
	for(int i = 1;i<=n;i++){
		for(auto nxt:paths[i]){
			if(pos[nxt.fs] != pos[i]+nxt.sc){
				cout<<"NO\n";
				return;
			}
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
