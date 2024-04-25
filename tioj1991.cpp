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
	int n,m;
	cin>>n>>m;
	int arr[n+1][m+1] = {};
	for(int i = 1;i<=n;i++)for(int j = 1;j<=m;j++)cin>>arr[i][j];
	int rdp[n+1][m+1] = {};
	for(int i = 1;i<=n;i++){
		for(int j= 1;j<=m;j++){
			rdp[i][j] = rdp[i][j-1];
			if(arr[i][j]==1&&arr[i][j-1] == 1)rdp[i][j]++;
		}
		for(int j = 1;j<=m;j++)rdp[i][j] += rdp[i-1][j];
	}
	int cdp[n+1][m+1] = {};
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=n;j++){
			cdp[j][i] = cdp[j-1][i];
			if(arr[j][i] == 1&&arr[j-1][i] == 1)cdp[j][i]++;
		}
		for(int j = 1;j<=n;j++)cdp[j][i] += cdp[j][i-1];
	}
//	for(int i = 1;i<=n;i++)for(int j= 1;j<=m;j++)rdp[i][j] += cdp[i][j];
//	cout<<endl;
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=m;j++)cout<<cdp[i][j]<<' ';cout<<endl;
//	}
	int q;
	cin>>q;
	while(q--){
		int sx,sy,ex,ey;
		cin>>sx>>sy>>ex>>ey;
		int total = rdp[ex][ey]-rdp[sx-1][ey]-rdp[ex][sy]+rdp[sx-1][sy];
		total += cdp[ex][ey]-cdp[sx][ey]-cdp[ex][sy-1]+cdp[sx][sy-1];
		cout<<total<<'\n';
	}
}

