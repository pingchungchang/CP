#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int r,c;
	cin>>r>>c;
	int arr[3][3] = {};
	for(int i = 1;i<=2;i++)for(int j = 1;j<=2;j++)cin>>arr[i][j];
	cout<<arr[r][c];
	return 0;
}

