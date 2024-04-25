#include <bits/stdc++.h>
using namespace std;

#define ll long long
string s;
char k;
ll toll(string s){
	ll returns = 0;
	ll tens = 1;
	for(int i = s.size()-1;i>=0;i--){
		returns += (ll)(s[i]-'0')*tens;
		tens *= 10;
	}
	return returns;
}
ll f(string s){
	ll returns = 0;
	if(s[0]==k){
		returns += 1+toll(s.substr(1));
	}
	else if(s[0]>k){
		returns += pow(10,s.size()-1);
	}
	for(int i = 1;i<s.size()-1;i++){
		returns += toll(s.substr(0,i))*pow(10,s.size()-1-i);
		if(s[i]>k)returns += pow(10,s.size()-1-i);
		else if(s[i] == k)returns += 1+toll(s.substr(i+1));
	}
	returns += toll(s.substr(0,s.size()-1));
	if(s[s.size()-1]>=k)returns++;
	return returns;
}
ll z(string s){
	ll returns = 0;
	for(int i = 1;i<s.size()-1;i++){
		returns += (toll(s.substr(0,i))-1)*pow(10,s.size()-1-i);
		if(s[i]!= '0')returns += pow(10,s.size()-1-i);
		else returns += (1+toll(s.substr(i+1)));
	}
	returns += (toll(s.substr(0,s.size()-1)));
	return returns;
}
void solve(){
	if(k != '0')cout<<f(s)<<'\n';
	else cout<<z(s)<<'\n';
}
int main(){
	while(cin>>s>>k){
		solve();
	}
}
