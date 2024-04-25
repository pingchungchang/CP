#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s;
	cin>>n>>s;
	int cnt = 0;
	for(int i = 0;i<n;i++){
		if(s[i] == '|')cnt++;
		if(s[i] == '*'){
			if(cnt != 1)cout<<"out";
			else cout<<"in";
		}
	}
}
