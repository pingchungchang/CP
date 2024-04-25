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
	int total = 0;
	for(auto &i:arr)cin>>i,total += i;
	if(total == 0){
		cout<<"NO\n";
		return;
	}
	sort(arr,arr+n);
	if(total>0)reverse(arr,arr+n);
	cout<<"YES\n";
	for(auto &i:arr)cout<<i<<' ';
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
