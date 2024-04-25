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
	for(int i = 0;i<s.size();i++){
		if(i&1){
			if(s[i] != 'z')s[i] = 'z';
			else s[i] = 'y';
		}
		else{
			if(s[i] != 'a')s[i] = 'a';
			else s[i] = 'b';
		}
	}
	cout<<s<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

