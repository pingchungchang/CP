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
	string s;
	cin>>n>>s;
	int cnt = 0;
	for(auto &i:s)if(i == '1')cnt++;
	if(cnt&1){
		cout<<"-1\n";
		return;
	}
	n*=2;
	vector<int> dif;
	for(int i = 0;i<n;i+=2){
		if(s[i] != s[i+1])dif.push_back(i);
	}
	vector<int> re;
	for(int i = 0;i<dif.size();i++){
		if(i&1){
			if(s[dif[i]] == '1')re.push_back(dif[i]);
			else re.push_back(dif[i]+1);
		}
		else{
			if(s[dif[i]] == '0')re.push_back(dif[i]);
			else re.push_back(dif[i]+1);
		}
	}
	cout<<re.size()<<' ';
	for(auto &i:re)cout<<i+1<<' ';cout<<'\n';
	for(int i = 0;i<n;i+=2)cout<<i+1<<' ';cout<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

