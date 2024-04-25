#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll a,b;
	cin>>a>>b;
	if(a == b)cout<<"0 0\n";
	else{
		if(a<b)swap(a,b);
		ll d = a-b;
		cout<<d<<' ';
		cout<<min(a-a/d*d,(a+d-1)/d*d-a)<<'\n';
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
