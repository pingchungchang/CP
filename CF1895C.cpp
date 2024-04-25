#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int sh = 50;
int dp[6][6][1100];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	ll ans = 0;
	cin>>n;
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		int pref = 0,suf =0;
		for(auto &j:s)pref += j-'0';
		dp[s.size()][s.size()][pref+sh]++;
		for(int j = s.size()-1;j>=0;j--){
			suf += s[j]-'0';
			pref -= s[j]-'0';
			dp[s.size()][j][pref-suf+sh]++;
		}
	}
	for(int i = 1;i<=5;i++){
		for(int j = 1;j<=5;j++){
			if((i+j)&1)continue;
			int mid = (i+j)>>1;
			if(mid>i){
				for(int k = -sh;k<=sh;k++){
					ans += 1ll*dp[i][i][sh+k]*dp[j][mid-i][sh-k];
				}
			}
			else{
				for(int k = -sh;k<=sh;k++){
					ans += 1ll*dp[i][mid][sh+k]*dp[j][j][k+sh];
				}
			}
		}
	}
	cout<<ans;
}
