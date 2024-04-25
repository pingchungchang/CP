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
	pll arr[n];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	int head = -1;
	if(arr[n-1].sc<arr[0].fs)head = 0;
	for(int i = 1;i<n;i++){
		if(arr[i-1].sc<arr[i].fs)head = i;
	}
	if(head == -1){
		cout<<min_element(arr,arr+n)->fs<<'\n';
		return;
	}
	vector<pll> v;
	for(int i = head;i<n;i++)v.push_back(arr[i]);
	for(int i = 0;i<head;i++)v.push_back(arr[i]);
	ll sum = v[0].fs-v.back().sc;
	for(int i = 1;i<n;i++){
		if(v[i-1].sc<v[i].fs)sum += v[i].fs-v[i-1].sc;
	}
	ll ans = sum+v.back().sc;
	for(int i = 1;i<n;i++){
		if(v[i-1].sc<v[i].fs)ans = min(ans,sum+v[i-1].sc);
		else ans = min(ans,sum+v[i].fs);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
