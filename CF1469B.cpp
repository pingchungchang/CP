#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n;ll arr[n];
	for(auto &i:arr)cin>>i;
	cin>>m;ll brr[m];
	for(auto &i:brr)cin>>i;
	for(int i = 1;i<n;i++)arr[i] += arr[i-1];
	for(int i = 1;i<m;i++)brr[i] += brr[i-1];
	ll ma = 0,mb = 0;
	for(auto &i:arr)ma = max(ma,i);
	for(auto &i:brr)mb = max(mb,i);
	cout<<ma+mb<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
