#include <bits/stdc++.h>
using namespace std;

int main(){
	string vow = "aeiouAEUOIYy";
	set<char> st;
	for(int i = 0;i<vow.size();i++)st.insert(vow[i]);
	string a;
	string b;
	cin>>a;
	for(int i = 0;i<a.size();i++){
		if(st.find(a[i]) == st.end()){
			if(a[i]>='A'&&a[i]<='Z'){
				b+= 'a'+(a[i]-'A');
			}
			else b+= a[i];
		}
	}
	for(int i = 0;i<b.size();i++){
		cout<<'.'<<b[i];
	}
	return 0;
}
