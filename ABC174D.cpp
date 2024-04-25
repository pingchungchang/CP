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
const int mxn = 2e4+10;
const int shift = mxn/2;
bitset<mxn> dp;
int main(){
	io
	int n;
	int x,y;
	cin>>n;
	cin>>x>>y;
	int arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	dp[shift+arr[0]] = true;
	for(int i = 2;i<n;i+=2){
		dp = (dp<<arr[i])|(dp>>arr[i]);
	}
	bool flag = true;
	if(!dp[shift+x])flag = false;
	dp.reset();
	dp[shift] = true;
	for(int i = 1;i<n;i+=2){
		dp = (dp<<arr[i])|(dp>>arr[i]);
	}
	if(!dp[shift+y])flag = false;
	if(flag)cout<<"Yes";
	else cout<<"No";
}

