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
	ll k;
	cin>>k;
	string s;
	cin>>s;
	int p[s.size()] = {};
	if(s.size()>1&&s[0] == s[1])p[1] = 1;
	for(int i = 2;i<s.size();i++){
		int pt = p[i-1];
		while(pt>0&&s[pt] != s[i]){
			pt = p[pt-1];
		}
		if(pt<=0&&s[0] == s[i])p[i] = 1;
		else if(pt<=0)p[i] = 0;
		else p[i] = pt+1;
	}
	ll ans = 0;
//	for(auto &i:p)cout<<i<<' ';cout<<endl;
	for(int i = 0;i<s.size();i++){
		ll d = i+1-p[i];
		ll len = (i+1)/d*d;
		if(d*k<=i+1)ans = max(ans,len/k);
	}
	cout<<ans;
//	for(auto &i:p)cout<<i<<' ';
}

