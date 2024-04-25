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
int main(){
	io
	int n,m,q;
	cin>>n>>m>>q;
	int arr[2][n+2][m+2];
	for(auto &i:arr)for(auto &j:i)for(auto &w:j)w = 0;
	int now = 1,pre = 0;
	for(int i = 1;i<=n;i++)for(int j = 1;j<=m;j++)cin>>arr[now][i][j];
	int t = 0;
	while(q--){
		t++;
		swap(now,pre);
		for(int i = 1;i<=n;i++)for(int j= 1;j<=m;j++)arr[now][i][j] = arr[pre][i][j];
		int k;
		cin>>k;
		while(k--){
			int r,c;
			cin>>r>>c;
			for(int i = -1;i<=1;i++)for(int j =-1;j<=1;j++)if(arr[pre][r+i][c+j]<=t)arr[now][r+i][c+j] = t+3;
			arr[now][r][c] = t+5;
		}
	}
	int ans = 0;
	for(int i = 1;i<=n;i++)for(int j = 0;j<=m;j++)if(arr[now][i][j]<=t)ans++;
	cout<<ans;
	return 0;
}

