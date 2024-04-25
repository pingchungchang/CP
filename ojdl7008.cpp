#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll mxn = 1e6+10;
ll bit[2][mxn];
ll n,q;
void modify(ll r,ll c,ll v){
	for(;c<=n;c+= c&-c){
		bit[r][c] += v;
	}
	return;
}

ll getval(ll c){
	ll ans = 0;
	ll e= c;
	for(;c>0;c -= c&-c){
		ans += (e+1)*bit[0][c];
		ans -= bit[1][c];
	}
	return ans;
}
int main(){
	io
	cin>>n>>q;
	ll vals[n+1];
	ll d[n+1];
	fill(vals,vals+n+1,0LL);
	fill(d,d+n+1,0LL);
	for(ll i = 1;i<=n;i++){
		cin>>vals[i];
		d[i] = vals[i]-vals[i-1];
	}
	for(ll i = 1;i<=n;i++){
		modify(0,i,d[i]);
		modify(1,i,i*d[i]);
	}
	while(q--){
		char c;
		cin>>c;
		if(c == 'q'){
			ll s,e;
			cin>>s>>e;
			cout<<getval(e)-getval(s-1)<<'\n';
		}
		else{
			ll a,b,v;
			cin>>a>>b>>v;
			modify(0,a,v);
			modify(0,b+1,-v);
			modify(1,a,a*v);
			modify(1,b+1,-(b+1)*v);
		}
	}
}


//pref[i] = sigma(d[i]*(x-i+1)) = sigma(d[i]*x-d[i]*i+d[i])
