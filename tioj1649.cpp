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
int main(){
	io
	ll n,h;
	cin>>n>>h;
	ll now = h;
	ll ans = 0;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		if(k>=h){
			cout<<-1;
			return 0;
		}
		if(k>=now){
			ans++;
			now = h-k;
		}
		else now -= k;
	}
	cout<<ans;
}

