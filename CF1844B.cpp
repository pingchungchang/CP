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
	int arr[n] = {};
	arr[0] = 2;
	arr[n-1] = 3;
	arr[n/2] = 1;
	int c = 4;
	for(int i = 0;i<n;i++)if(!arr[i])arr[i] = c++;
	for(auto &i:arr)cout<<i<<' ';
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
