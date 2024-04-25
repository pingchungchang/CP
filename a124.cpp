#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<int> goneto;
int n,m;
vector<vector<int>> v;

bool dfs(int now,int col){
	goneto[now] = col;
	col = -col;
	bool returns = true;
	for(auto nxt:v[now]){
		if(goneto[nxt] == 0)returns = returns&&dfs(nxt,col);
		else if(goneto[nxt] != col)return false;
	}
	return returns;
}
int main(){
	cin>>n>>m;
	int t = 0;
	goneto = vector<int>(n,0);
	v = vector<vector<int>>(n);
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 0;i<n;i++){
		if(goneto[i] == 0){
			t++;
			if(dfs(i,t) == false){
				cout<<0;
				return 0;
			}
		}
	}
	int ans = 0;
	map<int,int> mp;
	for(int i = 0;i<n;i++){
		if(mp.count(goneto[i]) == 0)mp[goneto[i]] = 1;
		else mp[goneto[i]]++;
	}
	for(int i = 1;i<=t;i++){
		if(mp.count(i) == 0||mp.count(-i) == 0)continue;
		else ans += min(mp[i],mp[-i]);
	}
	cout<<ans;
}

