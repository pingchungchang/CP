#include <bits/stdc++.h>
using namespace std;

long long dp[755];
int main(){
	memset(dp,0LL,sizeof(dp));
	dp[0] = 1;
	for(int i = 1;i<=749;i+=2){
		for(int j = 0;j<=750;j++){
			if(j+i>750)break;
			dp[j+i]+= dp[j];
		}
	}
	int m;
	cin>>m;
	for(int i =0;i<m;i++){
		int k;
		cin>>k;
		cout<<dp[k]<<'\n';
	}
	return 0;
}
