#include <bits/stdc++.h>
using namespace std;

int n;
int t;
int dp[1000000] = {};
void solve(){
	int arr[n] = {};
	memset(dp,0,sizeof(dp));
	int sum = 0;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		sum += arr[i];
	}
	if((sum&1)){
		cout<<"No\n";
		return;
	}
	sum /=2;
	for(int i = 0;i<n;i++){
		for(int j = sum;j>=arr[i];j--){
			dp[j] = max(dp[j],dp[j-arr[i]]+arr[i]);
		}
	}
	if(dp[sum] == sum)cout<<"Yes\n";
	else cout<<"No\n";
	return;
}
int main(){
	while(cin>>t>>n){
		for(int i = 0;i<t;i++)solve();
	}
}
