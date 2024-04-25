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

void solve(){
	ll n;
	cin>>n;
	ll arr[n];
	ll ans = 0;
	for(auto &i:arr)cin>>i;
	for(ll i = 1;i<n;i<<=1){
		for(ll j = 0;j<n;j+=i*2){
			if(abs(arr[j]-arr[j+i]) != i){
				cout<<"-1\n";
				return;
			}
			else{
				if(arr[j]>arr[j+i]){
					ans++;
					swap(arr[j],arr[j+i]);
				}
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

