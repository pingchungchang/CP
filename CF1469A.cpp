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
	if(s.size()&1){
		cout<<"NO\n";
		return;
	}
	int cnt = 0;
	for(auto &i:s){
		if(i == '(')cnt++;
	}
	if(cnt>s.size()/2){
		cout<<"NO\n";
		return;
	}
	int c = s.size()/2-cnt;
	for(auto &i:s){
		if(c>0&&i == '?')i = '(',c--;
		else if(i == '?')i = ')';
	}
	c = 0;
	for(auto &i:s){
		if(i == '(')c++;
		else c--;
		if(c<0){
			cout<<"NO\n";
			return;
		}
	}
	if(!c)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
