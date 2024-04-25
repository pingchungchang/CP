#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	int arr[n*k];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n*k);
	ll total = 0;
	int pt = 0;
	vector<int> v[k];
	while(v[0].size()<(n-1)/2){
		for(int i = 0;i<k;i++){
			v[i].push_back(arr[pt++]);
		}
	}

	for(int i = 0;i<k;i++){
		while(v[i].size()<n)v[i].push_back(arr[pt++]);
		sort(v[i].begin(),v[i].end());
	}
	/*
	for(auto &i:v){
		for(auto &j:i)cout<<j<<' ';cout<<'\n';
	}
   */
	for(auto &i:v)total += i[(n-1)/2];
	cout<<total<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
