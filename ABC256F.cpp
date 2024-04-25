#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const ll mod = 998244353;
const ll mxn = 2e5+10;
vector<vector<ll>> bit(3,vector<ll>(mxn,0LL));
ll n;
void modify(ll r,ll c,ll v){
//	cout<<r<<' '<<c<<' '<<v<<endl;
	for(;c<=n;c += c&-c){
		bit[r][c] += v;
		if(r < 2)modify(r+1,c,v);
	}
	return;
}

ll getval(ll p){
	ll ans = 0;
	for(;p>0; p-= p&-p)ans += bit[2][p];
	return ans;
}
int main(){
	ll q;
	cin>>n>>q;
	vector<ll> v(n+1,0LL);
	for(ll i = 1;i<=n;i++){
		cin>>v[i];
//		cout<<v[i]<<endl;
		modify(0,i,v[i]);
	}
	while(q--){
		ll t;
		cin>>t;
		if(t == 1){
			ll p,k;
			cin>>p>>k;
			modify(0,p,k-v[p]);
			v[p] = k;
		}
		else{
			ll x;
			cin>>x;
			cout<<getval(x)<<"\n";
		}
	}
}

