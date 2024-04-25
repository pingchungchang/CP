#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e4+10;
int dp[mxn];

int f(int b){
	if(b == 1)return 1;
	if(b == 0||b == 2)return 0;
	if(b == 5)return 0;
	if(b%2 == 0)return b/2;
	else if(b%4 == 1)return b/4;
	else return f(b/2);
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(dp,-1,sizeof(dp));
	int k,n;
	cin>>k>>n;
	if(k == 1)cout<<n;
	else cout<<f(n);
}
