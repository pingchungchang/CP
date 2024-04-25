#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string a,b;
	cin>>a>>b;
	if(a[0] != b[0]||a.back() != b.back()){
		cout<<"NO\n";
		return;
	}
	if(a[0] == a.back()){
		cout<<"YEs\n";
		return;
	}
	if(a[0] == '1'){
		for(auto &i:a)i = (i == '0'?'1':'0');
		for(auto &i:b)i = (i == '0'?'1':'0');
	}
	for(int i = 1;i<a.size();i++){
		if(a[i] == '1'&&b[i] == '1'&&a[i-1] == '0'&&b[i-1] == '0'){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
