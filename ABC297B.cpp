#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int a = -1,b = -1;
	for(int i = 0;i<s.size();i++){
		if(s[i] == 'B'){
			if(a == -1)a = i;
			else b = i;
		}
	}
	if(!((a+b)&1)){
		cout<<"No";
		return 0;
	}
	a = b = -1;
	for(int i = 0;i<s.size();i++){
		if(s[i] == 'R'){
			if(a == -1)a = i;
			else b = i;
		}
	}
	for(int i = 0;i<s.size();i++){
		if(s[i] == 'K'){
			if(a<i&&i<b){
				cout<<"Yes";
				return 0;
			}
		}
	}
	cout<<"No";
	return 0;
}
