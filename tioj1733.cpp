#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int n,m;
const int mxn = 55;
ll arr[mxn][mxn];

void solve(){
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin>>arr[i][j];
			arr[i][j] += arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
		}
	}
	ll ans = -1e18;
	for(int sx = 1;sx<=n;sx++){
		for(int sy = 1;sy<=m;sy++){
			for(int ex = sx;ex<=n;ex++){
				for(int ey = sy;ey<=m;ey++){
					ans = max(ans,arr[ex][ey]-arr[sx-1][ey]-arr[ex][sy-1]+arr[sx-1][sy-1]);
				}
			}
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n>>m)solve();
}
