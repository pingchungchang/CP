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
	int a,b;
	cin>>a>>b;
	int ca = a,cb = b;
	string s;
	cin>>s;
	int n = a+b;
	for(int i = 0;i<n/2;i++){
		if(s[i] == '?'&&s[n-1-i] != '?')s[i] = s[n-1-i];
		else if(s[i] != '?'&&s[n-1-i] == '?')s[n-1-i] = s[i];
		else if(s[i] != s[n-1-i]){
			cout<<"-1\n";
			return;
		}
	}
	for(auto i:s){
		if(i == '0')a--;
		else if(i == '1')b--;
	}
	if(n%2 == 1&&s[n/2] == '?'){
		if(a%2 == 1){
			s[n/2] = '0';
			a--;
		}
		else{
			s[n/2] = '1';
			b--;
		}
	}
	for(int i = 0;i<n/2;i++){
		if(s[i] == '?'&&a >0){
			a -= 2;
			s[i] = s[n-1-i] = '0';
		}
		else if(s[i] == '?'){
			b -= 2;
			s[i] = s[n-1-i] = '1';
		}
	}
	for(auto i:s){
		if(i == '0')ca--;
		else cb --;
	}
//	cout<<ca<<' '<<cb<<' '<<s<<' ';
	if(ca == 0&&cb == 0)cout<<s<<'\n';
	else cout<<"-1\n";
	return;
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

