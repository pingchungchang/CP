#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	bool a = false,b = true;
	for(auto &i:s){
		if(i == 'x')b = false;
		if(i == 'o')a = true;
	}
	if(a&&b)cout<<"Yes";
	else cout<<"No";
}
