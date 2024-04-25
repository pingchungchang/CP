#include <bits/stdc++.h>
using namespace std;


int main(){
	string a,b;
	cin>>a>>b;
	for(int i = 0;i<a.size();i++){
		if(a[i]>='A'&&a[i]<='Z'){
			a[i] = 'a'+(a[i]-'A');
		}
	}
	for(int i = 0;i<b.size();i++){
		if(b[i]>='A'&&b[i]<='Z'){
			b[i] = 'a'+(b[i]-'A');
		}
	}
	if(a== b)cout<<0;
	else if(a>b)cout<<1;
	else cout<<-1;
}
