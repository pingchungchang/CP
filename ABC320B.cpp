#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

bool check(string s){
	for(int i = 0;i<s.size();i++){
		if(s[i] != s[s.size()-1-i])return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	int ans = 1;
	for(int i = 0;i<s.size();i++){
		for(int j = i;j<s.size();j++){
			if(check(s.substr(i,j-i+1)))ans = max(ans,j-i+1);
		}
	}
	cout<<ans;
}
