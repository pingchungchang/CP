#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 110;
int arr[mxn][mxn],brr[mxn][mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			char c;
			cin>>c;
			arr[i][j] = c-'0';
		}
	}
	if(n<=1){
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++)cout<<arr[i][j];
			cout<<'\n';
		}
		return 0;
	}
	for(int i = 1;i<n-1;i++){
		brr[0][i] = arr[0][i-1];
		brr[i][0] = arr[i+1][0];
		brr[n-1][i] = arr[n-1][i+1];
		brr[i][n-1] = arr[i-1][n-1];
	}
	brr[0][0] = arr[1][0];
	brr[n-1][0] = arr[n-1][1];
	brr[0][n-1] = arr[0][n-2];
	brr[n-1][n-1] = arr[n-2][n-1];
	for(int i = 1;i<n-1;i++){
		for(int j = 1;j<n-1;j++)brr[i][j] = arr[i][j];
	}
	for(int i = 0;i<n;i++){
		for(int j =0;j<n;j++)cout<<brr[i][j];
		cout<<'\n';
	}
	return 0;
}
