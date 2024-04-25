#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	int n;
	cin>>n;
	int arr[n];
	int sum = 0;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		sum ^= arr[i];
	}
	for(int i = 0;i<n;i++){
		if(sum^arr[i] == arr[i]){
			cout<<arr[i]<<'\n';
			return;
		}
	}
	cout<<"ERROR\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

