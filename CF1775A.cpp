#include <bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin>>s;
	int ca = 0,cb = 0;
	for(auto &i:s)if(i == 'a')ca++;else cb++;
	if(ca == 0||cb == 0||(s[0] == s.back())){
		cout<<s[0]<<' '<<s.substr(1,s.size()-2)<<' '<<s[0]<<'\n';
		return;
	}
	else if(ca == 1){
		cout<<s[0]<<' '<<s.substr(1,s.size()-2)<<' '<<s.back()<<'\n';
	}
	else{
		int p =1;
		while(s[p] != 'a')p++;
		cout<<s.substr(0,p)<<' '<<s[p]<<' '<<s.substr(p+1,s.size()-p-1)<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
