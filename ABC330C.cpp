#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


ll tar;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>tar;
	ll b = 2e6;
	ll a;
	ll ans = 1e18;
	for(a = 0;a<2e6;a++){
		while(a*a+b*b>=tar&&b>=0){
			ans = min(ans,abs(a*a+b*b-tar));
			b--;
		}
		ans = min(ans,abs(a*a+b*b-tar));
		b+=5;
	}
	ans = min(ans,abs(a*a-tar));
	cout<<ans;
}
