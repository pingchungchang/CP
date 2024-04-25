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
string s;
void solve(){
	string ans[4];
	s += s;
	for(int i = 0;i<4;i++){
		if(s[i] == 'b'){
			ans[i] = "X";
			continue;
		}
		if(s[i+4-1] != 'a')ans[i] += 'A';
		if(s[i+1] != 'a')ans[i] += 'B';
		if(s[i+2] != 'a')ans[i] += 'C';
		if(ans[i].empty())ans[i] = "Y";
	}
	for(int i = 0;i<4;i++){
		cout<<ans[i];
		if(i == 3)cout<<'\n';
		else cout<<", ";
	}
}
int main(){
	io
	while(cin>>s)solve();
}

