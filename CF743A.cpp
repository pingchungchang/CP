#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a,b;
	cin>>n>>a>>b;
	string s;
	cin>>s;
	if(s[a-1]==s[b-1]){
		cout<<0<<'\n';
		return 0;
	}
	cout<<1<<'\n';
}
