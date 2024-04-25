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
	int l = -1,r = n+1;
	for(int i = 0;i<n;i++){
		if(i<=arr[i])l = i;
		else break;
	}
	for(int i = n-1;i>=0;i--)if(n-1-i<=arr[i])r = i;else break;
	if(r<=l)cout<<"Yes\n";
	else cout<<"No\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
