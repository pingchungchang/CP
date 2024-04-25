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
	if(s == "2020"){
		cout<<"YES\n";
		return;
	}
	else if(s.size()<4){
		cout<<"NO\n";
		return;
	}
	for(int i = 0;i<=4;i++){
		if(s.substr(0,4-i)+s.substr(n-i,i) == "2020"){
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

