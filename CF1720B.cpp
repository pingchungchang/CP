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
void solve(){
	int n;
	cin>>n;
	vector<ll> v(n);
	for(auto &i:v)cin>>i;
	sort(_all(v));
	cout<<(v[n-1]+v[n-2]-v[0]-v[1])<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

