#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

bool isp(int k){
	if(k == 1)return false;
	for(int i = 2;i*i<=k;i++){
		if(k%i==0)return false;
	}
	return true;
}

void solve(){
	string s;
	cin>>s;
	map<char,int> mp;
	for(auto &i:s)mp[i]++;
	bool flag = false;
	for(auto &i:mp){
		if(isp(i.sc))cout<<i.fs,flag = true;
	}
	if(!flag)cout<<"empty\n";
	else cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	for(int i = 1;i<=t;i++){
		cout<<"Case "<<i<<": ";
		solve();
	}
}
