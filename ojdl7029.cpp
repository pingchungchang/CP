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
const int mxn = 1e7+10;
ll a[mxn],b[mxn-1];
int main(){
	io
	int n;
	cin>>n;
	for(int i = 0;i<n-1;i++)cin>>a[i];
	for(int i= 0;i<n;i++)cin>>b[i];
	ll ans = 0;
	for(int i = 0;i<n-1;i++){
		ans = max(ans,a[i]^b[i]^b[i+1]);
	}
	cout<<ans;
}

