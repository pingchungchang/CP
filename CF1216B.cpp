#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	pll arr[n];
	for(int i = 0;i<n;i++){
		arr[i].sc = i+1;
		cin>>arr[i].fs;
	}
	sort(arr,arr+n,greater<pll>());
	ll ans = 0;
	for(ll i = 0;i<n;i++){
		ans ++;
		ans += i*arr[i].fs;
	}
	cout<<ans<<'\n';
	for(auto i:arr)cout<<i.sc<<' ';
}
