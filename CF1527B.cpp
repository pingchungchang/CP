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
	int cnt = 0;
	int cc = 0;
	for(auto &i:s)cc += i == '0';
	for(int i = 0;i<n/2;i++){
		if(s[i] != s[n-1-i])cnt++,s[i] = s[n-1-i] = '1';
	}
	if(cnt == 0){
		for(int i = 0;i<n;i++)if(s[i] == '0')cnt++;
		if(cnt == 0)cout<<"DRAW\n";
		else if(cnt == 1){
			cout<<"BOB\n";
		}
		else if(cnt&1)cout<<"ALICE\n";
		else cout<<"BOB\n";
	}
	else{
		if(cc == 2&&cnt == 1)cout<<"DRAW\n";
		else cout<<"ALICE\n";
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
