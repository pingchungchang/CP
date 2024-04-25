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
	reverse(_all(s));
	int p[s.size()];
	p[0] = p[1] = 0;
	if(s.size()>1&&s[0] == s[1])p[1] = 1;
	for(int i = 2;i<s.size();i++){
		int pt = p[i-1];
		while(pt>(i+1)/2&&pt>=0&&s[pt] != s[i])pt = p[pt]-1;
		if(pt<=0&&s[0] == s[i])p[i] = 1;
		else if(pt>=0&&s[pt] == s[i])p[i] = pt+1;
		else p[i] = 0;
	}
	cout<<s<<endl;
	for(auto &i:p)cout<<i<<' ';
	int ans = 0;
	for(int i = 0;i<s.size();i++){
		if(i%2 == 1&&p[i] == (i+1)/2)ans = max(i/2+1,ans);
	}
	cout<<ans<<'\n';
	
}
int main(){
//	io
	while(cin>>s){
		solve();
	}
}
/*
ababab

*/
