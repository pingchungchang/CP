#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<vector<int>> init;
int main(){
	io
	int n,m;
	cin>>n>>m;
	init = vector<vector<int>>(n,vector<int>(m));
	for(int i = 0;i<n;i++)for(int j = 0;j<m;j++)cin>>init[i][j];
	int ans = INT_MAX;
	for(int i = 0;i<(1<<(n*m));i++){
		int tmp[n][m] = {};
		int cnt = 0;
		for(int a = 0;a<n;a++){
			for(int b = 0;b<m;b++){
				if(i&(1<<(a*m+b)))tmp[a][b] = 1;
				if(tmp[a][b] != init[a][b])cnt+=2;
			}
		}
		for(int j = 0;j<n;j++){
			for(int k = 0;k<m-1;k++){
				if(tmp[j][k] != tmp[j][k+1])cnt ++;
			}
		}
		for(int j = 0;j<n-1;j++){
			for(int k = 0;k<m;k++){
				if(tmp[j][k] != tmp[j+1][k])cnt++;
			}
		}
		ans = min(ans,cnt);
	}
	cout<<ans;
}

