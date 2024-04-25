#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	ll n,q;
	cin>>n>>q;
	vector<ll> arr(n);
	for(int i = 0;i<n;i++)cin>>arr[i];
	sort(arr.rbegin(),arr.rend());
	for(int i = 1;i<n;i++){
		arr[i] += arr[i-1];
	}
	while(q--){
		ll k;
		cin>>k;
		ll pos = lower_bound(arr.begin(),arr.end(),k)-arr.begin();
		if(pos == n)cout<<-1<<'\n';
		else cout<<pos+1<<"\n";
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

