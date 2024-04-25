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
const ll mxn = 3005;
ll arr[mxn];
ll n;
ll f(ll tar,ll s){
	ll tmp = 0;
	ll cnt = 1;
	for(;s<n;s++){
		tmp += arr[s];
		if(tmp == tar){
			tmp = 0;
			cnt++;
		}
		else if(tmp>tar)return 0;
	}
	if(tmp == tar){
		cnt++;
		tmp = 0;
	}
	if(tmp == 0)return cnt;
	else return 0;
}
void solve(){
	cin>>n;
	for(int i = 0;i<n;i++)cin>>arr[i];
	ll total = arr[0];
	ll ans = n-1;
	for(int i = 1;i<n;i++){
		ans = min(ans,n-f(total,i));
		total += arr[i];
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

