#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int n;
void solve(){
	ll G;
	cin>>G;
	for(int i = 1;i<n;i++){
		ll k;
		cin>>k;
		G = __gcd(G,k);
	}
	cout<<G<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
