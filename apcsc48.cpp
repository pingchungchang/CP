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
	int n,m,s;
	cin>>n>>m>>s;
	int total = 0;
	int arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		total += arr[i];
	}
	if(m-total>=s){
		cout<<"0\n";
		return 0;
	}
	int tar = total-(s-(m-total));
	int dp[tar+1] = {};
	for(int i = 0;i<n;i++){
		for(int j = tar;j>=arr[i];j--){
			dp[j] = max(dp[j],dp[j-arr[i]]+arr[i]);
		}
	}
	cout<<total-dp[tar];
}

