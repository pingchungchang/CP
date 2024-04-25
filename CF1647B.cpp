#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<vector<int>> arr,sum;
int l,r,u,d;

void dfs(int x,int y){
	if(arr[x][y] == 0)return;
//	cout<<x<<' '<<y<<'\n';
	arr[x][y] = 0;
	l = min(x,l),r = max(r,x),u = min(y,u),d = max(d,y);
	dfs(x+1,y);
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x,y-1);
	return;
}
void solve(){
	int n,m;
	cin>>n>>m;
	sum = vector<vector<int>>(n+2,vector<int>(m+2,0));
	arr = vector<vector<int>>(n+2,vector<int>(m+2,0));
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			char c;
			cin>>c;
			arr[i][j] = c-'0';
			sum[i][j] = arr[i][j]-sum[i-1][j-1]+sum[i][j-1]+sum[i-1][j];
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(arr[i][j] == 1){
				l = i;
				r = i;
				u = j;
				d = j;
				dfs(i,j);
				if(sum[r][d]-sum[l-1][d]-sum[r][u-1]+sum[l-1][u-1] != (r-l+1)*(d-u+1)){
//					cout<<l<<' '<<r<<' '<<u<<' '<<d<<'\n';
					cout<<"NO\n";
					return;
				}
			}
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

