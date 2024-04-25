#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int k;
	cin>>k;
	if(k == 100){
		cout<<1<<'\n';
		return;
	}
	int G = __gcd(k,100-k);
	cout<<k/G+(100-k)/G<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
