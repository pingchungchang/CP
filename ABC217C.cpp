#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n;
	cin>>n;
	int arr[n];
	int v[n];
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<n;i++){
		v[arr[i]-1] = i+1;
	}
	for(auto i:v)cout<<i<<' ';
}

