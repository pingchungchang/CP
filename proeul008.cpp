#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	string s;
	string in;
	while(cin>>in)s += in;
	ll ans = 0;
	for(int i = 0;i<s.size()-12;i++){
		ll tans = 1;
		for(int j = 0;j<13;j++){
			tans = tans*(s[i+j]-'0');
		}
		ans = max(ans,tans);
	}
	cout<<ans;
}
