#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

void solve(){
	int n,x;
	cin>>n>>x;
	int arr[n];
	ll total = 0;
	for(auto &i:arr){
		cin>>i;
		total += i;
	}
	ll ans = 0;
	for(auto &i:arr)ans += (i+x-1)/x;
	cout<<(total+x-1)/x<<' '<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

