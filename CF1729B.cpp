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
	int n;
	cin>>n;
	string s;
	cin>>s;
	string ans;
	int p = n-1;
	while(p>=0){
		if(s[p] == '0'){
			ans += (char)('a'-1+stoi(s.substr(p-2,2)));
			p -= 2;
		}
		else ans += 'a'+s[p]-'1';
		p--;
	}
	reverse(_all(ans));
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

