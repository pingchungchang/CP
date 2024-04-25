#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	int row[n*m+1] = {};
	vector<int> v[n];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			int k;
			cin>>k;
			row[k] = i;
			v[i].push_back(k);
		}
	}
	int deg[n] = {};
	vector<int> paths[n];
	for(int i = 0;i<m;i++){
		vector<int> vv;
		for(int j = 0;j<n;j++){
			int k;
			cin>>k;
			vv.push_back(k);
		}
		for(int j = 1;j<n;j++){
			paths[row[vv[j-1]]].push_back(row[vv[j]]);
			deg[row[vv[j]]]++;
		}
	}
	vector<int> ans;
	queue<int> q;
	for(int i = 0;i<n;i++){
		if(!deg[i])q.push(i);
	}
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		ans.push_back(now);
		for(auto nxt:paths[now]){
			deg[nxt]--;
			if(!deg[nxt])q.push(nxt);
		}
	}
	for(auto &i:ans){
		for(auto &j:v[i])cout<<j<<' ';
		cout<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
