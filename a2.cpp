#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	string s;
	cin>>s;
	int p = 0;
	for(;p<s.size()&&s[p] != '.';p++);
	ll k = stoll(s.substr(0,p));
	ll m = stoll(s.substr(p+1,s.size()-p-1));
	if(m == 0){
		cout<<k<<"/"<<1<<'\n';
		return 0;
	}
	ll x = 1;
	for(int i = 0;i<s.size()-p-1;i++)x *=10;
	x--;
	ll G = __gcd(x,m);
	x /=G;
	m /= G;
	cout<<m+x*k<<'/'<<x;
}
