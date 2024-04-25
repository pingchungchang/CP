#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	string s;
	cin>>s;
	int a = 0,b = 0;
	for(int i = 0;i<6;i++){
		if(i<3)a += s[i];
		else b += s[i];
	}
	if(a == b)cout<<"YES\n";
	else cout<<"NO\n";
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

