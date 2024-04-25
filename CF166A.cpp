#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>


void solve(){
	int n,k;
	cin>>n>>k;
	pii arr[n];
	for(auto &i:arr){
		cin>>i.fs>>i.sc;
		i.sc = -i.sc;
	}
	sort(arr,arr+n);
	reverse(arr,arr+n);
	auto tar = arr[k-1];
	int ans = 0;
	for(auto &i:arr){
		if(i.fs == tar.fs&&i.sc == tar.sc)ans++;
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
