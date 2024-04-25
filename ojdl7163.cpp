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

set<int> no;

ll f(ll now){
	ll cnt = 0;
	ll dp[2][10];
	memset(dp,0LL,sizeof(dp));
	short now = 1;
	string s = to_string(now);
	for(int i = )
	for(int asd = 1;asd<s.size();i++){
		now ^=1;
		for(auto &i:dp[now])i = 0;
		
	}
}
int main(){
	io
	int n;
	cin>>n;
	for(int i = n+1;i<10;i++)no.insert(i);
	int k;
	cin>>k;
	for(int i = 0;i<k;i++){
		int tmp;
		cin>>tmp;
		no.insert(tmp);
	}
	ll s,e;
	cin>>s>>e;
	cout<<f(e)-f(s);
}

