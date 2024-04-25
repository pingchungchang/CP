#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int p;
	cin>>p;
	if(p&1){
		cout<<2<<' '<<p-1<<'\n';
	}
	else{
		cout<<2<<' '<<p<<'\n';
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
