#include <bits/stdc++.h>
using namespace std;

string s;

bool f(int l,int r){
	int dp[3] = {};
	for(int i = l;i<=r;i++){
		dp[s[i]-'a']++;
	}
	if(dp[0]>dp[1]&&dp[0]>dp[2])return true;
	else return false;
}
void solve(){
	int n;
	cin>>n;
	cin>>s;
	for(int i = 2;i<=10;i++){
		for(int j = 0;j<=n-i;j++){
			if(f(j,j+i-1)){
				cout<<i<<'\n';
				return;
			}
		}
	}
	cout<<-1<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
