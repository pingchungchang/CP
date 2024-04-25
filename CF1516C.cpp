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
ll gcd(ll a,ll b){
	if(a>b)swap(a,b);
	while(b != 0){
		a %= b;
		swap(a,b);
	}
	return a;
}
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
	ll G = arr[0];
	for(auto &i:arr)G = gcd(G,i);
	if(total&1){
		cout<<"0\n";
		return 0;
	}
	int dp[total/2+1]={};
	for(int i = 0;i<n;i++){
		for(int j = total/2;j>=arr[i];j--){
			dp[j] = max(dp[j],dp[j-arr[i]]+arr[i]);
		}
	}
	if(dp[total/2] != total/2){
		cout<<"0\n";
		return 0;
	}
	for(int i = 0;i<n;i++){
		if((arr[i]/G)&1){
			cout<<"1\n"<<i+1<<'\n';
			return 0;
		}
	}
}

