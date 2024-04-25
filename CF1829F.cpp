#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	int deg[n+1] = {};
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		deg[a]++,deg[b]++;
	}
	map<int,int> cnt;
	for(int i = 1;i<=n;i++){
		cnt[deg[i]]++;
	}
	cnt.erase(1);
	if(cnt.size() == 1){
		cout<<cnt.begin()->fs<<' '<<(cnt.begin()->fs-1)<<'\n';
	}
	else{
		int tar = -1,rest = -1;
		for(auto &i:cnt){
			if(i.second == 1)tar = i.first;
			else rest = i.first;
		}
		cout<<tar<<' '<<rest-1<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
