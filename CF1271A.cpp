#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	a = min(a,d);
	b = min({b,c,d});
	ll ans = 0;
	for(int i = 0;i<=a;i++){
		ll tans = i*e+max(0,min(b,d-i))*f;
		ans = max(ans,tans);
	}
	cout<<ans;
}
