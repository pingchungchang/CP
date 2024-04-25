#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ll n,x;
	cin>>n>>x;
	ll arr[n];
	ll dp[x+1];
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(auto &i:dp)i = INT_MAX;
	
	
	sort(arr,arr+mxn,greater<int>());
}
