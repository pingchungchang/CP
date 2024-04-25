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
	string s;
	cin>>s;
	int n = s.size();
	int oo = n,zz = 0;
	for(int i = 0;i<n-1;i++){
		if(s[i] == s[i+1]){
			if(s[i] == '1')oo = min(oo,i);
			else zz = max(zz,i);
		}
	}
	if(zz>oo)cout<<"NO\n";
	else cout<<"YES\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

