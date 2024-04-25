#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int cnt = 0;
	for(int i = 1;i<n;i+=2){
		if(s[i] == s[i-1]){
			cnt++;
			s[i] = (s[i] == 'b'?'a':'b');
		}
	}
	cout<<cnt<<'\n'<<s<<'\n';
	return 0;
}
