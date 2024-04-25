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
bool lcs(string &a,string &b){
	int dp[a.size()][b.size()] = {};
	for(int i = 0;i<a.size();i++){
		if(a[i] == '$'){
			for(int j= 0;j<b.size();j++)dp[i][j] = 1;
		}
		else{
			for(int j= 0;j<b.size();j++){
				if(a[i] == b[j])dp[i][j] = 1;
			}
		}
	}
	if(a[0] == '$'){
		for(int i = 1;i<a.size();i++)dp[0][i] +=dp[0][i-1];
	}
	for(int i = 1;i<a.size();i++){
		for(int j = 0;j<b.size();j++){
			if(a[i] == b[j]){
				if(j != 0)dp[i][j] = dp[i-1][j-1]+1;
				else dp[i][j] = 1;
			}
			else if(a[i] == '$'){
				if(j != 0)dp[i][j] = max(dp[i][j-1],dp[i-1][j-1])+1;
				else dp[i][j] = 1;
			}
		}
	}
//	for(auto &i:dp){
//		for(auto &j:i)cout<<j<<' ';cout<<endl;
//	}
	if(dp[a.size()-1][b.size()-1] == b.size())return true;
	else return false;
}
int main(){
	io
	string s;
	cin>>s;
	string t;
	while(cin>>t){
		if(lcs(s,t)){
			cout<<t<<'\n';
		}
	}
	return 0;
}

