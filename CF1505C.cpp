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
	for(int i = 2;i<s.size();i++){
		int cnt = s[i-1]-'A'+s[i-2]-'A';
		cnt %= 26;
		if(s[i] != 'A'+cnt){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}

