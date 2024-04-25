#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int n,t,m;
vector<pii> v;
int arr[11];
int ans = 0;

void dfs(int now,int mex){
	//for(int i = 1;i<now;i++)cout<<arr[i]<<' ';cout<<endl;
	if(t-mex>n-now+1)return;
	if(now == n+1){
		for(auto &i:v){
			if(arr[i.fs] == arr[i.sc])return;
		}
		/*
		cout<<ans<<":";
		for(int i = 1;i<now;i++)cout<<arr[i]<<' ';cout<<endl;
	   */
		ans++;
		return;
	}
	for(int i = 1;i<=min(mex+1,t);i++){
		arr[now] = i;
		dfs(now+1,max(mex,i));
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>t>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}
	dfs(1,0);
	cout<<ans;
}
