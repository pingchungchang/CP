#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 110;
int arr[mxn];
int ans[mxn];

void dfs(int l,int r,int dep){
	int big = max_element(arr+l,arr+r+1)-arr;
	ans[big] = dep;
	if(big != r)dfs(big+1,r,dep+1);
	if(big != l)dfs(l,big-1,dep+1);
}

void solve(){
	int n;
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	dfs(0,n-1,0);
	for(int i = 0;i<n;i++)cout<<ans[i]<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
