#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	vector<pii> v;
	for(int i = 0;i<n;i++){
		v.push_back({i,0});
	}
	vector<vector<int>> grid(n,vector<int>(n,0));
	for(auto &i:v){
		pii now = i;
		do{
			if(!k)break;
			k--;
			grid[now.fs][now.sc] = 1;
			now.fs++;now.sc++;
			if(now.fs>=n)now.fs -= n;
		}while(now.fs != i.fs);
	}
	pii r = {1e9,0},c = r;
	for(int i = 0;i<n;i++){
		int cnt = 0;
		for(auto &j:grid[i])cnt+=j;
		r.fs = min(r.fs,cnt);
		r.sc = max(r.sc,cnt);
		cnt = 0;
		for(int j = 0;j<n;j++){
			cnt += grid[j][i];
		}
		c.fs = min(c.fs,cnt);
		c.sc = max(c.sc,cnt);
	}
	cout<<(r.sc-r.fs)*(r.sc-r.fs)+(c.sc-c.fs)*(c.sc-c.fs)<<'\n';
	for(auto &i:grid){
		for(auto &j:i)cout<<j;
		cout<<'\n';
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
