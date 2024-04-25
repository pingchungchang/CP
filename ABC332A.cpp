#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	ll lim,p;
	cin>>lim>>p;
	ll ans = 0;
	while(n--){
		ll a,b;
		cin>>a>>b;
		ans += a*b;
	}
	cout<<ans+(ans<lim?p:0);
}
