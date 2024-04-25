#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define ld long double


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	ld ans = 0;
	while(n){
		ans += 1.0/n;
		n--;
	}
	cout<<fixed<<setprecision(10)<<ans;
}
