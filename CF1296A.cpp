#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int sum = 0;
	int od = 0,ev = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		sum += k;
		if(k&1)od++;
		else ev++;
	}
	if(od&&ev)cout<<"YES\n";
	else if(sum%2 == 1)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
