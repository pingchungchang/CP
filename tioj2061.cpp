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
	while(s.size()>1e4)s.pop_back();
	string t = s;
	reverse(_all(t));
	int n = s.size();
	int dp[n+1][n+1] = {};
	for(int i= 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			
		}
	}
}

