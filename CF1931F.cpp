#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
vector<int> paths[mxn];
int deg[mxn];
int n,k;
queue<int> q;

void solve(){
	for(int i = 0;i<=n;i++){
		paths[i].clear();
		deg[i] = 0;
	}
	cin>>n>>k;
	for(int i = 0;i<k;i++){
		int tmp[n];
		for(auto &j:tmp)cin>>j;
		for(int j = 2;j<n;j++){
			paths[tmp[j-1]].push_back(tmp[j]);
			deg[tmp[j]]++;
		}
	}
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		if(!deg[i])q.push(i);
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		cnt++;
		for(auto nxt:paths[now]){
			deg[nxt]--;
			if(!deg[nxt]){
				q.push(nxt);
			}
		}
	}
	cout<<(cnt == n?"YES\n":"NO\n");
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
