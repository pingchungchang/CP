#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	vector<vector<int>> v(26);
	for(int i = 0;i<s.size();i++){
		char c= s[i];
		if(c>='a'){
			c = 'A'+(c-'a');
		}
		v[c-'A'].push_back(i);
	}
	char c;
	cin>>c;
	if(c>='a')c = 'A'+(c-'a');
	int pos = c-'A';
	for(int i = 1;i<v[pos].size();i++)cout<<v[pos][i]-v[pos][i-1]<<' ';
}
