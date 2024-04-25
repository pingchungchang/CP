#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	int arr[m][n];
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++)cin>>arr[i][j];
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			bool flag = false;
			for(int k = 0;k<m;k++){
				for(int kk = 1;kk<n;kk++){
					if(arr[k][kk] == i&&arr[k][kk-1] == j)flag = true;
					if(arr[k][kk] == j&&arr[k][kk-1] == i)flag = true;
				}
			}
			if(!flag)ans++;
		}
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
