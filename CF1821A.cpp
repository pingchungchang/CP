#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	int  c1 = 1,c2 = 1;
	for(int i = 1;i<s.size();i++)if(s[i] == '?')c2*=10;
	if(s[0] == '0'){
		cout<<"0\n";
		return;
	}
	if(s[0] == '?')c1 = 9;
	cout<<c1*c2<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
