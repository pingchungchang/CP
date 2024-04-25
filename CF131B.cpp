#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n];
	map<int,int> mp;
	ll ans = 0;
	for(auto &i:arr){
		cin>>i;
		ans += mp[-i];
		mp[i]++;
	}
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t =1;
	while(t--)solve();
}
