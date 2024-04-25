#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n+1];
	bool vis[n+1] = {};
	int ans[n+1] = {};
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i = 1;i<=n;i++){
		if(vis[i])continue;
		int now = i;
		int len = 0;
		do{
			len++;
			now = arr[now];
		}while(now != i);
		do{
			vis[now] = true;
			ans[now] = len;
			now = arr[now];
		}while(now != i);
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
