#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> paths[mxn];
int deg[mxn];
bitset<mxn> del;

void solve(){
	int a,b;
	cin>>a>>b;
	cout<<(!del[a]&&!del[b]?2:1)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	queue<int> q;
	for(int i = 1;i<=n;i++){
		if(deg[i] == 1)q.push(i);
	}
	while(!q.empty()){
		auto now = q.front();
		del[now] = true;
		q.pop();
		for(auto nxt:paths[now]){
			deg[nxt]--;
			if(deg[nxt] == 1)q.push(nxt);
		}
	}
	int t;cin>>t;
	while(t--)solve();
}
