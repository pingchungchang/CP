#include <bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	cin>>a>>b;
	int dif = 30;
	for(int i = 0;i<a.size();i++){
		int a1 = a[i]-'a';
		int b1 = b[i]-'a';
		if(dif == 30){
			dif = (a1-b1+26)%26;
			continue;
		}
		if(dif != (26+a1-b1)%26){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
