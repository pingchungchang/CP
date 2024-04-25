#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

ll calc(ll k){
	if(k<=4)return k;
	ll sq = sqrt(k);
	while(sq*sq>k)sq--;
	while((sq+1)*(sq+1) <= k)sq++;
	sq--;
	ll re = sq*3;
//	cout<<re<<",";
	sq++;
	re += k/sq-sq+1;
	return re;
}
void solve(){
	ll l,r;
	cin>>l>>r;
	l--;
	cout<<calc(r)-calc(l)<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

//sum(i+2-i+1) = n*(n+1)/2-2*n
