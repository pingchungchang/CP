#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void solve(){
	ll n;
	cin>>n;
	if(n%3 == 0){
		cout<<n/3<<' '<<n/3+1<<' '<<n/3-1<<'\n';
	}
	else if(n%3 == 1){
		cout<<n/3<<' '<<n/3+2<<' '<<n/3-1<<'\n';
	}
	else if(n%3 == 2){
		cout<<n/3+1<<' '<<n/3+2<<' '<<n/3-1<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

