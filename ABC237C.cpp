#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	int p1=0,p2=0;
	for(int i = s.size()-1;i>=0;i--){
		if(s[i] != 'a'){
			break;
		}
		p1++;
	}
	for(int i = 0;i<s.size();i++){
		if(s[i] != 'a')break;
		p2++;
	}
	if(p2>p1){
		cout<<"No";
		return 0;
	}
	s = s.substr(0,s.size()-(p1-p2));
	for(int i = 0;i<s.size()/2;i++){
		if(s[i] != s[s.size()-1-i]){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
