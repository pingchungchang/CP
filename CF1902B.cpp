#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll n,p,a,b;
	cin>>n>>p>>a>>b;
	ll l = 0,r = n;
	ll c = (n+6)/7;
	while(l != r){
		ll mid = (l+r)>>1;
		ll re = mid*a;
		re += min(c,mid*2)*b;
		if(re>=p)r = mid;
		else l = mid+1;
	}
	cout<<n-l<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
