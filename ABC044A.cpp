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
int main(){
	io
	ll n,k,x,y;
	cin>>n>>k>>x>>y;
	if(n<=k){
		cout<<x*n;
	}
	else cout<<x*k+y*(n-k);	
}

