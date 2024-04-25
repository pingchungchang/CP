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
	ll n;
	cin>>n;
	if(n == 1){
		cout<<"NO\n";
		return;
	}
	ll sq = sqrt(n);
	ll ssq = sqrt(sq);
	if(sq*sq == n){
		for(ll i = 2;i<= ssq;i++){
			if(sq%i == 0){
				cout<<"NO\n";
				return;
			}
		}
		cout<<"YES\n";
		return;
	}
	cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

