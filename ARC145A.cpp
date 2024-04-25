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
	io
	int n;
	string s;
	cin>>n>>s;
	if(n == 1){
		cout<<"Yes";
		return 0;
	}
	if((s[0] == 'B'||s.back() == 'A')&&s.size()>2)cout<<"Yes";
	else if(s[0] == s[1]&&s.size() == 2)cout<<"Yes";
	else cout<<"No";
}

