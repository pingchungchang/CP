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
void solve(){
	ll n,m,k,q;
	cin>>n>>m>>k>>q;
	vector<pll> v(q);
	set<ll> r,c;
	ll rsum = 0,csum = 0;
	for(int i= 0;i<q;i++){
		cin>>v[i].fs>>v[i].sc;
		r.insert(v[i].fs);
		c.insert(v[i].sc);
	}
	ll ans = 1;
	for(int i = q-1;i>=0;i--){
//		cout<<rsum<<' '<<csum<<endl;
		if(r.find(v[i].fs) != r.end()||c.find(v[i].sc) != c.end()){
			if(rsum != n&&csum != m)ans = ans*k%mod;
		}
		if(r.find(v[i].fs) != r.end())rsum++;
		if(c.find(v[i].sc) != c.end())csum++;
		r.erase(v[i].fs);c.erase(v[i].sc);
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

