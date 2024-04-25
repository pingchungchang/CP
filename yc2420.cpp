#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define ld long double



const ld sq = sqrt(1e9+10)*2;
const ld eps = 1e-8;

void solve(){
	ll a,b;
	cin>>a>>b;
	ll l = 0,r = sq+1;
	while(l != r){
		ll mid = (l+r)>>1;
		ll C = mid*mid-a-b;
		if(C<0)l = mid+1;
		else if(C*C>a*b*4)r = mid;
		else l = mid+1;
	}
	cout<<l<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
