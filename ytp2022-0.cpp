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

ll dp[110][110];
ll C(ll a,ll b){
//	cout<<a<<' '<<b<<endl;
	if(a<b)return 0;
	if(b == 0){
		dp[a][b] = 1;
		return 1;
	}
	if(!dp[a][b])dp[a][b] = C(a-1,b)+C(a-1,b-1);
	return dp[a][b];
}
int main(){
	io
	ll n = 11;
	string s;
	getline(cin,s);
	for(auto &i:s)if(i == ',')i = ' ';
	stringstream ss(s);
	ll arr[n];
	for(auto &i:arr)i = 0;
	ll total = 0;
	ll k;
	int p = 0;
	while(ss>>k){
		arr[p++] = k;
		total += k;
	}
	ll ans = 1;
	for(ll i = 0;i<n;i++){
		ans *= C(total,arr[i]);
		total -= arr[i];
	}
	cout<<ans;
	
}

