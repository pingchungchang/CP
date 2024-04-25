#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n],brr[n];
	for(auto &i:arr)cin>>i;
	for(auto &i:brr)cin>>i;
	map<int,int> mp;
	for(int i = 0;i<n;i++){
		mp[arr[i]]++;
		mp[brr[i]]--;
	}
	for(auto &i:mp){
		if(i.sc != 0){
			cout<<"NO\n";
			return;
		}
	}
	for(auto &i:arr)mp[i]++;
	for(auto &i:mp){
		if(i.sc>=2){
			cout<<"YES\n";
			return;
		}
	}
	mp.clear();
	for(int i = 0;i<n;i++)mp[arr[i]] = i,arr[i] = i;
	for(int i = 0;i<n;i++)brr[i] = mp[brr[i]];
	if((n&1)&&brr[n/2] != arr[n/2]){
		cout<<"NO\n";
		return;
	}
	ll c = 0;
	for(int i = 0;i<n;i++)c += i-brr[i];
	if(!c)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
