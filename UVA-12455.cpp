#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int asd=0;asd<t;asd++){
		int n;
		cin>>n;
		int dp[n+1] = {0};
		int p;
		cin>>p;
		int v[p];
		for(int i =0;i<p;i++)cin>>v[i];
		for(int i =0;i<p;i++){
			for(int j =n;j>=v[i];j--){
				dp[j] = max(dp[j],dp[j-v[i]]+v[i]);
			}
		}
		if(dp[n]==n)cout<<"YES\n";
		else cout<<"NO\n";
	}
}
