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
	for(int i = 0;i<n;i++)cin>>arr[i];
	while(k--){
		int p = 0;
		for(;p<n&&!arr[p];p++);
		if(p<n){
			arr[p]--,arr[n-1]++;
		}
	}
	for(auto &i:arr)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
