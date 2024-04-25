#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	int x = 0;
	for(int i = 0;i<t;i++){
		string s;
		cin>>s;
		if(s[1] == '+')x++;
		else x--;
	}
	cout<<x;
}
