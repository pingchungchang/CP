#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	int n,m,p,t;
	cin>>n>>m>>p>>t;
	vector<vector<ll>> arr(n+2,vector<ll>(m+2,0));
	for(int i = 0;i<p;i++){
		int x,y;
		cin>>x>>y;
		arr[x+1][y+1] = 1LL;
	}
	for(int asd = 0;asd<t;asd++){
		vector<vector<ll>> a2 = arr;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=m;j++){
				a2[i][j] = arr[i-1][j]+arr[i][j]+arr[i+1][j]+arr[i][j+1]+arr[i][j-1];
			}
		}
		arr = a2;
	}
	ll ans = 0;
	for(int i = 1;i<=n;i++)for(int j = 1;j<=m;j++)ans += arr[i][j];
	cout<<ans;
}
