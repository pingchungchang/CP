#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll m,d,w;
	cin>>m>>d>>w;
	if(d>1)w /=__gcd(w,d-1);
	ll ans = 0;
	ll mk = min(m-1,d-1)/w;
	ans += (min(m,d)*(mk)-mk*w*(mk+1)/2);
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}

/*
((a-1)*d+b)%w = ((b-1)*d+a)%w
1<=a<b<=m
if a == b->true
let a<b
(d-1)*(b-a)%w = 0
(b-a)%(w/gcd(w,d-1)) = 0
let w/gcd(w,d-1) = c
(b-a) = k*c
2*sum(min(m,d)-k*c) for 1<=k<=n using triangle let mk = max(k)
2*(min(m,d)*(mk))-c*mk*(mk+1)/2))
*/
