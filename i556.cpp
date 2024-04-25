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
	string s;
	cin>>s;
	int tmp = 0;
	for(int i = 0;i<min((int)s.size(),2);i++){
		tmp += (i == 0?1:10)*(s[s.size()-i-1]-'0');
	}
	if(tmp%4 == 0)cout<<"L";
	else cout<<"C";
	return 0;
}

