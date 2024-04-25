#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll n;
	cin>>n;
	bool flag = false;
	if(n%2 == 0){
		ll tt = sqrt(n/2);
		if(tt*tt == n/2)flag = true;
	}
	if(n%4 == 0){
		ll tt = sqrt(n/4);
		if(tt*tt == n/4)flag = true;
	}
	cout<<(flag?"Yes\n":"NO\n");
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
