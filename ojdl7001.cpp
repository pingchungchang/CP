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
	string a,b;
	cin>>a>>b;
	reverse(_all(a));
	reverse(_all(b));
	while(a.size()<b.size())a+='0';
	while(b.size()<a.size())b+='0';
	string ans;
	int add = 0;
	for(int i = 0;i<a.size();i++){
		int total = a[i]-'0'+b[i]-'0'+add;
		ans+= '0'+total%10;
		add = total/10;
	}
	if(add)ans += '0'+add;
	reverse(_all(ans));
	cout<<ans;
}

