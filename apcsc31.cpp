#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
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
	int n,m;
	cin>>n>>m;
	ll arr[n+1][m+1];
	memset(arr,0LL,sizeof(arr));
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++)cin>>arr[i][j];
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++)arr[i][j] += max(arr[i-1][j],arr[i][j-1]);
	}
	cout<<arr[n][m];
}

