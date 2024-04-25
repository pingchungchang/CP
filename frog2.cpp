#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int arr[n];
	int dp[n];
	memset(dp,1000000,n*sizeof(int));
	dp[0] = 0;
	for(int i =0;i<n;i++){
		cin>>arr[i];
	}
	for(int i =1;i<n;i++){
		for(int j = i-1;j>=max(0,i-m);j--){
			dp[i] = min(dp[i],dp[j]+abs(arr[i]-arr[j]));
			//cout<<dp[j]+abs(arr[i]-arr[j])<<endl;
		}
	}
	cout<<dp[n-1];
}
