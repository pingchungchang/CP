#include <bits/stdc++.h>
using namespace std;

string s;
int main(){
	int k;
	cin>>k;
	cin>>s;
	string ans;
	s += '@';
	pair<char,int> now = make_pair(s[0],0);
	for(int i =0;i<=k;i++){
		if(s[i] == now.first)now.second++;
		else{
			ans += to_string(now.second);
			ans += now.first;
			now.first = s[i];
			now.second = 1;
		}
	}
	if(ans.size()<s.size())cout<<ans;
	else cout<<s.substr(0,k);
}
