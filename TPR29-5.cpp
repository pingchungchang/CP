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

ll f(ll a,ll b,ll c){
	return (a^(b|c))^(a+b);
}
int main(){
	io
	ll arr[3];
	for(auto &i:arr)cin>>i;
	ll ans= INT_MAX;
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			for(int k = 0;k<3;k++){
				if(i == j||j == k||i == k)continue;
				ans = min(ans,f(arr[i],arr[j],arr[k]));
			}
		}
	}
	cout<<ans;
}

