#include <bits/stdc++.h>
using namespace std;

bool isprime(int n){
	if(n==1)return false;
	for(int i = 2;i<=sqrt(n);i++){
		if(n%i == 0)return false;
	}
	return true;
}
string cycled(string s){
	return s[s.size()-1]+s.substr(0,s.size()-1);
}
int main(){
	set<int> st;
	string s;
	cin>>s;
	while(st.find(stoi(s)) == st.end()){
		st.insert(stoi(s));	
		if(isprime(stoi(s)) == true)cout<<"Check "<<stoi(s)<<": Yes\n";
		else{
			cout<<"Check "<<stoi(s)<<": No\n";
			return 0;
		}
		s = cycled(s);
	}
}
