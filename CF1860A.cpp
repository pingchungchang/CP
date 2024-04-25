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
	int n = s.size();
	if(s == "()"){
		cout<<"NO\n";
		return;
	}
	for(int i = 1;i<n;i++){
		if(s[i-1] == ')'&&s[i] == '('){
			cout<<"YES\n";
			for(int i = 0;i<n;i++)cout<<"(";
			for(int i = 0;i<n;i++)cout<<")";cout<<'\n';
			return;
		}
	}
	cout<<"YES\n";
	for(int i = 0;i<n;i++)cout<<"()";cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
