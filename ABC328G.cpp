#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll inf = 4e18;
const int mxn = 22;
ll dp[1<<mxn];
ll arr[mxn],brr[mxn],C;
ll pre[mxn][mxn][mxn];
ll n;

inline ll calc(ll l,ll r,ll lst){
	return pre[l][r][lst];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>C;
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<n;i++)cin>>brr[i];
	for(int l = 0;l<n;l++){
		for(int len = 1;len+l<=n;len++){
			for(int head = 0;head+len<=n;head++){
				for(int i = 0;i<len;i++)pre[l][l+len-1][head+len-1]+=abs(arr[l+i]-brr[head+i]);
			}
		}
	}
	for(auto &i:dp)i = inf;
	dp[0] = 0;
	/*
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			for(int k = 0;k<n;k++){
				cout<<i<<' '<<j<<' '<<k<<":"<<pre[i][j][k]<<endl;
			}
		}
	}

   */
	for(int i = 1;i<(1<<n);i++){
		ll cnt = __builtin_popcount(i);
		for(int r = 0;r<n;r++){
			if(!(i&(1<<r)))continue;
			int mask = 0;
			for(int l = r;l>=0&&(i&(1<<l));l--){
				mask |= 1<<l;
				//cout<<i<<":"<<l<<','<<r<<":"<<calc(l,r,cnt-1)<<endl;
				dp[i] = min(dp[i],dp[i^mask]+calc(l,r,cnt-1)+C);
			}
		}
		//cout<<i<<":"<<dp[i]<<endl;
	}
	cout<<dp[(1<<n)-1]-C;
}
