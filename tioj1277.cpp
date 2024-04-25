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
#define int ll
main(){
	io
	int n;
	cin>>n;
	int arr[n+1][n+1] = {};
	for(int i = 1;i<=n;i++)for(int j = 1;j<=n;j++){
		cin>>arr[i][j];
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			arr[i][j] = arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+arr[i][j];
//			cout<<arr[i][j]<<' ';
		}
//		cout<<endl;
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			int now = 0;
			for(int k = 1;k<=n;k++){
				int tmp = arr[j][k]-arr[i-1][k]-arr[j][k-1]+arr[i-1][k-1];
//				cout<<i<<' '<<j<<' '<<k<<' '<<tmp<<endl;
				ans = max(ans,now+tmp);
				now = max(0LL,now+tmp);
			}
//			cout<<i<<' '<<j<<' '<<ans<<endl;
		}
	}
	cout<<ans;
}

