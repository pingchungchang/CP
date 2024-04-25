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
	if(k == 0){
		cout<<"YES\n";
		return;
	}
	for(int i = 0;i<k;i++){
		if(s[i] != s[s.size()-1-i]||s.size()<k*2+1){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}


int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

