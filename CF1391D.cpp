#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	string arr[n];
	for(auto &i:arr)cin>>i;
	if(min(n,m)>3){
		cout<<"-1";
		return 0;
	}
	int ans = n*m;
	int dp[2][8] = {};
	bool roll = 0;
	for(int i = 0;i<m;i++){
		roll ^= 1;
		for(auto &j:dp[roll])j = 1e9;
		int now = 0;
		for(int j = 0;j<n;j++){
			now<<=1;
			now ^= (arr[j][i] == '1');
		}
		for(int j = 0;j<(1<<n);j++){
			for(int l = 0;l<(1<<n);l++){
				bool flag = true;
				int check = j^l;
				for(int k = 1;k<n;k++){
					int f1 = (1<<(k-1))&check?1:0;
					int f2 = (1<<k)&check?1:0;
					if(!(f1^f2))flag = false;
				}
				if(flag)dp[roll][l] = min(dp[roll][l],dp[roll^1][j]+__builtin_popcount(l^now));
			}
		}
	}
	cout<<*min_element(dp[roll],dp[roll]+(1<<n));
}
