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
	char small = s[0];
	for(auto &i:s){
		small = min(small,i);
	}
	for(int i = 0;i<s.size();i++){
		if(small == s[i]){
			cout<<small<<' ';cout<<s.substr(0,i)<<(i != s.size()-1?s.substr(i+1,s.size()-i):"")<<'\n';
			return;
		}
	}
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

