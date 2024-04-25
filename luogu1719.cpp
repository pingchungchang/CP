#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 128;
int arr[mxn][mxn];
int n;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++)cin>>arr[i][j],arr[i][j] = arr[i-1][j]+arr[i][j-1]+arr[i][j]-arr[i-1][j-1];
	}
	int ans = INT_MIN;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			for(int ii = i;ii<=n;ii++){
				for(int jj = j;jj<=n;jj++){
					ans = max(ans,arr[ii][jj]-arr[ii][j-1]-arr[i-1][jj]+arr[i-1][j-1]);
				}
			}
		}
	}
	cout<<ans;
}
