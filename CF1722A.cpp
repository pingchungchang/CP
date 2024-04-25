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
string tar = "Timur";
void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	sort(_all(s));
	if(s == tar)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	io
	sort(_all(tar));
	int t;
	cin>>t;
	while(t--)solve();
}

