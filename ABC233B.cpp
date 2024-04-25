#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	string s;
	cin>>a>>b>>s;
	reverse(s.begin()+a-1,s.begin()+b);
	cout<<s;
}
