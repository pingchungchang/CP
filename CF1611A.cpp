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
	bool odd = true;
	for(auto &i:s)if((i-'0')%2 == 0)odd = false;
	if(odd){
		cout<<-1<<'\n';
		return;
	}
	if((s.back()-'0')&1){
		if((s[0]-'0')&1)cout<<"2\n";
		else cout<<"1\n";
	}
	else cout<<"0\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

