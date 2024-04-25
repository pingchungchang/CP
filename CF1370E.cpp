#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	int cnt = 0;
	for(auto &i:a)cnt += i-'0';
	for(auto &i:b)cnt -= i-'0';
	if(cnt){
		cout<<"-1";
		return 0;
	}
	string ta,tb;
	for(int i = 0;i<n;i++){
		if(a[i] == b[i])continue;
		else ta += a[i],tb += b[i];
	}
	a = ta,b = tb;n = a.size();
	int arr[n] = {};
	for(int i = 0;i<n;i++){
		if(a[i] == '0')arr[i] = -1;
		else arr[i] = 1;
	}
	int ans = 0;
	if(a.empty()){
		cout<<ans;
		return 0;
	}
	int dp[n] = {};
	dp[0] = max(arr[0],0);
	for(int i = 1;i<n;i++){
		dp[i] = max(dp[i-1],0)+arr[i];
		ans = max(ans,abs(dp[i]));
	}
	dp[0] = max(arr[0],0);
	for(int i = 1;i<n;i++){
		dp[i] = min(dp[i-1],0)+arr[i];
		ans = max(ans,abs(dp[i]));
	}
	for(int i = 1;i<n;i++)arr[i] += arr[i-1],ans = max(abs(arr[i]),ans);
	cout<<ans;
}
