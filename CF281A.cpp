#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	if(s[0]>='a'&&s[0]<='z'){
		s[0] = 'A'+(s[0]-'a');
	}
	cout<<s;
}
