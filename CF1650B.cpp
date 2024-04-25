#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void solve(){
	ll l,r,a;
	cin>>l>>r>>a;
	if(l/a != r/a){
		cout<<max(r/a+r%a,(r/a)-1+a-1)<<'\n';
	}
	else{
		cout<<r/a+r%a<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

