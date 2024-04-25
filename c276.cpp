#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	map<char,int> m;
	for(int i =0;i<s.size();i++){
		m[s[i]] = i;
	}
	int t;
	cin>>t;
	for(int asd=0;asd<t;asd++){
		string g;
		cin>>g;
		int a = 0;
		int b =0;
		for(int i = 0;i<g.size();i++){
			if(m.count(g[i])!= 0){
				if(m[g[i]] == i)a++;
				else b++;
			}
		}
		cout<<a<<"A"<<b<<"B\n";
	}
}
