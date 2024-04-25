#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin>>s;
	for(int i =0;i<s.size();i++){
		if(s[i]>='A'&&s[i]<='Z'){
			s[i] = (char)(s[i]-'A'+'a');
		}
	}
	s[0] = (char)(s[0]-'a'+'A');
	cout<<s<<'\n';
	for(int i =1;i<s.size();i++){
		s[i-1] = (char)(s[i-1]-'A'+'a');
		s[i] = (char(s[i]-'a'+'A'));
		cout<<s<<'\n';
	}
	return 0;
}
