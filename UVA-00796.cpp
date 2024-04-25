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

const int mxn = 1e6+10;
vector<int> paths[mxn];
int idx = 1;
int id[mxn];
int low[mxn];
int n;
vector<pii> ans;
int tarjan(int now,int par){
	low[now] = idx++;
	id[now] = low[now];
	for(auto nxt:paths[now]){
		if(nxt == par)continue;
		if(!id[nxt])low[now] = min(low[now],tarjan(nxt,now));
		else low[now] = min(low[now],low[nxt]);
	}
	if(id[now] == low[now]&&now != par){
		ans.push_back({par,now});
	}
	return low[now];
}
void solve(){
	ans.clear();
	for(int i= 0;i<n;i++){
		paths[i].clear();
		low[i] = id[i] = 0;
	}
	for(int i = 0;i<n;i++){
		int s;
		cin>>s;
		string t;
		cin>>t;
		t.erase(t.begin());
		t.pop_back();
		int tt = stoi(t);
		while(tt--){
			int b;
			cin>>b;
			paths[s].push_back(b);
		}
	}
	for(int i = 0;i<n;i++){
		if(!low[i]){
			tarjan(i,i);
		}
	}
	sort(_all(ans));
	cout<<ans.size()<<" critical links\n";
	for(auto &i:ans)cout<<min(i.fs,i.sc)<<"-"<<max(i.fs,i.sc)<<'\n';
	cout<<'\n';
}
int main(){
	io
	while(cin>>n){
		if(n == -1)return 0;
		solve();
	}
}

