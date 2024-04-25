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

const int mxn = 1e6+10;
ll lpf[mxn],phi[mxn];
ll dp[mxn];
int main(){
	for(int i = 2;i<mxn;i++){
		if(!lpf[i]){
			for(int j = i+i;j<mxn;j+=i){
				lpf[j] = i;
			}
		}
	}
	for(int i = 2;i<mxn;i++){
		if(!lpf[i])phi[i] = i-1;
		else{
			int pre = i/lpf[i];
			if(pre%lpf[i] == 0)phi[i] = phi[pre]*(i/pre);
			else{
				phi[i] = phi[pre]*(i/pre)*(lpf[i]-1)/lpf[i];
			}
		}
	}
	dp[1] = 3;
	for(int i = 2;i<mxn;i++){
		dp[i] = dp[i-1]+phi[i]*2;
	}
//	for(int i = 2;i<=10;i++)cout<<i<<": "<<phi[i]<<'\n';return 0;
//	for(int i = 1;i<=10;i++)cout<<i<<": "<<dp[i]<<'\n';
	io
	int n;
	bool flag = false;
	while(cin>>n){
		if(n<0)return 0;
		if(flag)cout<<'\n';
		cout<<dp[n];
		flag = true;
	}
	return 0;
}

