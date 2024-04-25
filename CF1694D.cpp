#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


vector<vector<int>> childs;
vector<pll> vals;
ll ans;
ll dfs(int now){
	ll addmx = 0;
	for(auto nxt:childs[now]){
		addmx += dfs(nxt);
	}
	if(addmx<vals[now].fs){
		ans++;
		return vals[now].sc;
	}
	else{
		return min(addmx,vals[now].sc);
	}
}
void solve(){
	int n;
	cin>>n;
	ans = 0;
	vals = vector<pll>(n+1,make_pair(0,0));
	childs = vector<vector<int>>(n+1);
	for(int i = 2;i<=n;i++){
		int p;
		cin>>p;
		childs[p].push_back(i);
	}
	for(int i = 1;i<=n;i++){
		cin>>vals[i].fs>>vals[i].sc;
	}
	dfs(1);
	cout<<ans<<'\n';
	return;
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

