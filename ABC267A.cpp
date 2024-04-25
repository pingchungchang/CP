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
int main(){
	io
	string s;
	cin>>s;
	if(s[0] == 'M')cout<<5;
	else if(s.substr(0,2) == "Tu")cout<<4;
	else if(s.substr(0,2) == "We")cout<<3;
	else if(s[0] == 'T')cout<<2;
	else cout<<1;
	
}

