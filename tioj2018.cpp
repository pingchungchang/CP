#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


vector<ll> ans = {LLONG_MAX,0,0,0};
ll n;

vector<ll> calc(ll big){
	ll rest = n/big;
	vector<ll> re = {LLONG_MAX,0,0,0};
	for(int i = 1;i*i<=rest;i++){
		if(rest%i == 0){
			ll arr[] = {big,i,rest/i};
			sort(arr,arr+3);
			vector<ll> tmp = {2ll*(arr[0]*arr[1]+arr[1]*arr[2]+arr[0]*arr[2]),arr[0],arr[1],arr[2]};
			re = min(re,tmp);
		}
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i*i<=n;i++){
		if(n%i == 0){
			ans = min(ans,calc(n/i));
			ans = min(ans,calc(i));
		}
	}
	for(auto &i:ans)cout<<i<<' ';
}
