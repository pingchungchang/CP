#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<vector<int>> paths;
vector<int> goneto;
bool flag;
vector<int> cnt;
void dfs(int now,int col){
	if(goneto[now] != 0&&goneto[now] != col){
		flag = false;
		return;
	}
	goneto[now] = col;
	for(auto nxt:paths[now]){
		if(goneto[nxt] == 0){
			dfs(nxt,-col);
		}
		else if(goneto[nxt] != -col)flag = false;
	}
	return;
}
void solve(){
	int n;
	cin>>n;
	flag = true;
	goneto = vector<int>(n+1,0);
	cnt = vector<int>(n+1,0);
	paths = vector<vector<int>>(n+1);
	for(int i = 0;i<n;i++){
		int a,b;
		cin>>a>>b;
		cnt[a]++;
		cnt[b]++;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		if(cnt[i] != 2)flag = false;
	}
	for(int i = 1;i<=n;i++){
		if(goneto[i] == 0)dfs(i,1);
//		cout<<goneto[i]<<' ';
	}
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	return;	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

