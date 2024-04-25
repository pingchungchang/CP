#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll h,a;
	cin>>h>>a;
	ll ans = 0;
	ll C = 1;
	while(h){
		ans += C;
		C<<=1;
		h/=a;
	}
	cout<<ans;
}
