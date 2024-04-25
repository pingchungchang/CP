#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

int main(){
	io
	int n;
	cin>>n;
	int arr[n+1][n+1] = {};
	for(int i = 1;i<=n;i++)cin>>arr[i][i];
	int cnt = arr[n][n]-1;
	for(int i = n-1;i>=1&&cnt>0;i--,cnt--){
		arr[n][i] = arr[n][n];
	}
	for(int i = n-1;i>=1;i--){
		int cnt = arr[i][i];
		int r = i,c = i;
		while(cnt>0){
			arr[r][c] = arr[i][i];
			cnt--;
			if(r+1<=n&&arr[r+1][c] == 0)r++;
			else if(c>=1&&arr[r][c-1] == 0)c--;
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j= 1;j<=i;j++)cout<<arr[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}

