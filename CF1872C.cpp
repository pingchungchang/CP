#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int l,r;
	cin>>l>>r;
	if(l == 1&&r == 1){
		cout<<"-1\n";
		return;
	}
	if(r<=3){
		cout<<"-1\n";
		return;
	}
	l = max(l,4);
	if(l != r){
		l = r-1;
		if(l&1)cout<<2<<' '<<r-2<<'\n';
		else cout<<2<<' '<<l-2<<'\n';
		return;
	}
	for(int i = 2;i*i<=l;i++){
		if(l%i == 0){
			cout<<i<<' '<<l-i<<'\n';
			return;
		}
	}
	cout<<"-1\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
