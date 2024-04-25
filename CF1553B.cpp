#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

string s;
string t;

bool check(int s1,int t1,int d){
	bool returns = false;
	s1 += d;
	for(;s1<s.size()&&s1>=0;s1 += d){
//		cout<<s1<<' '<<t1<<' '<<d<<' '<<t.size()<<'\n';
		if(t1 == t.size())returns = true;
		if(s[s1] != t[t1])return returns;
		t1++;
		returns = returns||(d == -1?false:check(s1,t1,-1));
	}
	if(t1 == t.size())return true;
	return returns;
}
void solve(){
	cin>>s>>t;
	for(int i = 0;i<s.size();i++){
		if(check(i-1,0,1)){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

