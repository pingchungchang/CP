#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	while(s.size()<(int)1e5){
		s += "oxx";
	}
	string t;
	cin>>t;
	for(int i = 0;i<s.size()-t.size();i++){
		if(t == s.substr(i,t.size())){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}
