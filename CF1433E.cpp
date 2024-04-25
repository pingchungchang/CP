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
ll c[22][22];
ll C(ll a,ll b){
	if(a<b)return 0;
	if(c[a][b] != 0)return c[a][b];
	return C(a-1,b-1)+C(a-1,b);
}
int main(){
	int n;
	cin>>n;
	ll dp[12];
	dp[0] = dp[1] = dp[2] = 1;
	for(int i = 3;i<=10;i++)dp[i] = dp[i-1]*(i-1);
//	for(int i = 1;i<=10;i++)cout<<dp[i]<<',';cout<<endl;
	for(int i = 0;i<=20;i++)c[i][0] = 1;
//	cout<<C(n-1,n/2-1)<<endl;
	cout<<C(n-1,n/2-1)*dp[n/2]*dp[n/2];
}

