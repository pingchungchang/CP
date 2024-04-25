#include <bits/stdc++.h>
using namespace std;


int n;
void solve(){
	string s;
	cin>>s;
	int n= s.size();
	if(n == 1){
		s = '0'+s;
		n++;
	}
	int a=0,b=0;
	string sa,sb;
	for(int i = 0;i<n;i+=2){
		sa+=s[i];
	}
	for(int i = 1;i<n;i+=2)sb += s[i];
	a = stoi(sa);
	b = stoi(sb);
	cout<<(a+1)*(b+1)-2<<'\n';
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
