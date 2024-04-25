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
	int dp = 0;
	int ans = INT_MIN;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		dp = max(k,dp+k);
		ans = max(ans,dp);
	}
	cout<<ans;
}

