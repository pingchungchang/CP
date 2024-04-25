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
	int arr[n];
	for(int i = 0;i<n;i++)arr[i] = i+1;
	for(int i = 1;i<n;i+=2)swap(arr[i],arr[i-1]);
	if(n&1)swap(arr[n-1],arr[n-2]);
	for(auto &i:arr)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
