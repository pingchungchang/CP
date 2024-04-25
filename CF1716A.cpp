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
	ll n;
	cin>>n;
	ll ans = INT_MAX;
	ll tmp = n/3*3;
	if(n-tmp == 2)ans = n/3+1;
	else if(n== tmp)ans = n/3;
	else if(n != 1){
		ans = n/3+1;
	}
	if(n%2 == 0){
		ans = min(ans,n/2);
	}
	else{
		ans = min(ans,n/2+2);
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

