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
	for(int i = 0;i<n;i++)arr[i] = i+1,total += arr[i];
	while(total %n != 0)arr[0]++,total++;
	for(auto &i:arr)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
