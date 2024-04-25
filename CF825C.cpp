#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	ll ans = 0;
	for(auto &i:arr){
		while(i>k*2){
			k*=2;
			ans++;
		}
		k = max(k,i);
	}
	cout<<ans;
}
