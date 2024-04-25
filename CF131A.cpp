#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	string s;
	cin>>s;
	int pref[s.size()];
	for(int i = 0;i<s.size();i++){
		if(s[i]>='A'&&s[i]<='Z')pref[i] = 1;
		if(i != 0)pref[i] += pref[i-1];
	}
	int n = s.size();
	if(pref[n-1]-pref[0] == n-1){
		for(int i = 0;i<n;i++){
			if(s[i]>='A'&&s[i]<='Z')cout<<(char)('a'+(s[i]-'A'));
			else cout<<(char)('A'+(s[i]-'a'));
		}
	}
	else cout<<s;
}

