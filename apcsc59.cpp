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
	ll dp[2][3];
	memset(dp,0LL,sizeof(dp));
	int now = 0,pre = 1;
	for(int i = 0;i<n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		swap(now,pre);
		dp[now][0] = max(dp[pre][1],dp[pre][2])+a;
		dp[now][1] = max(dp[pre][0],dp[pre][2])+b;
		dp[now][2] = max(dp[pre][0],dp[pre][1])+c;
	}
	cout<<*max_element(dp[now],dp[now]+3);
}

