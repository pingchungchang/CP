#include <iostream>
using namespace std;

int main(){
	string s;
	while(cin>>s){
		for(int i =0;i<=s.size()/2;i++){
			if(s[i]!= s[s.size()-1-i]){
				cout<<"No\n";
				break;
			}
			if(i == s.size()/2)cout<<"Yes\n";
		}
	}
}
