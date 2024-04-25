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
	int n,k1,k2;
	cin>>n>>k1>>k2;
	int ta,tb;
	cin>>ta>>tb;
	int w = min(k1,k2)+abs(k2-k1)/2;
	int b = min(n-k1,n-k2)+abs(k2-k1)/2;
	if(w>=ta&&b>=tb)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

