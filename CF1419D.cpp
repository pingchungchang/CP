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
	for(auto &i:arr)cin>>i;
	int ans[n];
	sort(arr,arr+n);
	int pt = n-1;
	for(int i = 0;i<n;i+=2){
		ans[i] = arr[pt--];
	}
	if(n%2 == 0){
		ans[n-1] = arr[pt--];
	}
	for(int i = 1;i<n-1;i+=2){
		ans[i] = arr[pt--];
	}
	int cnt = 0;
	for(int i = 1;i<n-1;i++){
		if(ans[i]<min(ans[i+1],ans[i-1]))cnt++;
	}
	cout<<cnt<<'\n';
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
}
