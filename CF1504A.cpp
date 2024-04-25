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
	string ss = "a"+s;
	s += 'a';
	for(int i = 0;i<s.size()/2;i++){
		if(s[i] != s[s.size()-1-i]){
			cout<<"YES\n"<<s<<'\n';
			return;
		}
	}
	for(int i = 0;i<ss.size()/2;i++){
		if(ss[i] != ss[ss.size()-1-i]){
			cout<<"YES\n"<<ss<<'\n';
			return;
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

