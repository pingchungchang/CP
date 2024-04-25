#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
vector<vector<pii>> paths;

vector<int> goneto;
int ans;
ll n,m;

void dfs(int now,int total){
//	cout<<now<<':';for(auto i:goneto)cout<<i<<' ';cout<<endl;
	goneto.push_back(now);
	if(goneto.size() == n){
		for(auto nxt:paths[now]){
			if(nxt.fs == goneto[0]){
				ans = min(ans,total+nxt.sc);
			}
		}
		goneto.pop_back();
		return;
	}
	for(auto nxt:paths[now]){
		bool flag = true;
		for(auto j:goneto){
			if(j == nxt.fs)flag = false;
		}
		if(!flag)continue;
		dfs(nxt.fs,total+nxt.sc);
	}
	goneto.pop_back();
	return;
}
int main(){
	io
	cin>>n>>m;
	paths = vector<vector<pii>>(n+1);
	for(int i = 0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		paths[a].push_back(make_pair(b,c));
		paths[b].push_back(make_pair(a,c));
	}
	ans = INT_MAX;
	for(int i = 1;i<=n;i++){
		dfs(i,0);
	}
	if(ans == INT_MAX)cout<<-1;
	else cout<<ans;
}

