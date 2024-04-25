#include <bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	cin>>a>>b;
	if(b.size()>a.size())b = b.substr(b.size()-a.size(),a.size());
	else a = a.substr(0,b.size());
	while(a.size()>0&&b.size()>0&&a!=b){
		a = a.substr(0,a.size()-1);
		b = b.substr(1,b.size()-1);
	}
	cout<<b.size();
}
