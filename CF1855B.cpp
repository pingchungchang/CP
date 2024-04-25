#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n;
	cin>>n;
	ll sum = 1;
	for(ll i = 1;i<=1e6;i++){
		sum *= i;
		if(n%i != 0){
			cout<<i-1<<'\n';
			return;
		}
	}
	assert(false);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
