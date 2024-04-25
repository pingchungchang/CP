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
	int od = 0,ev = 0;
	for(int i = 0;i<n*2;i++){
		int k;
		cin>>k;
		if(k&1)od++;
		else ev++;
	}
	if(od != ev)cout<<"No\n";
	else cout<<"Yes\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
