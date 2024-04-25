#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	ll n,m;
	cin>>m>>n;
	cout<<n*(n+1)/2+(n+m*n)*m/2-n<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

