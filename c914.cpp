#include <bits/stdc++.h>
using namespace std;

int dp[31] = {};
int f(int n){
	if(dp[n]!=0)return dp[n];
	dp[n] = f(n-1)*2+f(n-2)*3+f(n-3)*2;
	return dp[n];
}
int main(){
	int t;
	cin>>t;
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 7;
	dp[3] = 22;
	for(int i =0;i<t;i++){
		int n;
		cin>>n;
		cout<<f(n)<<'\n';
	}
}
