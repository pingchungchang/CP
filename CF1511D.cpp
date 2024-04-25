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
	int n,m;
	cin>>n>>m;
	string s;
	for(char i = 'a';i<'a'+m;i++){
		s += i;
		for(int j = i+1;j<'a'+m;j++){
			s += i;
			s += j;
		}
	}
	while(s.size()<n)s += s;
	cout<<s.substr(0,n);
}
int main(){
	io
	int t = 1;
	while(t--)solve();
}

