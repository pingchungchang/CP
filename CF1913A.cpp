#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	string s;
	cin>>s;
	int p = 1;
	while(p<s.size()&&s[p] == '0')p++;
	if(p == s.size()){
		cout<<"-1\n";
		return;
	}
	int a = stoi(s.substr(0,p));
	int b = stoi(s.substr(p,s.size()-p));
	if(a>=b){
		cout<<"-1\n";
	}
	else cout<<a<<' '<<b<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
