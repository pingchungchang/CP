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
	bool flag = true;
	int arr[n+1],deg[n+1] = {};
	for(int i = 1;i<=n;i++)cin>>arr[i];
	if(k == 1){
		for(int i = 1;i<=n;i++)if(arr[i] != i)flag = false;
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
		return;
	}
	bool vis[n+1] = {};
	vector<int> paths[n+1];
	for(int i = 1;i<=n;i++){
		paths[i].push_back(arr[i]);
		deg[arr[i]]++;
	}
	queue<int> q;
	for(int i  =1;i<=n;i++)if(!deg[i])q.push(i);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			deg[nxt]--;
			if(!deg[nxt])q.push(nxt);
		}
	}
	for(int i = 1;i<=n;i++){
		if(!deg[i])continue;
		int now = i;
		int C = 0;
		do{
			deg[now] = 0;
			now = arr[now];
			C++;
		}while(now != i);
		if(C != k)flag = false;
	}
	if(!flag)cout<<"NO\n";
	else cout<<"YEs\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
