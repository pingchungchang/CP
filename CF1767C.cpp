#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 110;
const int mod = 998244353;
int dp[mxn];
int arr[mxn][mxn];
int n;

inline int mad(int a,int b){
	a += b;
	return a>=mod?a-mod:a;
}
inline int mub(int a,int b){
	return mad(a,mod-b);
}

inline bool check_all(int p){
	for(int i = p+1;i<=n;i++){
		for(int j = i;j<n;j++){
			if(arr[i][j] != 1)return false;
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++)cin>>arr[i][j];
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		if(arr[i][i] == 2){
			cout<<0;
			return 0;
		}
	}
	dp[0][0] = 1;
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<i;j++){
			bool flag = true;
			for(int k = j;k<=i;k++){
				if(arr[k][i] == 2)flag = false;
			}
			if(flag)dp[j][i] = mad(dp[j][i],dp[j][i-1]);
		}
		for(int j = 0;j<i-1;j++){
			bool flag = true;
			for(int tl = j+1;tl<i;tl++){
				for(int tr = tl;tr<i;tr++){
					if(arr[tl][tr] == 2)flag = false;
				}
			}
			if(flag){
				for(int tl = )
			}
		}
	}
}
