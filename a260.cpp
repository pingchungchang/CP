#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	for(int i =0;i<s.size();i++){
		if(s[i]>='a'&&s[i]<='z')cout<<(char)('a'+(s[i]-'a'+13)%26);
		else if(s[i]>='A'&&s[i]<='Z')cout<<(char)('A'+(s[i]-'A'+13)%26);
		else cout<<s[i];
	}
}
