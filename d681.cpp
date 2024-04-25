#include <bits/stdc++.h>
using namespace std;

void solve(string &s){
	string st;
	for(int i = 0;i<s.size();i++){
		if(s.substr(i,3) == "and"){
			st += "&&";
		}
		else if(s.substr(i,2) == "or"){
			st += "||";
		}
		else if(s[i] == '0'||s[i] == '1'){
			st += s[i];
		}
		else{
			continue;
		}
	}
	string k = st.substr(0,5);
	for(int i = 5;i<st.size();i+=7){
		if(st[i] == '&'){
			for(int j = i+2;j<=i+6;j++){
				if(k[j-i-2] == '1'&&st[j] == '1'){
					k[j-i-2] = '1';
				}
				else k[j-i-2] = '0';
			}
		}
		else{
			for(int j = i+2;j<=i+6;j++){
				if(k[j-i-2] == '0'&&st[j] == '0'){
					k[j-i-2] = '0';
				}
				else k[j-i-2] = '1';
			}
		}
	}
	cout<<st<<" = "<<k<<'\n';
}
int main(){
	string in;
	while(getline(cin,in)){
		solve(in);
	}
}
