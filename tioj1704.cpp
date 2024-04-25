#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define _all(T) T.begin(),T.end()
#define pii pair<int,int>
#define fs first
#define sc second
const int mxn = 2002;
const int inf = 1e8;
int dp[mxn],arr[mxn][mxn];
int main(){
	int n,k;
	cin>>n>>k;
	pii w[n];
	for(int i = 0;i<n;i++){
		cin>>w[i].fs;
		w[i].sc = i;
	}
	for(int i = 0;i<n;i++)for(int j = 0;j<n;j++)cin>>arr[i][j];
	int small = mxn;
	fill(dp,dp+mxn,-inf);
	dp[0] = 0;
	sort(w,w+n);
	for(int i = 0;i<n;i++){
		for(int j = n;j>=1;j--){
			if(dp[j-1] <= -inf)continue;
//			cout<<i<<' '<<j<<',';
			dp[j] = max(dp[j],dp[j-1]+arr[w[i].sc][j-1]);
			if(dp[j]>=k){
				small = min(small,j);
			}
		}
	}
	if(small<mxn)cout<<small;
	else cout<<-1;
	return 0;
}
