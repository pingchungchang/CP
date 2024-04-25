#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	string s1,s2;
	int p1,p2;
	cin>>s1>>p1>>s2>>p2;
	if(s1.size()+p1 != s2.size()+p2){
		cout<<(s1.size()+p1>s2.size()+p2?">":"<")<<'\n';
		return;
	}
	while(s1.size()>s2.size())s2 += '0';
	while(s1.size()<s2.size())s1 += '0';
	cout<<(s1 == s2?"=":s1<s2?"<":">")<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
