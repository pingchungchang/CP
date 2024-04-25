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
	ll n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	string rs = s;
	reverse(_all(rs));
	if(s == rs||k == 0)cout<<"1\n";
	else cout<<"2\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

