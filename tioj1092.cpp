#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

int n,m;
void solve(){
	int deg[n+1] = {};
	vector<int> paths[n+1];
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		deg[a]++;
		paths[b].push_back(a);
	}
	queue<pii> q;
	bool ans[n+1] = {};
	q.push({1,n});
	deg[n] = 1;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		deg[now.sc]--;
		if((now.fs&1) == 0){
			ans[now.sc] = true;
		}
		if(deg[now.sc] == 0){
			for(auto nxt:paths[now.sc]){
				q.push({ans[now.sc],nxt});
			}
		}
	}
//	for(int i = 1;i<=n;i++)cout<<ans[i];cout<<'\n';
	string s;
	cin>>s;
	pair<string,string> p = {"Mimi","Moumou"};
	if(s == "Mimi")swap(p.fs,p.sc);
	if(ans[1] == true)cout<<p.fs;
	else cout<<p.sc;
}
int main(){
	io
	while(cin>>n>>m){
		if(n == 0&&m == 0)return 0;
		else solve();
		cout<<'\n';
	}
}

