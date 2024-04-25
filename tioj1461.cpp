#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int n,m;
string s;
string in;

void solve(){
	stringstream ss(in);
	ss>>n>>m;
	if(!n&&!m)exit(0);
	s.clear();
	for(int i = 0;i<n;i++){
		getline(cin,in);
		s += in;
	}
	s = "#"+s;
	getline(cin,in);
	ss = stringstream(in);
	while(ss>>n)cout<<s[n];
	cout<<'\n';
	return;
}

int main(){
	while(getline(cin,in))solve();
}
