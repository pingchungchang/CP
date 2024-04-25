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
int n,a;
ll arr[21][21];
void solve(){
	memset(arr,0LL,sizeof(arr));
	ll arr[n+1][n+1] = {};
	arr[1][1] = a;
	for(int i = 1;i<=n;i++){
		if(i != 1)arr[i][1] = a+i;
		for(int j = 2;j<=n;j++){
			arr[i][j] = abs(arr[i][j-1])*17%103*((i+j)%2 == 1?-1:1)*(arr[i][j-1]<0?-1:1);
		}
	}
//	for(int i = 1;i<=n;i++){
//		for(int j= 1;j<=n;j++)cout<<arr[i][j]<<' ';cout<<endl;
//	}	
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			arr[i][j] = arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+arr[i][j];
		}
	}
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			for(int k = i;k<=n;k++){
				for(int l = j;l<=n;l++){
					ans = max(ans,arr[k][l]-arr[i-1][l]-arr[k][j-1]+arr[i-1][j-1]);
				}
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	while(cin>>n>>a){
		solve();
	}
}

