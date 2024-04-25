#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	ll n,m,k;
	cin>>n>>m>>k;
	ll total = n*m/2;
	if(n%2 != 0){
		swap(n,m);
		k = total-k;
	}
	if((k%2))cout<<"NO\n";
	else if((m/2*2)*n/2>=k)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

