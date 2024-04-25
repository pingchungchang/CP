#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	if(n>=42)n++;
	string s = to_string(n);
	while(s.size()<3)s = '0'+s;
	cout<<"AGC"<<s;
}
