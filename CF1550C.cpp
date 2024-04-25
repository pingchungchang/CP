#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double


ll m;
vector<ll> bit;

void modify(ll p,ll v){
	for(;p<=m;p+=p&-p)bit[p] += v;
	return;
}
ll getval(ll s,ll e){
	ll re = 0LL;
	for(;e>0;e -= e&-e)re += bit[e];
	s--;
	for(;s>0;s -= s&-s)re -= bit[s];
	return re;
}
void solve(){
	ll n;
	cin>>n;
	vector<ll> v(n+1,INT_MIN);
	for(int i = 1;i<=n;i++)cin>>v[i];
	ll ans = 0;
	for(ll i = 1;i<=n;i++){
		for(int l = min(i,7LL);l>0;l--){
			bool flag = true;
			for(ll a = i-l+1;a<=i;a++){
				if(!flag)break;
				for(ll b = a+1;b<=i;b++){
					if(!flag)break;
					for(ll c = b+1;c<=i;c++){
						if(!flag)break;
						if((v[b]-v[a])*(v[c]-v[b])>=0)flag = false;
					}
				}
			}
			if(flag){
//				cout<<i<<' '<<l<<'\n';
				ans += l;
				break;
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

