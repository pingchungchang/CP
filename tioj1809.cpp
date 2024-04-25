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
const ll mxn = 1e8;
int main(){
	io
	ll n,m,q;
	cin>>n>>m>>q;
	set<ll> st;
	while(m--){
		ll a,b;
		cin>>a>>b;
		if(a>b)swap(a,b);
		st.insert(a*mxn+b);
	}
	while(q--){
		ll a,b;
		cin>>a>>b;
		if(a>b)swap(a,b);
		if(st.find(a*mxn+b) != st.end())cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}

