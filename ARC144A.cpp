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
	int n;
	cin>>n;
	int m = 2*n;
	string s;
	if(n%4 != 0) s = string(1,'0'+n%4);
	s += string(n/4,'4');
	cout<<m<<'\n'<<s;
}
