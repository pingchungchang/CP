#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double


ll ask(ll s,ll e){
	cout<<"?"<<' '<<s<<' '<<e<<endl;
	ll re;
	cin>>re;
	return re;
}
void answer(ll i,ll j,ll k){
	cout<<"! "<<i<<' '<<j<<' '<<k<<endl;
	return;
}
void solve(){
	ll n;
	cin>>n;
	ll p1 = 1LL,p2 = n;
	ll total = ask(1,n);
	ll l = 1,r = n;
	while(l != r){
		ll mid = (l+r+1)/2;
		if(ask(l,mid) != 0)r = mid-1;
		else l = mid;
	}
	while(p1<p2){
		cout<<p1<<','<<p2<<endl;
		ll x = total*2-p1*(p1-1);
		ll sq = sqrt(1+x*4);
		p2 = (1+sq)/2;
		if(p2*(p2-1)+p1*(p1-1) == total*2){
			ll tmp = ask(l,p1+l);
			if(tmp == p1*(p1-1)){
				answer(l,p1+l,p1+p2+l-1);
				return;
			}
			else{
				answer(l,p2+l,p1+p2+l-1);
				return;
			}
		}
		p1++;
	}
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

