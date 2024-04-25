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
int main(){
	io
	int n;
	cin>>n;
	int arr[n];
	int total = 0;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		total += arr[i];
	}
	int dp[total/2+1] = {};
	for(int i = 0;i<n;i++){
		for(int j = total/2;j>=arr[i];j--){
			dp[j] = max(dp[j],dp[j-arr[i]]+arr[i]);
		}
	}
	ll a = dp[total/2],b = total-dp[total/2];
	cout<<a*a+b*b;	
}

