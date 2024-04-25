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
	int arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	if(n == k){
		cout<<(int)1e9<<'\n';
		return;
	}
	else if(k == 0){
		if(arr[0] == 1)cout<<"-1\n";
		else cout<<"1\n";
		return;
	}
	if(arr[k] != arr[k-1])cout<<arr[k-1]<<'\n';
	else cout<<"-1\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
