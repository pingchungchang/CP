#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxm = 18;
const int mxn = 202;

int N,M,T;
int arr[mxn];
int alive[1<<mxm];
int dp[1<<mxm];

void check(int mask){
	alive[mask] = 0;
	for(int i = 0;i<N;i++){
		if((arr[i]&mask) == mask)alive[mask]++;
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M>>T;
	for(int i = 0;i<N;i++){
		string s;
		cin>>s;
		for(int j = 0;j<M;j++){
			if(s[j]=='O')arr[i]|=1<<j;
		}
	}
	for(int i = 0;i<(1<<M);i++){
		check(i);
	}
	for(auto &i:dp)i = 1e9;
	dp[0] = 0;
	for(int i = 0;i<(1<<M);i++){
		for(int j = 0;j<M;j++){
			if(i&(1<<j))continue;
			dp[i^(1<<j)] = min(dp[i^(1<<j)],dp[i]+T*alive[i]);
		}
	}
	cout<<dp[(1<<M)-1]<<'\n';
	return 0;
}
