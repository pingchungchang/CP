#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	string s;
	cin>>s;
	while(s.size()>1){
		int total = 0;
		for(auto i:s)total += i-'0';
		s = to_string(total);
	}
	cout<<s;
}

