#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,k;
	cin>>n>>k;
	if(n%2 == 0){
		cout<<n+k*2<<'\n';
	}
	else{
		k--;
		for(int i = 2;i<=n;i++){
			if(n%i == 0){
				n += i;
				break;
			}
		}
		cout<<n+k*2<<'\n';
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
