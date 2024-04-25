#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int col[n] = {};
	int p = 0;
	for(auto &i:s)if(i == ')')p++;else p--;
	if(p){
		cout<<"-1\n";
		return;
	}
	col[0] = 1;
	for(int i = 0;i<n;i++){
		if(s[i] == s[0])p++,col[i] = 1;
		else if(p>0)p--,col[i] = 1;
	}
	for(int i = n-1;p>0&&i >=0;i--){
		if(s[i] == s[0]){
			p--;
			col[i] = 0;
		}
	}
	for(auto &i:col)if(!i)i = 2;
	int r = 0;
	for(auto &i:col)r|=i;
	if(r == 1)cout<<1<<'\n';
	else cout<<2<<'\n';
	for(auto &i:col)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
