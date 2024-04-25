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
	ll ans =0;
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	ll p = 0;
	for(int i = 0;i<n;i++){
		if(p<=i){
			p = i;
		}
		while(p < n&&arr[p]>=p-i+1){
			p++;
		}
		p--;
		ans += p-i+1;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

