#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	string k;
	cin>>s>>k;
	for(int i =0;i<s.size();i++){
		cout<<(char)('a'+(26+s[i]-k[i%k.size()])%26);
	}
}
