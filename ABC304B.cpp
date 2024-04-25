#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	int n = s.size();
	for(int i = 0;i<n-3;i++)s[n-1-i] = '0';
	cout<<s;
}
