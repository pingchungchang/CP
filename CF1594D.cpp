#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

map<int,vector<int>> paths;
set<int> goneto;
set<int> tmp;
int cnt;
bool flag;
void dfs(int now){
	tmp.insert(now);
	if(tmp.find(-now) != tmp.end()){
		flag = false;
		return;
	}
	if(now<0)cnt++;
	for(auto nxt:paths[now]){
		if(tmp.find(nxt) != tmp.end())continue;
		dfs(nxt);
	}
	return;
}
void solve(){
	paths.clear();
	goneto.clear();
	flag = true;
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		string in;
		cin>>a>>b>>in;
		if(in[0] == 'i'){
			b = -b;
		}
		paths[a].push_back(b);
		paths[-a].push_back(-b);
		paths[b].push_back(a);
		paths[-b].push_back(-a);
	}
	int ans =0;
	for(int i = 1;i<=n;i++){
		if(goneto.find(i) == goneto.end()){
			cnt = 0;
			tmp.clear();
			dfs(i);
			ans += max(cnt,(int)tmp.size()-cnt);
			for(auto i:tmp){
				goneto.insert(abs(i));
			}
		}
	}
	if(!flag)cout<<"-1\n";
	else cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

