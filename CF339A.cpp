#include <bits/stdc++.h>
using namespace std;

int main(){
	stringstream ss;
	ss.clear();
	string s;
	getline(cin,s);
	for(int i = 0;i<s.size();i++){
		if(s[i] == '+')s[i] = ' ';
	}
	ss.str(s);
	vector<int> v;
	int k;
	while(ss>>k){
		v.push_back(k);
	}
	sort(v.begin(),v.end());
	for(int i = 0;i<v.size();i++){
		if(i != 0)cout<<'+';
		cout<<v[i];
	}
	return 0;
}
