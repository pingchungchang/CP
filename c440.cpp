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
	string s;
	cin>>s;
	ll dp[4] = {0,0,0};
	for(auto i:s){
		if(i == 'Q'){
			dp[2]+= dp[1];
			dp[0]++;
		}
		else if(i == 'A'){
			dp[1]+= dp[0];
		}
	}
	cout<<dp[2];
}

