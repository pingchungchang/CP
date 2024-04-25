#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int bit = 24;
int dp[1<<bit];
int n;
string s;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	while(n--){
		cin>>s;
		int a = 1<<(s[0]-'a'),b = 1<<(s[1]-'a'),c = 1<<(s[2]-'a');
		dp[a]++,dp[b]++,dp[c]++,dp[a|b]--,dp[a|c]--,dp[b|c]--,dp[a|b|c]++;
	}
	for(int i = 0;i<bit;i++){
		for(int j = 0;j<(1<<bit);j++){
			if(j&(1<<i))dp[j] += dp[j^(1<<i)];
		}
	}
	ll ans = 0;
	for(auto &i:dp)ans ^= 1ll*i*i;
	cout<<ans;
}
