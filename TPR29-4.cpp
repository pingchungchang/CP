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
	string s;
	cin>>s;
	for(int i = 0;i<s.size();i++){
		if(s[i] == '.'){
			s.erase(s.begin()+i);
			break;
		}
	}
	while(!s.empty()&&*s.begin() == '0')s.erase(s.begin());
	if(s.empty())s = "0";
	cout<<s;
}

