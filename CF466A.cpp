#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	ll n,m,a,b;
	cin>>n>>m>>a>>b;
	ll ans = a*n;
	ans = min(ans,(n/m)*b+(n%m)*a);
	ans = min(ans,((n+m-1)/m)*b);
	cout<<ans;
}

