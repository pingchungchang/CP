#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	int arr[n];
	int sum = 0;
	for(auto &i:arr)cin>>i,sum += i;
	if(sum == m){
		cout<<"NO\n";
		return;
	}
	sort(arr,arr+n);
	sum = 0;
	for(int i = 0;i<n;i++){
		sum += arr[i];
		if(sum == m){
			swap(arr[i],arr[n-1]);
		}
	}
	cout<<"YES\n";
	for(auto &i:arr)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
