#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 22;
int n;
int dist[mxn][mxn][mxn][mxn];
int arr[mxn][mxn];

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	cin>>n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++)cin>>arr[i][j];
	}
	for(int i = 1;i<=n;i++){
		for(int ii = 1;ii<=n;ii++){
			for(int j = 1;j<=n;j++){
				for(int jj = 1;jj<=n;jj++){
					dist[i][ii][j][jj] = 1e9;
				}
			}
			dist[i][ii][i][ii] = 0;
		}
	}

	for(int i = 1;i<=n;i++)for(int ii = 1;ii<=n;ii++)for(int j = 1;j<=n;j++)for(int jj = 1;jj<=n;jj++){
		if(abs(i-j)+abs(ii-jj) == 1){
			dist[i][ii][j][jj] = arr[j][jj];
			dist[j][jj][i][ii] = arr[i][ii];
		}
	}

	for(int k = 1;k<=n;k++){
		for(int kk = 1;kk<=n;kk++){
			for(int j = 1;j<=n;j++){
				for(int jj = 1;jj<=n;jj++){
					for(int i = 1;i<=n;i++){
						for(int ii = 1;ii<=n;ii++){
							dist[i][ii][j][jj] = min(dist[i][ii][j][jj],dist[i][ii][k][kk]+dist[k][kk][j][jj]);
						}
					}
				}
			}
		}
	}

	int q;
	cin>>q;
	while(q--){
		pii p1,p2;
		cin>>p1.fs>>p1.sc>>p2.fs>>p2.sc;
		int ans = dist[p1.fs][p1.sc][p2.fs][p2.sc]+arr[p1.fs][p1.sc];
		for(int i =1;i<=n;i++){
			for(int j =1;j<=n;j++){
				ans = min(ans,dist[p1.fs][p1.sc][i][j]+dist[i][j][p2.fs][p2.sc]-arr[i][j]+arr[p1.fs][p1.sc]);
				//cout<<i<<' '<<j<<":"<<dist[p1.fs][p1.sc][i][j]<<' '<<dist[i][j][p2.fs][p2.sc]<<' '<<arr[i][j]<<' '<<endl;
			}
		}
		ans = min(ans,dist[p1.fs][p1.sc][p2.fs][p2.sc]);
		ans = min(ans,dist[p2.fs][p2.sc][p1.fs][p1.sc]);
		cout<<ans<<'\n';
	}

	return 0;
}
