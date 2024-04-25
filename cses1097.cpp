#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[5001][5001];
ll pref[5001];
ll MX = 1e13+5;
ll recursive(ll s,ll e){
	if(dp[s][e] == MX){
		dp[s][e] = min(pref[e]-pref[s]-recursive(s,e-1),pref[e+1]-pref[s+1]-recursive(s+1,e));
	}
//	cout<<s<<' '<<e<<' '<<dp[s][e]<<endl;
	return dp[s][e];
}
int main(){
	memset(pref,0,5001*sizeof(ll));
	memset(dp,MX,5001*5001*sizeof(ll));
	MX = dp[0][0];
	ll n;
	cin>>n;
	ll sum =0;
	vector<ll> v(n,0);
	for(ll i =0;i<n;i++){
		cin>>v[i];
		pref[i+1] =pref[i] + v[i];
		dp[i][i] = 0;
		if(i !=0)dp[i-1][i] = min(v[i-1],v[i]);
		sum += v[i];
	}
//	for(ll i =0;i<=4;i++)cout<<pref[i]<<' ';
//	cout<<endl<<endl;
	cout<<sum-recursive(0,n-1)<<endl;
//	for(ll i =0;i<n;i++){
//		for(ll j =0;j<n;j++)cout<<dp[i][j]<<' ';
//		cout<<endl;
//	}
} 
//10
//-8 4 6 -2 5 -4 -5 9 10 1


//4
//4 5 1 3
//pref: 0 4 9 10 13


