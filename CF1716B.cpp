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
	ll n;
	cin>>n;
	vector<ll> v(n,0);
	for(int i = 0;i<n;i++)v[i] = i+1;
	cout<<n<<'\n';
	for(auto &j:v)cout<<j<<' ';cout<<'\n';
	for(int i = 0;i<n-1;i++){
		swap(v[i],v[i+1]);
		for(auto &j:v)cout<<j<<' ';cout<<'\n';
	}
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

