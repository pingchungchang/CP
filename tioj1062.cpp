#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 110;
int arr[mxn][mxn];
int ans[mxn][mxn];

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)for(int j = 1;j<=m;j++)cin>>arr[i][j];
	for(int i = 1;i<=n;i++){
		for(int j= 1;j<=m;j++){
			for(int ii = 1;ii<=n;ii++){
				for(int jj = 1;jj<=m;jj++){
					ans[i][j] += arr[ii][jj]*(abs(i-ii)+abs(j-jj));
				}
			}
		}
	}
	pii p = {1,1};
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(ans[i][j]<ans[p.fs][p.sc])p = {i,j};
		}
	}
	cout<<p.fs<<' '<<p.sc;
}
