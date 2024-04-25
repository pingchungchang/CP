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
	int n,m;
	cin>>n>>m;
	string s(m+1,'B');
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(s[min(k,m+1-k)] == 'A')s[max(k,m+1-k)] = 'A';
		else s[min(k,m+1-k)] = 'A';
	}
	cout<<s.substr(1,s.size()-1)<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

