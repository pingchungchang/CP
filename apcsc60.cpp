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
	string a,b;
	cin>>a>>b;
	ll dp[a.size()];
	memset(dp,0,sizeof(dp));
	for(int i = 0;i<b.size();i++){
		for(int j = a.size()-1;j>=1;j--){
			if(b[i] == a[j])dp[j] += dp[j-1];
		}
		if(b[i] == a[0])dp[0]++;
	}
	cout<<dp[a.size()-1];
}

