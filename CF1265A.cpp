#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	for(int i = 1;i<s.size();i++){
		if(s[i] == '?')continue;
		if(s[i] == s[i-1]){
			cout<<"-1\n";
			return;
		}
	}
	for(int i = 0;i<s.size();i++){
		if(s[i] == '?'){
			for(char c = 'a';c<='c';c++){
				if(i&&s[i-1] == c)continue;
				if(i+1 != s.size()&&s[i+1] == c)continue;
				s[i] = c;
				break;
			}
		}
	}
	for(auto &i:s)assert(i != '?');
	cout<<s<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
