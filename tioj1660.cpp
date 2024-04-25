#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

string s;
void solve(){
	for(int i = 0;i<s.size();i++){
		if(s[i] != s[s.size()-1-i]){
			cout<<"not palindrome\n";
			return;
		}
	}
	cout<<"palindrome\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>s)solve();
}
