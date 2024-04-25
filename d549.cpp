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
	ll a,b,c;
	while(cin>>a>>b>>c){
		cout<<fixed<<setprecision(2)<<sqrt(a*a+c*c-b*b)<<'\n';
	}
	return 0;
}
//dp[i] = dp[j]+(sum[i]-sum[j]) for j<i-m
