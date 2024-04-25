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
	cout<<arr[0]<<' ';
	for(int i = 1;i<n;i++){
		if(arr[i]>arr[i-1])while(arr[i-1] != arr[i])cout<<++arr[i-1]<<' ';
		else while(arr[i-1] != arr[i])cout<<--arr[i-1]<<' ';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t =1;
	while(t--)solve();
}
