#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	n--;
	ll ans = 0;
	while(n--){
		int k;
		cin>>k;
		ans ^= k;
	}
	cout<<ans;
}
