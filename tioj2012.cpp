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
const int mxn= 606;
ld matrix[mxn][mxn];
ld ans[mxn];
void solve(){
	int n;
	cin>>n;
	int shuf[n];
	for(int i = 0;i<n;i++)shuf[i] = i;
	for(int i = 0;i<n;i++){
		int a = rand(),b = rand();
		swap(shuf[a%n],shuf[b%n]);
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<=n;j++)cin>>matrix[i][j];
	}
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			ld c = matrix[j][i]/matrix[i][i];
			for(int k = i;k<=n;k++){
				matrix[j][k] -= c*matrix[i][k];
			}
			matrix[j][i] = 0;
		}
	}
	for(int i = n-1;i>=0;i--){
		for(int j= n-1;j>i;j--){
			matrix[i][n] -= ans[j]*matrix[i][j];
		}
		ans[i] = matrix[i][n]/matrix[i][i];
	}
	for(int i = 0;i<n;i++)cout<<setprecision(13)<<ans[i]<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

