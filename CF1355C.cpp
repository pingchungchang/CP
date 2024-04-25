#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e6+10;
ll pref[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll ans = 0;
	for(ll x = a;x<=b;x++){
		pref[x+b]++;pref[x+c+1]--;
	}
	for(ll i = 1;i<mxn;i++)pref[i] += pref[i-1];
	for(ll i = 1;i<mxn;i++)pref[i] += pref[i-1];
	for(ll z = c;z<=d;z++){
		ans += pref[mxn-1]-pref[z];
	}
	cout<<ans;
}
