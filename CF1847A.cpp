#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n;
	ll k;
	cin>>n>>k;
	ll arr[n];
	ll total = 0;
	vector<ll> v;
	for(auto &i:arr)cin>>i;
	k--;
	for(int i = 1;i<n;i++){
		v.push_back(abs(arr[i]-arr[i-1]));
		total += abs(arr[i]-arr[i-1]);
	}
	sort(v.begin(),v.end());
	while(k--){
		total -= v.back();
		v.pop_back();
	}
	cout<<total<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
