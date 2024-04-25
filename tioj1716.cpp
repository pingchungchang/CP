#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
void solve(){
	ll a,b,c;
	cin>>a>>b>>c;
	ll det = b*b-4*a*c;
	if(det == 0){
		cout<<"Yes\n";
		return;
	}
	else if(det<0){
		cout<<"No\n";
		return;
	}
	ll tmp = sqrt(det);
	if(tmp*tmp == det)cout<<"Yes\n";
	else cout<<"No\n";
	return;
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

