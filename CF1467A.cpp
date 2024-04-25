#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void solve(){
	int n;
	cin>>n;
	string s = "98";
	string tmp = "9012345678";
	while(s.size() < n) s += tmp;
	cout<<s.substr(0,n)<<'\n';
	return;
}

int main(){
	int t;
	cin>>t;
	while(t--)solve();
}

