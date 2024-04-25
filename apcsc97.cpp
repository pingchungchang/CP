#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<ll> dsu;
int root(ll a){
	while(dsu[a] != a){
		dsu[a] = dsu[dsu[a]];
		a = dsu[a];
	}
	return a;
}
int main(){
	io
	ll n,m;
	cin>>n>>m;
	dsu = vector<ll> (n+1,0);
	vector<ll> sz(n+1,1);
	ll ans = 0;
	for(ll i = 1;i<=n;i++)dsu[i] = i;
	while(m--){
		ll t;
		cin>>t;
		if(t == 1){
			ll a,b;
			cin>>a>>b;
			ll ra = root(a),rb = root(b);
			if(sz[ra]>sz[rb]){
				dsu[rb] = ra;
				if(ra != rb){
					ans -= sz[ra]*(sz[ra]-1)/2+(sz[rb]-1)*sz[rb]/2;
					sz[ra] += sz[rb];	
					ans += sz[ra]*(sz[ra]-1)/2;
				}
			}
			else{
				dsu[ra] = rb;
				if(ra != rb){
					ans -= sz[ra]*(sz[ra]-1)/2+(sz[rb]-1)*sz[rb]/2;
					sz[rb] += sz[ra];	
					ans += sz[rb]*(sz[rb]-1)/2;
				}
			}
		}
		else if(t == 2){
			ll a,b;
			cin>>a>>b;
			if(root(a) == root(b))cout<<"Yes\n";
			else cout<<"No\n";
		}
		else if(t == 3){
			ll x;
			cin>>x;
			cout<<sz[root(x)]<<'\n';
		}
		else{
			cout<<ans<<'\n';
		}
	}
	return 0;
}

