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
int main(){
	io
	int n;
	cin>>n;
	map<char,int> mp;
	for(int i = 0;i<10;i++)mp[i] = '0'+i;
	for(int i = 0;i<6;i++)mp[i+10] = 'A'+i;
	string ans;
	ans += mp[n%16];
	n /=16;
	ans = string(1,mp[n])+ans;
	cout<<ans;
}

