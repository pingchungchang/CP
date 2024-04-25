#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll inf = 5e18;
const int mxn = 5050;
int pt[mxn][mxn];
ll arr[mxn];
ll dp[mxn][mxn];
int n;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		arr[i] += arr[i-1];
	}
	for(int i = 1;i<=n;i++)dp[i][i] = 0,pt[i][i] = i;
	for(int len = 2;len<=n;len++){
		for(int st = 1;st+len-1<=n;st++){
			int l = st,r = st+len-1;
			dp[l][r] = inf;
			for(int c = max(pt[l][r-1],l);c<=min(pt[l+1][r],r-1);c++){
				if(dp[l][r]>dp[l][c]+dp[c+1][r]){
					pt[l][r] = c;
					dp[l][r] = dp[l][c]+dp[c+1][r];
				}
			}
			dp[l][r] += arr[r]-arr[l-1];
		}
	}
	/*
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			cout<<(dp[i][j] >=inf?-1:dp[i][j])<<' ';
		}
		cout<<endl;
	}

   */
	cout<<dp[1][n];
}
